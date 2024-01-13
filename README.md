# Artillery v1.0.0

## Road Map

Artillery is undergoing a transformation over the next few iterations. 
Artillery v1.0.0 is a wrapper on the Nasm assembler and is mostly used to create quick tests for assembly code without having to first assemble code and create a binary file for your shellcode. It will load the shellcode directly into a buffer and provide the size of the generated binary if successful.

### What's in v2.0.0

Artillery v2.0.0 is going to be non-dependent on Nasm or any assembler and will provide:
- [ ] limited instruction set 
    - 'mov, add, sub, xor, and, or, push, pop, ret, syscall, etc...`
- [ ] options for 32 and 64 bit binaries
    - this is already an option for v1.0.0 but that is for control over Nasm assembed binaries

### What's in v3.0.0

Artillery v3.0.0 is going to be a highly featured assembler and will provide:
- [ ] broader instruction set
- [ ] configurable assembler options
    - `AsmConfig` struct which contains assembler options

## v1.0.0

Shellcode generator written in C. Uses NASM to generate binary for shellcode.
In its current form, Artillery can be put into a C program to generate shellcode.

## Example

This may be a more dramatic example, but this code does work.

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
