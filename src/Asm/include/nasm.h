#ifndef NASM_H
#define NASM_H

#include <stddef.h>

/*
 * Define initial logic for nasm assembly.
 */
int Nasm(
    char* code,         /* [in] assembly code input */
    char* input,        /* [in] nasm input location */
    char* output,       /* [out] nasm output location */
    size_t output_size  /* [in] output size */
);

#endif
