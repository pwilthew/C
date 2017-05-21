#include "readline.h"
/*
 * Read dogs' names, breeds, and owner last names
 */
int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()))
    ;
    
    str[i++] = ch;
    while ((ch = getchar()) != '\n') {
    
        if (i < n)
            str[i++] = ch;
    }

    str[i] = '\0';
    return i;
 }
