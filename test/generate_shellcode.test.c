/* include artillery headers */
#include "artillery.h"

/* C std libs */
#include <stdio.h>

int main() {
    char* assembly = 
        "mov eax, 0\n"
        "mov ebx, 0\n"
        "mov rax, 1\n"
        "mov rbx, 2\n";
    char code[1024] = { 0 };
    int size = Nasm(
        assembly,
        NULL,
        code,
        1024
    );

    if (size == 0) return -2;

    Formatter_bytecode(code, size);

    return 0;
}
