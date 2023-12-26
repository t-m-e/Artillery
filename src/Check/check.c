#include "check.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

int Check_nasm() {
    char result[100] = { 0 };
    FILE* pf;

    /* execute bash command */
    pf = popen("which nasm", "r");
    if (!pf) {
        return 0;
    }

    fgets(result, 100, pf);

    if (strcmp(result, "/usr/bin/nasm\n") != 0) {
        return 0;
    }

    pclose(pf);
    return 1;
}

int Check_objdump() {
    char result[100] = { 0 };
    FILE* pf;

    /* execute bash command */
    pf = popen("which objdump", "r");
    if (!pf) {
        return 0;
    }

    fgets(result, 100, pf);

    if (strcmp(result, "/usr/bin/objdump\n") != 0) {
        return 0;
    }

    pclose(pf);
    return 1;
}
