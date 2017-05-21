/* Name: extract.c
*  Description: extracts web addresses starting with www. and ending with .edu
*  Student: Patricia Wilthew
*/
#include <stdio.h>
#include <stdlib.h>
#define N 1000

void extract(char *s1, char *s2);
int read_line(char *str, int n);

int main() {

    char address[N+1];
    char new_address[N+1] = {0};

    printf("Input: ");
    read_line(address, N);

    extract(address, new_address);

    printf("Output: %s\n", new_address);

    return(0);
}

/* Function extract()
 * Input: a char array with a web address string
 * Output: a char array with web address subtring, if the web address has 
 * www. as prefix and .edu as suffix
 */
void extract(char *s1, char *s2) {

    char *p = s1;
    int i = 0;

    // Check if the string starts with http://
    if ((*p == 'h') & (*(p + 1) == 't') & (*(p + 2) == 't') & (*(p + 3) == 'p') & (*(p + 4) == ':') & (*(p + 5) == '/') & (*(p + 6) == '/')) {

        // if the string starts with http:// point the pointer to the first caracter after http://
        p = p + 7;

        // Check if the address has www.
        if ((*p == 'w') & (*(p + 1) == 'w') & (*(p + 2) == 'w') & (*(p + 3) == '.')) {

            // Add www. to the output array (s2)
            while (i < 4) {
                *s2++ = *p++;
                i++;
            }
            
            // Add the rest of the address to the output array (s2) until a period '.' is found
            while (*p != '.') {
                *s2++ = *p++;
            }

            // Check if the address ends in edu.
            if ((*p == '.') & (*(p + 1) == 'e') & (*(p + 2) == 'd') & (*(p + 3) == 'u') ) {
                
                // Add the 'edu' to the output array (s2)
                for (i = 0; i < 4; i++) {
                    *s2++ = *p++;
                }

            }
            // If it does not end in edu. then inform and exit
            else {
                s2 = '\0';
                printf("Web address starting with www. and ending with .edu not found\n");
                exit(EXIT_SUCCESS);
            }
        // If the address does not start with www. then inform exit
        } else {
                s2 = '\0';
                printf("Web address starting with www. and ending with .edu not found\n");
                exit(EXIT_SUCCESS);
        }
    }
    // If the string does not start with http:// then inform it is not an address and exit
    else {
        printf("No web address found\n");
        exit(EXIT_SUCCESS);
    }

}

/* Function read_line() 
 * Input: integer n with the number of characters to read
 * Output: array of characters with the characters read from standard input
 */
int read_line(char *str, int n)
{
    int ch, i = 0; 

    while ((ch = getchar()) != '\n'){  

        if (i < n){
            *str++= ch;  
            i++;
        }
    }
    
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}


