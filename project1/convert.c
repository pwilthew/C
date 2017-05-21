/*  Name: convert.c
 *  Description: Allows a user to convert miles to kilometers and vice versa, 
 *  and inches to centimeters and vice versa.
 *  Student: Patricia Wilthew
 */
#include <stdio.h>
#define MILES_TO_KM_FACTOR 1.6093
#define KM_TO_MILES_FACTOR 0.6214
#define INCHES_TO_CM 2.54
#define CM_TO_INCHES 0.3937

int main()
{
    int option;
    float input;
    float output;

    printf("Please select one of the following operations:\n");
    printf("1 - Miles to Kilometers\n");
    printf("2 - Kilometers to Miles\n");
    printf("3 - Inches to Centimeters\n");
    printf("4 - Centimeters to Inches\n");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("Enter the number of miles:\n");
            scanf("%f", &input);
            output = input * MILES_TO_KM_FACTOR;
            printf("%.2f miles = %.2f kilometers\n", input, output);
            break;

        case 2:
            printf("Enter the number of kilometers:\n");
            scanf("%f", &input);
            output = input * KM_TO_MILES_FACTOR;
            printf("%.2f kilometers = %.2f miles\n", input, output);
            break;

        case 3:
            printf("Enter the number of inches:\n");
            scanf("%f", &input);
            output = input * INCHES_TO_CM;
            printf("%.2f inches = %.2f centimeters\n", input, output);
            break;

        case 4:
            printf("Enter the number of centimeters:\n");
            scanf("%f", &input);
            output = input * CM_TO_INCHES;
            printf("%.2f centimeters = %.2f inches\n", input, output);
            break;

        default:
            printf("Invalid input, please select between 1 and 4\n");
    }
    return(1);
}
