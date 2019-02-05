/* 
 * File:   simple_string.c
 * Author: marcd
 *
 * Created on February 1, 2019, 6:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "simp_str.h"

/*
 * 
 */


int main(int argc, char** argv) {
    //**************************************************
    //try the initialize function                      *
    //**************************************************
    simp_str *s1 = simp_str_init("This is a string", 16);
    simp_str *s2 = simp_str_init("This be a string", 16);
    
    printf("s1 = ");
    puts(s1->str);
    printf("s2 = ");
    puts(s2->str);
    
    //**************************************************
    //try the compare function                         *
    //**************************************************
    printf("Comparing s1 and s2...\n");
    if (simp_str_equals(s1,s2))
    {
        printf("Strings are equal!\n");
    }
    else
    {
        printf("Strings are not equal!\n");
    }
    
    //**************************************************
        //try the copy function                        *
    //**************************************************
    simp_str *s3 = simp_str_copy(s2);
    printf("s3 = ");
    puts(s3->str);
    
    if (simp_str_equals(s2,s3))
    {
        printf("Strings are equal!\n");
    }
    else
    {
        printf("Strings are not equal!\n");
    }

    //**************************************************    
    //try the format function                          *
    //**************************************************
    int x = 100;
    int y = 200;
    int z = x + y;
    
    simp_str *s4 = simp_str_init("Test", 4);
    simp_str *s5 = simp_str_init(" ", 1);
    simp_str_format(s4,"My favorite number is %d", x);
    simp_str_format(s5,"The sum of %d and %d is %d", x, y, z);
    
    //**************************************************
    // clean the mess you caused                       *
    //**************************************************
    simp_str_destroy(s1);
    simp_str_destroy(s2);
    simp_str_destroy(s3);
    simp_str_destroy(s4);
    simp_str_destroy(s5);

    return (0);
}
//*****************************************************************************
// End of main                                                                *
//*****************************************************************************
//                                                                            *
//                                                                            *
//*****************************************************************************
// Initialize simple strings                                                  *
//*****************************************************************************
simp_str* simp_str_init(const char* stringToUse, size_t in)
{
    simp_str *initialized_str = malloc(sizeof(simp_str));
    if (!initialized_str)
    {
        return NULL;
    }
    
    initialized_str->str = malloc(in+1);
    if (!initialized_str->str)
    {
        return NULL;
    }

    initialized_str->len = in;
    initialized_str->buf_len = in+1;
    memcpy(initialized_str->str, stringToUse, in);
    initialized_str->str[in] = '\0';
  
    return initialized_str;
}
//*****************************************************************************
// Destroy strings!                                                           *
//*****************************************************************************
void simp_str_destroy(simp_str* destroy_str)
{
    free(destroy_str->str);
    free(destroy_str);
}
//*****************************************************************************
// Compare simple strings                                                     *
//*****************************************************************************
int simp_str_equals(simp_str *s1, simp_str *s2)
{
    if (strcmp(s1->str,s2->str))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
//*****************************************************************************
// Format simple strings                                                      *
//*****************************************************************************
int simp_str_format(simp_str *format_str, const char *fmt, ...)
{
    int rc = 0;
    format_str->len = strlen(fmt);
    format_str->buf_len = format_str->len +1;
    
    format_str->str = realloc(format_str->str, format_str->buf_len);
    if (format_str->str == NULL)
    {
        return -1;
    }
    
    va_list argptr;
    va_start(argptr, fmt);
    rc = vsprintf(format_str->str, fmt, argptr);
    va_end(argptr);
    
    puts(format_str->str);
    
    return 0;
}
//*****************************************************************************
// Copy simple strings                                                        *
//*****************************************************************************
 simp_str* simp_str_copy(simp_str *orig_str)
{
     simp_str *copy_str = malloc(sizeof(simp_str));
     if(!copy_str)
     {
         return NULL;
     }
     copy_str->len = orig_str->len;
     copy_str->buf_len = orig_str->buf_len;
     copy_str->str = malloc(copy_str->buf_len);   
     if (!copy_str->str)
     {
         return NULL;
     }
     memcpy(copy_str->str, orig_str->str, copy_str->len);
     copy_str->str[copy_str->len] = '\0';
     return copy_str;
}