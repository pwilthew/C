/* Name: replace2.c
 *  Description: Gets a positive integrer of any lenght, replace its digit by 
 *  the sum of that digit plus 6, modulus 10. Then swaps the first number with 
 *  last number.
 *  Student: Patricia Wilthew
 */
#include <stdio.h>
#include <stdlib.h>

void replace(int *a, int *b, int n);
void swap(int *p, int *q);

int main() {

    int n, a[n], b[n], *p;

    //Get length of number
    printf("Enter the number of digits of the number: ");
    scanf("%d", &n);

    //Get number
    printf("Enter the number: ");
    for (p = &a[0]; p < &a[n]; p++) {
        scanf("%1d", p);
    }

    //Perform calculations
    replace(a, b, n);
    swap(&b[0], &b[n-1]);

    //Print result
    printf("Output: ");
    for (p = &b[0]; p < &b[n]; p++) {
        printf("%d", *p);
    }

    return(1);
}

/* Function: replace(int array a, int array b, int n)
 * Description: takes each of the digits stored in array a of size n
 * to perfom the operation 'plus 6 modulus 10' and stores each result in array b
 */
void replace(int *a, int *b, int n) {

    int *p, *q;

    for (p = &a[0], q = &b[0]; p < &a[n]; p++, q++) {
        *q = (*p + 6) % 10;
    }
}

/* Function: swap(int p, int q)
 * Description: takes two addresses with two integers stored in each,
 * and swaps their values.
 */
void swap(int *p, int *q) {
    
    int temp = *p;
    *p = *q;
    *q = temp;
}
