#ifndef NASM_H
#define NASM_H

#include <stddef.h>

/*
 * Define initial logic for nasm assembly.
 */
int Nasm(
    char* code,         /* [in] assembly code */
    int   bit_mode,     /* [in] 16, 32, or 64-bit mode */
    char* input,        /* [in] nasm input path */
    char* output,       /* [out] nasm output path */
    size_t output_size  /* [in] largest possible binary size */
);

#endif
