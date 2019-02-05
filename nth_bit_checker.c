/* 
 * File:   nth_bit_checker.c
 * Author: marcd
 *
 * Created on February 1, 2019, 6:56 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int result, position;

int bit_position(int x, int position);

int main(int argc, char **argv) 
{
    unsigned int number;
    printf("Enter a number:\n");
    scanf("%d", &number);
    printf("Enter the bit position of number to check \n");
    scanf("%d", &position);
    
    bit_position(number, position);
    
    if(result & 1)
    {
        printf("That bit is - ON\n");
    }
    else
    {
        printf("That bit is - OFF\n");
    }
    return 0;
}

int bit_position(int number, int position)
{
    result = (number>>(position));
}

