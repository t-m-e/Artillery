# Artillery

Shellcode generator written in C. Uses NASM to generate binary for shellcode.
In its current form, Artillery can be put into a C program to generate shellcode.

## Example

This may be a more dramatic example, but this is code does work.

```c
/* includes for artillery */
#include "artillery.h"

int main() {
    /* assembly code */
    char* assembly = 
        "mov rdi, \"/bin/sh\"\n"
        "push rdi\n"
        "mov rdi, rsp\n"
        "xor rsi, rsi\n"
        "xor rdx, rdx\n"
        "mov rax, 59\n"
        "syscall\n"
        "pop rax\n"
        "ret\n";

    /* where the output binary will go */
    char code[1024] = { 0 };
    /* perform the assembly, and record the size of the binary */
    int size = Nasm(
        assembly,
        NULL,
        code,
        1024
    );

    /* escape if we didn't create a binary */
    if (size == 0) return -1;

    /* output bytecode */
    Formatter_bytecode(code, size);

    /* execute code */
    (*(void (*)(void)) code)();

    return 0;
}
```
