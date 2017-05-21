/* Name: barcode.c
*  Description: Gets a binary string and finds its edges of dark and light regions
*  Student: Patricia Wilthew
*/
#include <stdio.h>
#include <stdlib.h>
#define N 8

void edge(int byte1[], int byte2[]);

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
    edge(byte, barcode);

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
void edge(int byte1[], int byte2[])
{
    int i;
    byte2[0] = 0; 
    
    for (i = 0 ; i < N-1 ; i++)
    {
        byte2[i+1] = byte1[i] ^ byte1[i+1];
    }
}
