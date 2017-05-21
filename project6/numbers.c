/* Name: numbers.c
 * Description: finds either the largest or smallest of the ten numbers as command
 * line arguments
 * Student: Patricia Wilthew
 */
#include <stdio.h>
#include <stdlib.h>
#define N 10

int find_largest(int *numbers);
int find_smallest(int *numbers);

int main(int argc, char *argv[]) {

    int output; 
    int numbers[N];
    int option;
    int i;

    if (argc != (N+2)) {

        printf("Invalid option. Use -s for smallest and -l for largest. Enter %d numbers.\n", N);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < N; i++) {

        numbers[i] = atoi(argv[i+2]);

    }

    // Get input option (s or l) in 'option'
    option = *++argv[1]; //Use of increment because we care about s or l and not the dash -

    if (option == 's') {

        output = find_smallest(numbers);
    }
    else if (option == 'l') {

        output = find_largest(numbers);
    }
    else {
        printf("Invalid option '%d'.\n", option);
        exit(EXIT_FAILURE);
    }
    
    printf("%d\n", output);

    return(0);
}

/* Function find_largest()
 * Input: array of N numbers
 * Output: largest integer in the array
 */
int find_largest(int *numbers) {

    int largest = numbers[0];
    int i;

    for (i = 0; i < N; i++) {
        if (largest < numbers[i])
            largest = numbers[i]; 
    }

    printf("The largest number is ");
    return(largest);
}

/* Function find_smallest()
 * Input: array of N numbers
 * Output: smallest integet in the array
 */
int find_smallest(int *numbers) {

    int smallest = numbers[0];
    int i;

    for (i = 0; i < N; i++) {
        if (smallest > numbers[i])
            smallest = numbers[i]; 
    }

    printf("The smallest number is ");
    return(smallest);

}


