/* Name: remove.c
 *  Description: Takes input from the user, removes all non alphanumeric
 *  characters, bring all leters to uppercase and prints the new message
 *  Student: Patricia Wilthew
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char message[200];
    int i = 0;

    printf("Enter text: ");

    while ((message[i] = getchar()) != '\n' )
    {
        if ((isalpha(message[i]) || isspace(message[i])))
        {
            message[i] = toupper(message[i]);
            printf("%c", message[i]);
        }

        i++;
    }

    printf("\n");

    return(0);
}


