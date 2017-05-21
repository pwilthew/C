/* Project 7
 * phone_numbers.c
 * Student: Patricia Wilthew
 * Description: Translate seven-letter words in a file to their corresponding
 * phone numbers
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 7

void translate(char *word, char *phone_number);

int main() {

    FILE *input_file, *output_file;
    char line[N+1];
    char phone_number[N+1];
    char name[100];

    //ask and store input file name
    printf("\nEnter the file name: ");
    scanf("%s", name);
    input_file = fopen(name, "r");

    //verify that file exists and can be read
    if (input_file == NULL) {

        printf("Can't open file\n");
    }

    //create and open output file
    output_file = fopen(strcat(name,".cvt"), "w");
    
    //verify that file could be created
    if (output_file == NULL) {
    
        printf("Can't open file\n");
    }

    //read input file line by line
    while (fscanf(input_file, "%s", line)==1){ 
        
        //translate each line from letters to numbers
        translate(line, phone_number);

        //store those numbers in output file
        fprintf(output_file, "%s", phone_number);
        
        fprintf(output_file, "\n");
    }
    
    //close both files
    fclose(input_file);
    fclose(output_file);

    return(0);
}


/* Function translate()
 * Given an array of caps letters, returns an array
 * of their corresponding numbers according to the 
 * telephone keypad
 */
void translate(char *word, char *phone_number) {

    char *p = word;
    char *q = phone_number;

    while (*p != '\0') {

        if (*p == 'A' || *p == 'B' || *p == 'C') {
        
            *q = '2';
        }
        else if (*p == 'D' || *p == 'E' || *p == 'F') {

            *q ='3';
        }
        else if (*p == 'G' || *p == 'H' || *p == 'I') {
        
            *q = '4';
        }
        else if (*p == 'J' || *p == 'K' || *p == 'L') {

            *q = '5';
        }
        else if (*p == 'M' || *p == 'N' || *p == 'O') {

            *q = '6';
        }
        else if (*p == 'P' || *p == 'R' || *p == 'S') {

            *q = '7';
        }
        else if (*p == 'T' || *p == 'U' || *p == 'V') {

            *q = '8';
        }
        else if (*p == 'W' || *p == 'X' || *p == 'Y' || *p == 'Z') {

            *q = '9';
        }

        p++;
        q++;

    }

}
