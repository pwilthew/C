
/* Name: sort_commands.c
 * Description: Sorts the array of strings from the command line
 * Student: Patricia Wilthew
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

int compare_strings(const void *p, const void *q);

int main(int argc, char *argv[]) {

	int i;
	char *A[N];

	//copying argv to A, ignoring the name of the program
	for (i = 1; i < argc; i++){

		A[i-1] = argv[i];
	}

	qsort(A, argc-1, sizeof(char *), compare_strings);

	//printing sorted array of strings
	for (i = 0; i < argc-1; i++) {

		printf("%s ", A[i]);
	}

	printf("\n");

	return(0);
}

/* Function compare_strings
 * Description: Given two strings, returns the result of their comparison
 * Input: Two void pointers
 * Output: -1 if p<q, 0 if p=q, 1 if p>q
 */
int compare_strings(const void *p, const void *q) {

	return strcmp(*(char **)p, *(char **)q);

}