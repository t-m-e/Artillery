#include "nasm.h"
#include "check.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Nasm(
    char* code,         /* [in] assembly code */
    int   bit_mode,     /* [in] 16, 32, or 64-bit mode */
    char* input,        /* [in] input file. If null, use default */
    char* output,       /* [out] output buffer */
    size_t output_size  /* [in] largest possible buffer size */
) {
    if (!Check_nasm()) {
        printf("[-] nasm not found!\n");
        return 0;
    }

    if (!(bit_mode == 16 || bit_mode == 32 || bit_mode == 64)) {
        printf("[-] incorrect nasm bit-mode `%d` found!", bit_mode);
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
        char _bitmode_fmt[] = "bits %d\n";
        char _bitmode_buf[25] = { 0 };
        sprintf(_bitmode_buf, _bitmode_fmt, bit_mode);
        
        fwrite(_bitmode_buf, 1, strlen(_bitmode_buf), f);
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
