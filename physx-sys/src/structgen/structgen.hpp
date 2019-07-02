#include <cassert>
#include <cstdio>

struct PodStructGen {
    PodStructGen() {
        cfile = fopen("structgen_out.hpp", "w");
        rfile = fopen("structgen_out.rs", "w");
    }

    void finish() {
        fclose(cfile);
        fclose(rfile);
    }

    void passThroughC(const char* code) { fputs(code, cfile); }

    void beginStruct(const char* cname, const char* rname) {
        fprintf(cfile, "struct %s {\n", cname);

        fprintf(rfile, "#[derive(Clone, Copy)]\n");
        fprintf(rfile, "#[repr(C)]\n");
        fprintf(rfile, "pub struct %s {\n", rname);

        this->rname = rname;
        pos = 0;
        padIdx = 0;
    }
    void emitPadding(unsigned bytes) {
        fprintf(cfile, "    char structgen_pad%u[%u];\n", padIdx, bytes);
        fprintf(rfile, "    pub structgen_pad%u: [u8; %u],\n", padIdx, bytes);
        ++padIdx;
    }
    void addField(
        const char* cppDecl,
        const char* rustName,
        const char* rustType,
        size_t size,
        size_t offset) {
        assert(offset >= pos);
        if (offset > pos) {
            emitPadding(unsigned(offset - pos));
            pos = offset;
        }
        fprintf(cfile, "    %s;\n", cppDecl);
        fprintf(rfile, "    pub %s: %s,\n", rustName, rustType);
        pos += size;
    }
    void endStruct(size_t size) {
        assert(size >= pos);
        if (size > pos) {
            emitPadding(unsigned(size - pos));
        }
        fputs("};\n", cfile);
        fputs("}\n", rfile);
        fprintf(
            rfile,
            "#[test] fn check_size_%s() { "
            "assert_eq!(std::mem::size_of::<%s>(), %u); }\n",
            rname,
            rname,
            unsigned(size));
    }

  private:
    FILE* cfile;
    FILE* rfile;
    const char* rname;
    size_t pos;
    unsigned padIdx;
};
