/* Name: barcode2.c
*  Description: Gets a binary string and finds its edges of dark and light regions
*  Student: Patricia Wilthew
*/
#include <stdio.h>
#include <stdlib.h>
#define N 8

void edge(int n, int *byte1, int *byte2);

/* Main function 
*/
int main()
{
    int i, byte[N], barcode[N];

    //Get input: 8 bits
    printf("Input: ");
    for (i = 0 ; i < N ; i++)
    {
        scanf("%1d", &byte[i]);
    }

    //Call to edge(), result will be stored in barcode[]
    edge(N, byte, barcode);

    //Print output: 8 bits
    printf("Output: ");
    for (i = 0 ; i < N ; i++) 
    {
        printf("%d", barcode[i]);
    }

    printf("\n");

    return(0);
}

/* The edge function takes an array of bits, byte1, and performs XOR between 
   consecutive bits and stores the result in byte2. The first element of byte2
   is always a 0 
*/
void edge(int n, int *byte1, int *byte2)
{
    int *p, *q;
    q = &byte2[0];

    *q = 0;

    for (p = &byte1[0] ; p < &byte1[n-1] ; p++, q++)
    {
        *(q + 1) = *p ^ *(p + 1);
    }
}
