/* 
 * File:   endian.c
 * Author: marcd
 *
 * Created on February 1, 2019, 6:39 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char **argv) {
    unsigned int x = 0x76543210;
    char *p = (char*) &x;
    
    printf("*p is: 0x%x\n", *p);
    
    if(*p == 0x10)
    { //if stored as x10|32|54|76
        printf("Little Endian!  \n");
    }
    else
    { //if stored as x76|54|32|10
        printf("Big Endian!  \n");
    }

    return 0;
}

