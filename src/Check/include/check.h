#ifndef CHECK_H
#define CHECK_H

/*
 * check.h is used to check for various dependencies that are required for 
 * Artillery to work. If the dependent programs don't exist, then we will:
 * * quit the program and recommend installation.
 */

/*
 * Check for NASM
 */ 
int Check_nasm();

/*
 * Check for Objdump
 */
int Check_objdump();

#endif
