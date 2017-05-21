/* Name: cents.c
 * Description: Asks a user to enter a number of cents and outputs the number
 * of quarters, dimes, nickels, and pennies needed to add up to that amount of
 * cents.
 * Student: Patricia Wilthew
 */
#include <stdio.h>
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

void coins(int cents, int *quarters, int *dimes, int *nickels, int *pennies);

int main()
{
	//initialize variables and read input
	int cents, pennies, quarters, dimes, nickels;
	pennies = quarters = dimes = nickels = 0;

    printf("Enter the number of cents:\n");
	scanf("%d", &cents);

	//check the range of the input amount
	if(cents< 0 || cents > 10000)
        printf("Invalid amount %d,\nAmount must be between 0 and 10000, inclusive\n", cents);
    else {
            coins(cents, &quarters, &dimes, &nickels, &pennies);	
	        
	        printf("Quarters: %d\n", quarters);
	        printf("Dimes: %d\n", dimes);
        	printf("Nickels: %d\n", nickels);
	        printf("Pennies: %d\n", pennies);
	}
	return 0;
}

/* Function: coins
 * Description: Takes the integer 'cents' and 4 integer pointers and modifies the content
 * of the pointers so that they contain the amount of quartes, dimes, nickels, and pennies
 * in that amount of cents.
 */
void coins(int cents, int *quarters, int *dimes, int *nickels, int *pennies) {

    	*quarters = cents/QUARTER;
		*dimes = cents%QUARTER/DIME;
		*nickels = cents%QUARTER%DIME/NICKEL;
		*pennies = cents%QUARTER%DIME%NICKEL;

}
