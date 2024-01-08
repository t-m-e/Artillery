#include "artillery.h"

int main() {
    char* file = "../Infector/asm/write_hack.asm";
    char code[1024] = { 0 };
    size_t size = Nasm(
        NULL, 
        64, 
        file, 
        code,
        1024
    );

    if (size == 0) return -1;

    Formatter_bytecode(code, size);

    return 0;
}
