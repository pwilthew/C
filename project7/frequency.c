/* Project 7
 * frequency.c
 * Student: Patricia Wilthew
 * Description: Outputs the frequency of characters of a string
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
#define WORD_SIZE 20

int read_line(char *str, int n);

int main() {

    int freq[N] = {0};
    char string[N];
    char words[N][WORD_SIZE];
    char *p;
    int flag;
    int i = 0, j = 0, k = 0;

    //initialize array of words
    for (j = 0; j < N; j++) {

        for (k = 0; k < WORD_SIZE; k++) {

            words[j][k] = '\0';
        }
    }

    //ask and store input
    printf("Input: ");
    read_line(string, N);
    
    //get first word from string
    p = strtok(string, " .,-!");

    while (p != NULL) {
        
        flag = 0;
        
        //for each new word found, see if its in the array words
        for (j = 0; j <= i ; j++) {
            
            if (strcmp(words[j], p) == 0) { 
                
                flag = 1;
                break;
            } 
        }
    
        //if the word is already in the array words, then flag should be 1
        if (flag == 1) {

            freq[j] += 1; 
        }
        //if the word is not in the array, flag shoul be 0 and word should be copied to array
        else {

            strcpy(words[i], p);
            freq[i] += 1;
            i++;
        }

        //obtain next word
        p = strtok(NULL, " .,-!");
    }
  
    //print results

    printf("Output:\n");
    for (k = 0; k < i; k++) {

        printf("%s\t%d\n", words[k], freq[k]);

    }

    return(0);
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

