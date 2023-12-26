/* include artillery headers */
#include "artillery.h"

/* c std libs */
#include <stdio.h>
#include <string.h>


int main() {
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

    char code[1024] = { 0 };
    int size = Nasm(
        assembly,
        64,
        NULL,
        code,
        1024
    );

    if (size == 0) return -1;

    Formatter_bytecode(code, size);
    (*(void (*)(void)) code)(); /* call shellcode as function pointer */

    return 0;
}
