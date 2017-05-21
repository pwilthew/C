/* Name: sets.c
*  Description: Gets two sets of numbers and returns their intersection and union
*  Student: Patricia Wilthew
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    int sizeA, sizeB, i, num;
    
    //Binary arrays are initialized with zeros 
    int setA[N] = { 0 }, setB[N] = { 0 };

    //Get user input for set A
    printf("Please enter the number of elements in set A:\n");
    scanf("%d", &sizeA);

    printf("Enter the numbers in set A:\n");
    for (i = 0 ; i < sizeA ; i++)
    {
        scanf("%d", &num);
        setA[num] = 1;
    }

    //Get user input for set B
    printf("Please enter the number of elements in set B:\n");
    scanf("%d", &sizeB);

    printf("Enter the numbers in set B:\n");
    for (i = 0 ; i < sizeB ; i++)
    {
        scanf("%d", &num);
        setB[num] = 1;
    }

    
    printf("Output:\n");


    //Perform union
    printf("The union of set A and B is: ");
    for (i = 0 ; i < N ; i++)
    {
        if (setA[i] | setB[i]) {printf("%d ", i);}
    }

    //Perform intersection
    printf("\nThe intersection of set A and B is: ");
    for (i = 0 ; i < N ; i++)
    {
        if (setA[i] & setB[i]) {printf("%d ", i);}
    }
    

    printf("\n");
    return(0);
}
