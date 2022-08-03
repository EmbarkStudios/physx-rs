#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/Decl.h"
#include "clang/AST/PrettyPrinter.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Driver/Options.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <tuple>
#include <vector>

#define FMT_HEADER_ONLY 1
#define FMT_STRING_ALIAS 1
#include "fmt/fmt/format.h"

// Only types within this directory will be included
const char* const REQUIRED_PATH_COMPONENT = "PhysX";

using namespace std;
using namespace clang;
using namespace clang::driver;
using namespace clang::tooling;
using namespace clang::ast_matchers;
using namespace llvm;

static cl::OptionCategory PxBindCategory("PxBind options");
const opt::OptTable& Options(getDriverOptTable());
static cl::opt<std::string> OutputFilename(
    "o",
    cl::desc(Options.getOptionHelpText((options::OPT_o))));

// https://stackoverflow.com/questions/5288396/c-ostream-out-manipulation/5289170#5289170
template<typename Range, typename Value = typename Range::value_type>
std::string join(Range const& elements, const char* const delimiter) {
    std::ostringstream os;
    auto b = begin(elements), e = end(elements);

    if (b != e) {
        std::copy(b, prev(e), std::ostream_iterator<Value>(os, delimiter));
        b = prev(e);
    }
    if (b != e) {
        os << *b;
    }

    return os.str();
}

// https://stackoverflow.com/a/14678800
std::string replaceString(
    std::string subject,
    const std::string& search,
    const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

string stripPrefix(string s, const string& prefix) {
    if (s.rfind(prefix) == 0) {
        s = s.substr(prefix.length());
    }

    return s;
}

// https://stackoverflow.com/a/46943631
vector<string> split(string str, string token) {
    vector<string> result;
    while (str.size()) {
        int index = str.find(token);
        if (index != string::npos) {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)
                result.push_back(str);
        } else {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

string remapRustIdent(const string& s) {
    if (s == "box")
        return "_box";
    if (s == "type")
        return "_type";
    if (s == "ref")
        return "_ref";
    return s;
}

struct CppResultCalc {
    virtual string toString(
        const string& returnName,
        const string& returnType,
        const vector<string>& args) const = 0;
};

struct CppFnCallResult : CppResultCalc {
    explicit CppFnCallResult(const string& fnName)
      : fnName(fnName) {}

    string fnName;

    string toString(
        const string& returnName,
        const string& returnType,
        const vector<string>& args) const override {
        if (returnType != "void") {
            return fmt::format(
                "{} {} = {}({});",
                returnType,
                returnName,
                fnName,
                join(args, ", "));
        } else {
            return fmt::format("{}({});", fnName, join(args, ", "));
        }
    }
};

struct CppCtorResult : CppResultCalc {
    explicit CppCtorResult(const string& className)
      : className(className) {}

    string className;

    string toString(
        const string& returnName,
        const string& returnType,
        const vector<string>& args) const override {
        if (args.empty()) {
            return fmt::format("{} {};", className, returnName);
        } else {
            return fmt::format(
                "{} {}({});", className, returnName, join(args, ", "));
        }
    }
};

struct CppNewResult : CppResultCalc {
    explicit CppNewResult(const string& className)
      : className(className) {}

    string className;

    string toString(
        const string& returnName,
        const string& returnType,
        const vector<string>& args) const override {
        return fmt::format(
            "auto {} = new {}({});", returnName, className, join(args, ", "));
    }
};

enum class Mutability { Mutable, Immutable };

Mutability mutabilityFromConstness(bool c) {
    return c ? Mutability::Immutable : Mutability::Mutable;
}

string getRustPtr(Mutability m) {
    return Mutability::Immutable == m ? "*const" : "*mut";
}

string getCPtrConstness(Mutability m) {
    return Mutability::Immutable == m ? " const" : "";
}

struct CppType {
    CppType() {}

    explicit CppType(
        const string& cppType,
        const string& cType,
        const string& rustType,
        const string& c2cppCode = "",
        const string& cpp2cCode = "")
      : cppType(cppType)
      , cType(cType)
      , rustType(rustType)
      , c2cppCode(c2cppCode)
      , cpp2cCode(cpp2cCode) {}

    CppType ptr(Mutability mutability) const {
        CppType res;
        res.cType = cType + getCPtrConstness(mutability) + "*";
        res.cppType = cppType + getCPtrConstness(mutability) + "*";
        if (rustType == "()") {
            res.rustType = getRustPtr(mutability) + " std::ffi::c_void";
        } else {
            res.rustType = getRustPtr(mutability) + " " + rustType;
        }
        if (cType != cppType) {
            res.c2cppCode = "{cppType} {cppName} = "
                            "reinterpret_cast<{cppType}>({cName});\n";
            res.cpp2cCode = "{cType} {cName} = "
                            "reinterpret_cast<{cType}>({cppName});\n";
        }
        return res;
    }

    CppType ref(Mutability mutability) const {
        CppType res;
        res.cType = cType + getCPtrConstness(mutability) + "*";
        res.cppType = cppType + getCPtrConstness(mutability) + "&";
        if (rustType == "()") {
            res.rustType = string(getRustPtr(mutability)) + " std::ffi::c_void";
        } else {
            res.rustType = string(getRustPtr(mutability)) + " " + rustType;
        }
        if (cType != cppType) {
            res.c2cppCode = "{cppType} {cppName} = "
                            "reinterpret_cast<{cppType}>(*{cName});\n";
            res.cpp2cCode = "{cType} {cName} = "
                            "reinterpret_cast<{cType}>(&{cppName});\n";
        } else {
            res.c2cppCode = "{cppType} {cppName} = *{cName};\n";
            res.cpp2cCode = "{cType} {cName} = &{cppName};\n";
        }
        return res;
    }

    const string& getCType() const { return cType; }
    const string& getCppType() const { return cppType; }
    const string& getRustType() const { return rustType; }

  protected:
    string cType;
    string cppType;
    string rustType;
    string c2cppCode;
    string cpp2cCode;
};

struct CppFnArg : CppType {
    CppFnArg() {}
    CppFnArg(const CppType& base, const string& cppName)
      : CppType(base)
      , cppName(cppName) {}

    string cppName;
    string cName() const {
        if (c2cppCode.empty()) {
            return cppName;
        } else {
            return cppName + "_pod";
        }
    }

    string getC2CppCode() const {
        if (c2cppCode.empty()) {
            return "";
        } else {
            string res = c2cppCode;
            res = replaceString(res, "{cppName}", cppName);
            res = replaceString(res, "{cppType}", cppType);
            res = replaceString(res, "{cName}", cppName + "_pod");
            res = replaceString(res, "{cType}", cType);
            return res;
        }
    }

    string getCpp2CCode() const {
        if (cpp2cCode.empty()) {
            return "";
        } else {
            string res = cpp2cCode;
            res = replaceString(res, "{cppName}", cppName);
            res = replaceString(res, "{cppType}", cppType);
            res = replaceString(res, "{cName}", cppName + "_pod");
            res = replaceString(res, "{cType}", cType);
            return res;
        }
    }
};

struct CppFn {
    string name;
    string bodyPreamble;
    bool hasSelf = false;
    vector<CppFnArg> args;
    shared_ptr<CppResultCalc> valueExpr;
    CppType returnType;

    string genCppDef() const {
        string result;
        result += fmt::format("{} {}(", returnType.getCType(), name);

        int i = 0;
        for (auto& arg : args) {
            if (i > 0) {
                result += ", ";
            }
            result += fmt::format("{} {}", arg.getCType(), arg.cName());
            ++i;
        }

        result += ") {\n";

        for (const CppFnArg& arg : this->args) {
            result += arg.getC2CppCode();
        }

        result += bodyPreamble;

        if (this->valueExpr) {
            vector<string> argNames;
            {
                auto arg = this->args.begin();
                if (this->hasSelf) {
                    // Skip self when calling the function
                    ++arg;
                }

                for (; arg != this->args.end(); ++arg) {
                    argNames.push_back(arg->cppName);
                }
            }

            CppFnArg returnValue(this->returnType, "returnValue");

            // Calculate the result
            result +=
                this->valueExpr->toString(
                    returnValue.cppName, returnValue.getCppType(), argNames) +
                "\n";

            // Convert the result to a C POD representation
            result += returnValue.getCpp2CCode();

            if (this->returnType.getCType() != "void") {
                result += fmt::format("return {};\n", returnValue.cName());
            }
        }
        result += "}\n";

        return result;
    }

    string genRustDecl() const {
        string result;
        result += fmt::format("pub fn {}(", name);

        for (auto& arg : args) {
            result += fmt::format(
                "{}: {}, ", remapRustIdent(arg.cppName), arg.getRustType());
        }

        result += fmt::format(") -> {};\n", returnType.getRustType());

        return result;
    }
};

struct ConvEnum {
    struct Enumerator {
        string name;
        string value;
    };

    string name;
    vector<string> scope;
    string intType;
    vector<Enumerator> enumerators;

    string getQualifiedRustType() const {
        string result;
        for (auto& n : scope) {
            if (!result.empty()) {
                result += "::";
            }
            result += n;
        }

        if (!result.empty()) {
            result += "::";
        }
        result += name;
        return result;
    }

    string genRustDef() const {
        string res = "";
        for (auto& n : scope) {
            res += "pub mod " + n + "{\n";
        }

        res += fmt::format("pub type {} = {};\n", name, intType);

        for (const auto& e : enumerators) {
            res += fmt::format(
                "pub const {}: {} = {}u64 as {};\n",
                e.name,
                name,
                e.value,
                intType);
        }

        for (auto& n : scope) {
            res += "}\n";
        }

        return res;
    }
};

struct PodRecordField {
    string name;
    string decl;
    string cppType;
    string rustType;
    bool accessible = false;
    bool isReference = false;
};

struct PodRecord {
    string recordType;
    string typeName;
    string cppTypeName;
    string rustTypeName;

    vector<PodRecordField> fields;
    bool hasVtable = false;
    bool hasDefinition = false;

    // Decide whether we should use "strugen" to calculate the exact layout of
    // this C++ struct.
    //
    // Ideally we would do this for all types, but we must be able to name them,
    // which is not feasible for anonymous types, or types which the generator
    // doesn't support yet (their cppTypeName will be empty).
    //
    // Note that empty types are only refered to by pointers and references in
    // PhysX, so we can generate dummy contents for them.
    bool shouldCalculateLayout() const {
        return hasDefinition && !cppTypeName.empty() &&
               "struct" == recordType && !fields.empty();
    }

    void fixEmptyStruct() {
        if (!hasVtable && fields.empty()) {
            PodRecordField f;
            f.name = "pxbind_dummy";
            f.decl = "char pxbind_dummy;";
            f.cppType = "char";
            f.rustType = "u8";
            fields.emplace_back(f);
        }
    }

    string genLayoutCalcCode() const {
        if (shouldCalculateLayout()) {
            string res = "";

            res += fmt::format(
                "struct {}: public {} {{\n    static void "
                "dumpLayout(PodStructGen& "
                "structGen) {{\n",
                typeName,
                cppTypeName);

            res += fmt::format(
                "        structGen.beginStruct(\"{}\", \"{}\");\n",
                typeName,
                rustTypeName);

            for (const auto& field : fields) {
                if (field.accessible && !field.isReference) {
                    res += "        structGen.addField(";
                    res += "\"" + field.decl + "\", ";
                    res += "\"" + remapRustIdent(field.name) + "\", ";
                    res += "\"" + field.rustType + "\",";
                    res += fmt::format("sizeof({})", field.cppType) + ", ";
                    res +=
                        fmt::format(
                            "unsafe_offsetof({}, {})", typeName, field.name) +
                        ");\n";
                }
            }

            res +=
                "        structGen.endStruct(sizeof(" + cppTypeName + "));\n";
            res += "    }\n";

            res += fmt::format("}};\n{}::dumpLayout(structGen);\n", typeName);
            return res;
        } else {
            string code = "struct " + typeName;
            if (hasDefinition) {
                code += " {\\n";

                if (hasVtable) {
                    code += "    void* vtable_;\\n";
                }

                for (const auto& field : fields) {
                    code += "    " + field.decl + ";\\n";
                }

                code += "};\\n";
            } else {
                code += ";\\n";
            }

            return "structGen.passThroughC(\"" + code + "\");";
        }
    }

    string genRustDecl() const {
        if (shouldCalculateLayout()) {
            return "";
        }

        string res;
        res += "#[derive(Clone, Copy)]\n";
        res += "#[repr(C)]\n";
        res += "pub " + recordType + " " + rustTypeName;

        res += "{\n";

        if (hasDefinition) {
            if (hasVtable) {
                res += "    vtable_: *const std::ffi::c_void,\n";
            }

            for (const auto& field : fields) {
                res += fmt::format(
                    "    pub {}: {},\n",
                    remapRustIdent(field.name),
                    field.rustType);
            }
        } else {
            res += "    pxbind_dummy: u8\n";
        }

        res += "}\n";

        return res;
    }

    string genStaticAssertCode() const {
        if (hasDefinition && !cppTypeName.empty()) {
            return fmt::format(
                "static_assert(sizeof({0}) == sizeof({1}), \"POD "
                "wrapper for {0} has incorrect size.\");\n",
                cppTypeName,
                typeName);
        } else {
            return "";
        }
    }
};

struct GeneratorContext {
    vector<CppFn> fns;
    vector<PodRecord> recs;
    map<string, string> podTypeRemap;
    map<string, int> funcList;
    map<string, string> remappedCToRust;
    map<string, ConvEnum> enums;
};

string remapBuiltinTypeToCpp(BuiltinType::Kind k) {
    switch (k) {
        case BuiltinType::Void:
            return "void";

        case BuiltinType::Bool:
            return "bool";

        case BuiltinType::Float:
            return "float";
        case BuiltinType::Double:
            return "double";

        case BuiltinType::Char_S:
        case BuiltinType::SChar:
            return "char";
        case BuiltinType::Char_U:
        case BuiltinType::UChar:
            return "unsigned char";

        case BuiltinType::Short:
            return "int16_t";
        case BuiltinType::UShort:
            return "uint16_t";

        case BuiltinType::Int:
            return "int32_t";
        case BuiltinType::UInt:
            return "uint32_t";

        case BuiltinType::Long:
            return "int64_t";
        case BuiltinType::ULong:
        case BuiltinType::ULongLong:
            return "uint64_t";
        default:
            printf("Unhanded builtin cpp type. BuiltinType::Kind = %u\n", unsigned(k));
            abort();
    }
}

string remapBuiltinTypeToRust(BuiltinType::Kind k) {
    switch (k) {
        case BuiltinType::Void:
            return "()";

        case BuiltinType::Bool:
            return "bool";

        case BuiltinType::Float:
            return "f32";
        case BuiltinType::Double:
            return "f64";

        case BuiltinType::Char_S:
        case BuiltinType::SChar:
            return "i8";
        case BuiltinType::UChar:
        case BuiltinType::Char_U:
            return "u8";

        case BuiltinType::Short:
            return "i16";
        case BuiltinType::UShort:
            return "u16";

        case BuiltinType::Int:
            return "i32";
        case BuiltinType::UInt:
            return "u32";

        case BuiltinType::Long:
            return "isize";
        case BuiltinType::ULong:
        case BuiltinType::ULongLong:
            return "usize";
        default:
            printf("Unhanded builtin cpp type. BuiltinType::Kind = %u\n", unsigned(k));
            abort();
    }
}

class ClassMatchHandler : public MatchFinder::MatchCallback {
    ASTContext* astContext;
    shared_ptr<GeneratorContext> gc;

  public:
    ClassMatchHandler(shared_ptr<GeneratorContext> gc)
      : gc(gc) {}

    string remapSingleField(
        const QualType& qt,
        const string& fieldName,
        const PrintingPolicy& policy) {
        if (auto builtin = qt->getAs<BuiltinType>()) {
            const string desugared = remapBuiltinTypeToCpp(builtin->getKind());
            return desugared + "{0} " + fieldName + "{1}";
        } else if (qt->isFunctionPointerType()) {
            return "void*{0} " + fieldName + "{1}";
        } else if (qt->isReferenceType()) {
            string child =
                remapSingleField(qt.getNonReferenceType(), fieldName, policy);
            return fmt::format(child, "*{0}", "{1}");
        } else if (qt->isPointerType()) {
            string child =
                remapSingleField(qt->getPointeeType(), fieldName, policy);
            return fmt::format(child, "*{0}", "{1}");
        } else if (qt->isEnumeralType()) {
            const EnumType* enumType = qt->getAs<EnumType>();
            remapEnumToRust(*enumType->getDecl(), policy);

            string fieldType =
                enumType->getDecl()->getIntegerType().getAsString(policy);
            return fieldType + "{0} " + fieldName + "{1}";
        } else if (qt->isElaboratedTypeSpecifier()) {
            return remapSingleField(
                qt.getSingleStepDesugaredType(*this->astContext),
                fieldName,
                policy);
        } else if (qt->isRecordType()) {
            string fieldType = remapRecordTypeNoConst(
                qt.getAsString(policy), *qt->getAsCXXRecordDecl(), policy);

            return fieldType + "{0} " + fieldName + "{1}";
        } else if (qt->isArrayType()) {
            auto constArray = astContext->getAsConstantArrayType(qt);
            string sizeStr =
                fmt::format("{}", constArray->getSize().getLimitedValue());
            string child = remapSingleField(
                constArray->getElementType(), fieldName, policy);
            return fmt::format(child, "{0}", "{1}[" + sizeStr + "]");
        } else {
            /*os << "    ";
            field->print(os, policy);
            os << ";\n";*/
            printf(
                "Unsupported field type:\n    qualified: %s\n    type "
                "class:%s\n",
                qt.getAsString(policy).c_str(),
                qt->getTypeClassName());
            abort();
        }
    }

    string remapRustType(const QualType& qt, const PrintingPolicy& policy) {
        if (auto builtin = qt->getAs<BuiltinType>()) {
            return remapBuiltinTypeToRust(builtin->getKind());
        } else if (qt->isFunctionPointerType()) {
            return "*mut std::ffi::c_void";
        } else if (qt->isReferenceType()) {
            string child = remapRustType(qt.getNonReferenceType(), policy);
            string ptrType = qt.getNonReferenceType().isConstQualified()
                                 ? "*const "
                                 : "*mut ";

            if (child == "()") {
                return ptrType + "std::ffi::c_void";
            } else {
                return ptrType + child;
            }
        } else if (qt->isPointerType()) {
            string child = remapRustType(qt->getPointeeType(), policy);
            string ptrType =
                qt->getPointeeType().isConstQualified() ? "*const " : "*mut ";
            if (child == "()") {
                return ptrType + "std::ffi::c_void";
            } else {
                return ptrType + child;
            }
        } else if (qt->isEnumeralType()) {
            const EnumType* enumType = qt->getAs<EnumType>();
            remapEnumToRust(*enumType->getDecl(), policy);

            const QualType& intType = enumType->getDecl()->getIntegerType();
            return remapRustType(intType, policy);
        } else if (qt->isElaboratedTypeSpecifier()) {
            return remapRustType(
                qt.getSingleStepDesugaredType(*this->astContext), policy);
        } else if (qt->isRecordType()) {
            string fieldType = remapRecordTypeNoConst(
                qt.getAsString(policy), *qt->getAsCXXRecordDecl(), policy);
            return gc->remappedCToRust[fieldType];
        } else if (qt->isArrayType()) {
            auto constArray = astContext->getAsConstantArrayType(qt);
            string child = remapRustType(constArray->getElementType(), policy);
            return fmt::format(
                "[{}; {}]", child, constArray->getSize().getLimitedValue());
        } else {
            /*os << "    ";
            field->print(os, policy);
            os << ";\n";*/
            printf(
                "Unsupported (rust) field type:\n    qualified: %s\n    type "
                "class:%s\n",
                qt.getAsString(policy).c_str(),
                qt->getTypeClassName());
            abort();
        }
    }

    string remapEnumToRust(const EnumDecl& decl, const PrintingPolicy& policy) {
        string qualName = decl.getQualifiedNameAsString();

        if (auto it = gc->enums.find(qualName); it != gc->enums.end()) {
            return it->second.getQualifiedRustType();
        }

        const string enumName = decl.getNameAsString();

        const DeclContext* ctx = decl.getDeclContext();
        vector<const DeclContext*> contexts;

        // Collect named contexts.
        while (ctx) {
            if (isa<NamedDecl>(ctx))
                contexts.push_back(ctx);
            ctx = ctx->getParent();
        }

        vector<string> scope;

        for (const DeclContext* dc : llvm::reverse(contexts)) {
            if (const auto* nd = dyn_cast<NamespaceDecl>(dc)) {
                string n = nd->getNameAsString();
                if (n != "physx") {
                    scope.push_back(n);
                }
            } else if (const auto* rd = dyn_cast<RecordDecl>(dc)) {
                assert(rd->getIdentifier());
                string n = rd->getNameAsString();

                if (!rd->field_empty()) {
                    // We declare modules with the scope parts as names. Modules
                    // use the same name space as structs, so we need to rename
                    // the modules.
                    scope.push_back(n + "Enum");
                } else {
                    // Assume the type is just a wrapper for the enum. PhysX
                    // follows the convention that such a wrapped enum is called
                    // "Enum" or "Type".
                    assert(enumName == "Enum" || enumName == "Type");

                    scope.push_back(n);
                }
            }
        }

        ConvEnum ce;
        ce.name = enumName;
        ce.scope = scope;
        ce.intType = remapBuiltinTypeToRust(
            decl.getIntegerType()->getAs<BuiltinType>()->getKind());

        for (auto e = decl.enumerator_begin(); e != decl.enumerator_end();
             ++e) {
            ce.enumerators.push_back(
                { e->getNameAsString(),
                  fmt::format("{}", e->getInitVal().getLimitedValue()) });
        }

        gc->enums[qualName] = ce;

        return ce.getQualifiedRustType();
    }

    void remapRecordTypeFields(
        const CXXRecordDecl& decl,
        const PrintingPolicy& policy,
        PodRecord* const rec) {
        for (auto it = decl.bases_begin(); it != decl.bases_end(); ++it) {
            QualType qt = it->getType();
            remapRecordTypeFields(*qt->getAsCXXRecordDecl(), policy, rec);
        }

        for (auto field = decl.field_begin(); field != decl.field_end();
             ++field) {
            string fieldName = field->getNameAsString();

            bool anonymous = false;
            if (fieldName.empty()) {
                static unsigned incr = 0;
                fieldName = fmt::format("anonymousField_{}", incr++);
                anonymous = true;
            }

            PodRecordField recField;
            recField.name = fieldName;
            recField.decl = fmt::format(
                remapSingleField(field->getType(), fieldName, policy), "", "");
            recField.cppType = field->getType().getAsString(policy);
            recField.rustType = remapRustType(field->getType(), policy);
            recField.isReference = field->getType()->isReferenceType();
            recField.accessible =
                field->getAccess() != AccessSpecifier::AS_private && !anonymous;

            rec->fields.emplace_back(recField);
        }
    }

    string remapRecordTypeNoConst(
        string qualifiedName,
        const CXXRecordDecl& decl,
        const PrintingPolicy& policy) {
        const string sourceFile = this->astContext->getSourceManager()
                                      .getFilename(decl.getLocation())
                                      .str();

        // Ony include types defined in PhysX
        if (sourceFile.find(REQUIRED_PATH_COMPONENT) == string::npos) {
            return "void";
        }

        qualifiedName = stripPrefix(qualifiedName, "const ");

        const auto foundType = gc->podTypeRemap.find(qualifiedName);
        if (foundType == gc->podTypeRemap.end()) {
            string remappedTypeName = qualifiedName;
            remappedTypeName = replaceString(remappedTypeName, "::", "_");
            replace(remappedTypeName.begin(), remappedTypeName.end(), '<', '_');
            replace(remappedTypeName.begin(), remappedTypeName.end(), '>', '_');
            replace(remappedTypeName.begin(), remappedTypeName.end(), ' ', '_');

            bool isAnonymous = false;

            if (remappedTypeName.find("(anonymous") != string::npos || remappedTypeName.find("(unnamed)") != string::npos) {
                isAnonymous = true;
                remappedTypeName =
                    fmt::format("Anonymous{}", gc->podTypeRemap.size());
            }

            string rustTypeName = remappedTypeName;
            rustTypeName = stripPrefix(rustTypeName, "physx_");
            rustTypeName = stripPrefix(rustTypeName, "pvdsdk_");

            remappedTypeName += "_Pod";

            gc->podTypeRemap[qualifiedName] = remappedTypeName;

            PodRecord rec;
            rec.typeName = remappedTypeName;

            // TODO: handle template typedefs, e.g.
            // typedef PxFlags<PxActorTypeFlag::Enum,PxU16> PxActorTypeFlags
            if (!isAnonymous &&
                nullptr == decl.getTemplateInstantiationPattern()) {
                rec.cppTypeName = qualifiedName;
            }

            rec.recordType = (decl.isUnion() ? "union" : "struct");
            rec.rustTypeName = rustTypeName;

            gc->remappedCToRust[remappedTypeName] = rustTypeName;

            if (decl.getDefinition()) {
                rec.hasDefinition = true;
                rec.hasVtable = decl.isPolymorphic();
                remapRecordTypeFields(decl, policy, &rec);
                rec.fixEmptyStruct();
            }

            /*if (!isAnonymous && decl.getDefinition() &&
                !decl.getTemplateInstantiationPattern()) {
                os << fmt::format(
                    "static_assert(sizeof({0}) == sizeof({1}), \"POD "
                    "wrapper for {0} has incorrect size.\");\n",
                    qualifiedName,
                    remappedTypeName);
            }*/

            // globalOs << os.str();
            gc->recs.emplace_back(rec);
            return remappedTypeName;
        } else {
            return foundType->second;
        }
    }

    string remapRecordType(
        string qualifiedName,
        const CXXRecordDecl& decl,
        const PrintingPolicy& policy) {
        if (qualifiedName.rfind("const ") == 0) {
            qualifiedName = qualifiedName.substr(6);
        }

        return remapRecordTypeNoConst(qualifiedName, decl, policy);
    }

    CppType convertTypeInner(const QualType& qt, const PrintingPolicy& policy) {
        const string cppType = stripPrefix(qt.getAsString(policy), "const ");

        if (auto recordDecl = qt->getAsCXXRecordDecl()) {
            const string cType = remapRecordType(cppType, *recordDecl, policy);
            const string rustType = gc->remappedCToRust[cType];
            if (rustType.empty()) {
                printf(
                    "Could not map type %s to Rust. Available types:\n",
                    stripPrefix(cType, "const ").c_str());
                for (auto& kv : gc->remappedCToRust) {
                    printf(
                        "%s -> %s; cpp: %s\n",
                        kv.first.c_str(),
                        kv.second.c_str(),
                        cppType.c_str());
                }
                abort();
            }

            // printf("%s -> %s\n", cppType.c_str(), cType.c_str());

            const string c2cppCode =
                "{cppType} {cppName};\n"
                "memcpy(&{cppName}, &{cName}, sizeof({cppName}));\n";

            const string cpp2cCode =
                "{cType} {cName};\n"
                "memcpy(&{cName}, &{cppName}, sizeof({cName}));\n";

            return CppType(cppType, cType, rustType, c2cppCode, cpp2cCode);
        } else if (qt->isEnumeralType()) {
            const EnumType* enumType = qt->getAs<EnumType>();
            string desugared =
                enumType->getDecl()->getIntegerType().getAsString(policy);
            string rustType = remapEnumToRust(*enumType->getDecl(), policy);

            const string c2cppCode =
                "{cppType} {cppName} = ({cppType}){cName};\n";

            const string cpp2cCode = "{cType} {cName} = ({cType}){cppName};\n";

            return CppType(cppType, desugared, rustType, c2cppCode, cpp2cCode);
        } else if (qt->isFunctionPointerType()) {
            const string c2cppCode =
                "{cppType} {cppName};\n"
                "memcpy(&{cppName}, &{cName}, sizeof({cppName}));\n";

            const string cpp2cCode =
                "{cType} {cName};\n"
                "memcpy(&{cName}, &{cppName}, sizeof({cName}));\n";

            return CppType(
                cppType,
                "void*",
                "*mut std::ffi::c_void",
                c2cppCode,
                cpp2cCode);
        } else if (qt->isPointerType()) {
            QualType inner = qt->getPointeeType();
            return convertTypeInner(inner, policy)
                .ptr(mutabilityFromConstness(inner.isConstQualified()));
        } else if (qt->isReferenceType()) {
            QualType inner = qt.getNonReferenceType();
            return convertTypeInner(inner, policy)
                .ref(mutabilityFromConstness(inner.isConstQualified()));
        } else if (auto builtin = qt->getAs<BuiltinType>()) {
            string desugared = remapBuiltinTypeToCpp(builtin->getKind());
            string rustType = remapBuiltinTypeToRust(builtin->getKind());
            return CppType(desugared, desugared, rustType);
        } else {
            printf(
                "Unsupported type:\n    qualified: %s\n    type class:%s\n",
                cppType.c_str(),
                qt->getTypeClassName());
            abort();
        }
    }

    CppType convertType(QualType qt, const PrintingPolicy& policy) {
        qt.removeLocalConst();
        return convertTypeInner(qt, policy);
    }

    static bool hasReleaseMethod(const CXXRecordDecl& decl) {
        for (auto it = decl.bases_begin(); it != decl.bases_end(); ++it) {
            if (hasReleaseMethod(*it->getType()->getAsCXXRecordDecl())) {
                return true;
            }
        }

        for (auto it = decl.method_begin(); it != decl.method_end(); ++it) {
            if (it->getNameAsString() == "release") {
                return true;
            }
        }

        return false;
    }

    void addFnArguments(
        const FunctionDecl* cmd,
        CppFn* const fn,
        const PrintingPolicy& policy) {
        for (unsigned int i = 0; i < cmd->getNumParams(); i++) {
            const QualType qt = cmd->parameters()[i]->getType();

            CppFnArg arg;
            ((CppType&)arg) = convertType(qt, policy);
            arg.cppName = cmd->parameters()[i]->getQualifiedNameAsString();

            if (arg.cppName.empty()) {
                arg.cppName = fmt::format("anonymous_arg{}", i);
            }

            fn->args.emplace_back(arg);
        }
    }

    void run(const MatchFinder::MatchResult& Result) override {
        this->astContext = Result.Context;
        PrintingPolicy policy(Result.Context->getPrintingPolicy());
        policy.adjustForCPlusPlus();
        // We rely on (unnamed) being printed for anonymous tag names
        policy.AnonymousTagLocations = false;

        if (const CXXMethodDecl* cmd =
                Result.Nodes.getNodeAs<CXXMethodDecl>("publicMethodDecl")) {
            if (cmd->isTemplated() || cmd->isTemplateInstantiation() ||
                cmd->getParent()->isTemplated()) {
                return;
            }

            if (cmd->getAccessUnsafe() != clang::AccessSpecifier::AS_public) {
                return;
            }

            string className = cmd->getParent()->getDeclName().getAsString();
            string qualifiedClassName =
                cmd->getParent()->getQualifiedNameAsString();

            if (className.empty() ||
                qualifiedClassName.find("(anonymous") != string::npos) {
                return;
            }

            // Ignore operator overloadings
            if (cmd->isOverloadedOperator()) {
                return;
            }

            CppFn fn;

            bool hasSelf = !cmd->isStatic();
            QualType selfType = QualType(cmd->getParent()->getTypeForDecl(), 0);

            // constructor
            if (const CXXConstructorDecl* ccd =
                    dyn_cast<CXXConstructorDecl>(cmd)) {
                if (ccd->isCopyConstructor() || ccd->isMoveConstructor() ||
                    cmd->getParent()->isAbstract() ||
                    cmd->getParent()->isEmpty())
                    return;

                hasSelf = false;

                if (cmd->getParent()->isPolymorphic() ||
                    !cmd->getParent()->hasSimpleDestructor()) {
                    fn.name = className + "_new_alloc";
                    const auto retValueType = convertType(selfType, policy);
                    fn.valueExpr = shared_ptr<CppNewResult>(
                        new CppNewResult(retValueType.getCppType()));
                    fn.returnType = retValueType.ptr(Mutability::Mutable);
                } else {
                    fn.name = className + "_new";
                    fn.returnType = convertType(selfType, policy);
                    fn.valueExpr = shared_ptr<CppCtorResult>(
                        new CppCtorResult(fn.returnType.getCppType()));
                }
            } else if (isa<CXXDestructorDecl>(cmd)) {
                if (cmd->getParent()->hasIrrelevantDestructor() ||
                    hasReleaseMethod(*cmd->getParent())) {
                    return;
                }

                fn.name = className + "_delete";
                fn.valueExpr = nullptr;
                fn.returnType = CppType("void", "void", "()");
                fn.bodyPreamble += "delete self_;\n";
            } else {
                fn.name = className + "_" + cmd->getNameAsString();
                if (!cmd->isConst()) {
                    fn.name += "_mut";
                }

                if (cmd->isStatic()) {
                    fn.valueExpr =
                        shared_ptr<CppFnCallResult>(new CppFnCallResult(
                            className + "::" + cmd->getNameAsString()));
                } else {
                    fn.valueExpr =
                        shared_ptr<CppFnCallResult>(new CppFnCallResult(
                            "self_->" + cmd->getNameAsString()));
                }

                fn.returnType = convertType(cmd->getReturnType(), policy);
            }

            auto it = gc->funcList.find(fn.name);

            if (it != gc->funcList.end()) {
                it->second++;
                fn.name += fmt::format("_{}", it->second);
            } else {
                gc->funcList[fn.name] = 0;
            }

            if (hasSelf) {
                CppFnArg arg;
                ((CppType&)arg) =
                    convertType(selfType, policy)
                        .ptr(mutabilityFromConstness(cmd->isConst()));
                arg.cppName = "self_";
                fn.args.push_back(arg);
                fn.hasSelf = true;
            }

            addFnArguments(cmd, &fn, policy);

            gc->fns.emplace_back(fn);
        } else if (
            const FunctionDecl* cmd =
                Result.Nodes.getNodeAs<FunctionDecl>("publicFnDecl")) {
            if (cmd->isTemplated() || cmd->isTemplateInstantiation() ||
                cmd->isCXXClassMember() ||
                cmd->getFriendObjectKind() != Decl::FOK_None) {
                return;
            }

            CppFn fn;

            fn.name = "phys_" + cmd->getNameAsString();
            fn.valueExpr = shared_ptr<CppFnCallResult>(
                new CppFnCallResult(cmd->getNameAsString()));

            fn.returnType = convertType(cmd->getReturnType(), policy);

            auto it = gc->funcList.find(fn.name);
            if (it != gc->funcList.end()) {
                it->second++;
                fn.name += fmt::format("_{}", it->second);
            } else {
                gc->funcList[fn.name] = 0;
            }

            addFnArguments(cmd, &fn, policy);

            gc->fns.emplace_back(fn);
        } else if (
            const EnumDecl* cmd =
                Result.Nodes.getNodeAs<EnumDecl>("publicEnumDecl")) {

            if (!cmd->getNameAsString().empty()) {
                remapEnumToRust(*cmd, policy);
            }
        }
    }
};

class MyASTConsumer : public ASTConsumer {
  public:
    MyASTConsumer(shared_ptr<GeneratorContext> gc)
      : matchHandler(gc) {
        matchFinder.addMatcher(
            cxxMethodDecl(
                allOf(isPublic(), unless(isExplicitTemplateSpecialization())),
                ofClass(allOf(
                    matchesName("Px.*"),
                    unless(isExplicitTemplateSpecialization()))))
                .bind("publicMethodDecl"),
            &matchHandler);

        matchFinder.addMatcher(
            functionDecl(allOf(
                             matchesName("Px.*"),
                             unless(isExplicitTemplateSpecialization())))
                .bind("publicFnDecl"),
            &matchHandler);

        matchFinder.addMatcher(
            enumDecl(matchesName("Px.*")).bind("publicEnumDecl"),
            &matchHandler);
    }

    void HandleTranslationUnit(ASTContext& Context) override {
        matchFinder.matchAST(Context);
    }

  private:
    ClassMatchHandler matchHandler;
    MatchFinder matchFinder;
};

// For each source file provided to the tool, a new FrontendAction is created.
class MyFrontendAction : public ASTFrontendAction {
  public:
    MyFrontendAction()
      : gc(make_shared<GeneratorContext>()) {}

    void EndSourceFileAction() override {
        {
            ofstream f("structgen/structgen.cpp");
            f << "// Automatically generated by pxbind\n";
            f << "#include \"PxPhysicsAPI.h\"\nusing namespace physx;\n\n";

            f << "#define unsafe_offsetof(st, m) ((size_t) ( (char *)&((st "
                 "*)(0))->m - (char *)0 ))\n";

            f << "#include \"structgen.hpp\"\n"
                 "int main() {\n"
                 "PodStructGen structGen;\n";

            for (const auto& rec : gc->recs) {
                f << rec.genLayoutCalcCode() << "\n";
            }

            f << "structGen.finish();\n";
            f << "}\n";
        }

        {
            ofstream f("physx_generated.hpp");

            f << "using namespace physx;\n";
            f << "#include \"structgen_out.hpp\"\n";

            for (const auto& rec : gc->recs) {
                f << rec.genStaticAssertCode();
            }

            f << "extern \"C\" {\n";
            for (const auto& fn : gc->fns) {
                f << fn.genCppDef() << "\n";
            }
            f << "}\n";
        }

        {
            ofstream f("physx_generated.rs");
            for (const auto& e : gc->enums) {
                f << e.second.genRustDef();
            }

            for (const auto& rec : gc->recs) {
                f << rec.genRustDecl();
            }

            f << "extern \"C\" {\n";

            for (const auto& rec : gc->fns) {
                f << rec.genRustDecl();
            }

            f << "}\n";
        }
    }

    std::unique_ptr<ASTConsumer> CreateASTConsumer(
        CompilerInstance& CI,
        StringRef file) override {
        return std::make_unique<MyASTConsumer>(gc);
    }

  private:
    shared_ptr<GeneratorContext> gc;
};

int main(int argc, const char** argv) {
    // parse the command-line args passed to your code
    static llvm::Expected<CommonOptionsParser> op_res = CommonOptionsParser::create(argc, argv, PxBindCategory);
    if(auto test = op_res.takeError()) {
        std::cerr << "Failed to create common options parser" << std::endl;
        return 1;
    }
    CommonOptionsParser &op = *op_res;
    // create a new Clang Tool instance (a LibTooling environment)
    ClangTool Tool(op.getCompilations(), op.getSourcePathList());

    // run the Clang Tool, creating a new FrontendAction
    return Tool.run(newFrontendActionFactory<MyFrontendAction>().get());
}
