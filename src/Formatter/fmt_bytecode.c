#include "fmt_bytecode.h"

#include <stdio.h>
#include <stddef.h>

void Formatter_bytecode(
    char* code,     /* [in] bytecode */
    size_t size     /* [in] bytecode size */
) {
    char hex[] = {
        '0', '1', '2', '3', 
        '4', '5', '6', '7', 
        '8', '9', 'a', 'b', 
        'c', 'd', 'e', 'f'
    };

    for (size_t i = 0; i < size; i++) {
        unsigned char h = (unsigned char)code[i] >> 4;
        unsigned char l = (unsigned char)code[i] & 0x0f;
        printf("\\x%c%c", hex[h], hex[l]);
    }
    printf("\n");
}
