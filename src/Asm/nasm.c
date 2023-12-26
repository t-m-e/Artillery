#include "nasm.h"
#include "check.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Nasm(
    char* code,         /* [in] assembly code */
    char* input,        /* [in] input file. If null, use default */
    char* output,       /* [out] output. Allocated by callee */
    size_t output_size  /* [in] output size */
) {
    if (!Check_nasm()) {
        printf("[-] nasm not found!\n");
        return 0;
    }

    int retCode = 0;
    char* _input  = (input)  ? input  : "/tmp/nasm-in";
    char* _output = "/tmp/nasm-out";
    char  _nasm_cmd[100] = { 0 };
    char  _nasm_fmt[] = "nasm -fbin %s -o %s";

    sprintf(_nasm_cmd, _nasm_fmt, _input, _output);

    FILE* f = fopen(_input, "wb");
    if (!f) {
        return 0;
    }

    if (code != NULL) {
        fwrite("bits 64\n", 1, strlen("bits 64\n"), f);
        fwrite(code, 1, strlen(code), f);
    }
    fclose(f);

    retCode = system(_nasm_cmd);
    if (retCode != 0) {
        return 0;
    }

    f = fopen(_output, "rb");
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (size > output_size) {
        return 0;
    }
    fread(output, 1, size, f);

    char _rm_fmt[] = "rm %s %s";
    char _rm_resources[100] = { 0 };
    sprintf(_rm_resources, _rm_fmt, _input, _output);
    system(_rm_resources);

    return size;
}
