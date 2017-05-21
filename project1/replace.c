/* Name: replace.c
*  Description: Gets a three digit number from the user and replace 
*  each digit by the sum of that digit plus 6 modulus 10
*  Student: Patricia Wilthew
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int user_input = 0;
    int current_digit =0;
    int replace_digit = 0;
    int program_output = 0;
    int i = 0;
    int multiplier = 1;

    //Ask user for input
    printf("Enter a three-digit number: ");
    scanf("%d", &user_input);
    
    //Exit the program if the input is not valid
    if (100 > user_input || user_input > 999)
    {
        printf("Invalid input, the number must be between 100 and 999\n");
        exit(0);
    }

    //Loop to obtain the replacement digit for each digit and create the new three-digit integer
    while (i < 3) 
    {
        current_digit = user_input % 10; //With modulus 10, we obtain the last digit of a number
        replace_digit = (current_digit + 6) % 10; //Calculation to obtain the new digit
        
        user_input = (user_input - current_digit) / 10; //Operation to reduce checked digit.
                                                     //Example: If userInput was '345', and 5 was checked, userInput will contain '34'
        
        program_output = program_output + (replace_digit * multiplier); //Operation to build new number with every new digit
        
        multiplier = multiplier * 10;
        i = i + 1;
    }

    printf("Output: %d\n", program_output);
    return(program_output);
}
