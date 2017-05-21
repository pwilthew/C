/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
/*
 * Patricia Wilthew
 */
#include "readline.h"
#include "dogs.h"
#include <stdio.h>
int main(void)
{
    char code;

    struct dog *dog_list = NULL;  

    printf("Operation Code: a for appending to the list, s for finding a dog"
        ", p for printing the list; q for quit.\n");
   
    for (;;) {

        printf("Enter operation code: ");
        scanf(" %c", &code);

        while (getchar() != '\n')   /* skips to end of line */
        ;

        switch (code) {
            case 'a': dog_list = append(dog_list);
                break;
            case 's': search(dog_list);
                break;
            case 'p': print(dog_list);
                break;
            case 'q': clear(dog_list);
		        return 0;
            default:  printf("Illegal code\n");
        }

    printf("\n");

    }

    return(0);
}
