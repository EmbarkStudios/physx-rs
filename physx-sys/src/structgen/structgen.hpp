#include <cassert>
#include <cstdio>
#include <cstdint>
#include <vector>

struct RustCheck {
    const char* rname;
    uint32_t size;
};

struct PodStructGen {
    PodStructGen() {
        cfile = fopen("structgen_out.hpp", "w");
        rfile = fopen("structgen_out.rs", "w");
    }

    void finish() {
        fclose(cfile);

        fputs("#[cfg(test)]\nmod sizes {\n    use super::*;\n    use std::mem::size_of;\n    #[test]\n    fn check_sizes() {\n", rfile);
        for (const auto& rc : rust_checks) {
            fprintf(
                rfile,
                "        assert_eq!(size_of::<%s>(), %u);\n",
                rc.rname,
                rc.size
            );
        }
        fputs("    }\n}\n", rfile);
        fclose(rfile);
    }

    void pass_thru(const char* code) { fputs(code, cfile); }

    void begin_struct(const char* cname, const char* rname) {
        fprintf(cfile, "struct %s {\n", cname);

        fprintf(rfile, "#[derive(Clone, Copy)]\n");
        fprintf(rfile, "#[cfg_attr(feature = \"debug-structs\", derive(Debug))]\n");
        fprintf(rfile, "#[repr(C)]\n");
        fprintf(rfile, "pub struct %s {\n", rname);

        this->rname = rname;
        pos = 0;
        padIdx = 0;
    }

    void emit_padding(uint32_t bytes) {
        fprintf(cfile, "    char structgen_pad%u[%u];\n", padIdx, bytes);
        fprintf(rfile, "    pub structgen_pad%u: [u8; %u],\n", padIdx, bytes);
        ++padIdx;
    }

    void add_field(
        const char* cppDecl,
        const char* rustName,
        const char* rustType,
        size_t size,
        size_t offset) {
        assert(offset >= pos);
        if (offset > pos) {
            emit_padding(uint32_t(offset - pos));
            pos = offset;
        }
        fprintf(cfile, "    %s;\n", cppDecl);
        fprintf(rfile, "    pub %s: %s,\n", rustName, rustType);
        pos += size;
    }

    void end_struct(size_t size) {
        assert(size >= pos);
        if (size > pos) {
            emit_padding(uint32_t(size - pos));
        }
        fputs("};\n", cfile);
        fputs("}\n", rfile);

        rust_checks.emplace_back(RustCheck { rname, uint32_t(size) });
    }

  private:
    std::vector<RustCheck> rust_checks;
    FILE* cfile;
    FILE* rfile;
    const char* rname;
    size_t pos;
    uint32_t padIdx;
};
