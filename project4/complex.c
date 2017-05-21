/* Name: complex.c
 * Description: This program adds, subtracts, or multiplies complex numbers
 * Student: Patricia Wilthew
 */
#include <stdio.h>
void read_numbers(double *r1, double *i1, double *r2, double *i2);
void add(double r1, double i1, double r2, double i2, double *r3, double *i3);
void subtract(double r1, double i1, double r2, double i2, double *r3, double *i3);
void multiply(double r1, double i1, double r2, double i2, double *r3, double *i3);
void print_complex(double r3, double i3); 

int main(void)
{
	double r1, r2, r3, i1, i2, i3;
	int option;
	
	printf("Complex Number Arithmetic Program: \n\n");
	for(;;)
	{
		printf("1. Add two complex numbers\n");
		printf("2. Subtract two complex numbers\n");
		printf("3. Multiply two complex numbers\n");
		printf("4. Quit\n\n");

		printf("Choose an option (1 - 4): ");
		scanf("%d", &option);
		switch(option){
			case 1:
				read_numbers(&r1, &i1, &r2, &i2);
				add(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 2:
				read_numbers(&r1, &i1, &r2, &i2);
				subtract(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 3:
				read_numbers(&r1, &i1, &r2, &i2);
				multiply(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 4:
				return 0;
			default:
				printf("Invalid option. Choose an option (1-4):\n");

		}
	}

	return 0;
}

/* Function: read_numbers
 * Description: Reads 4 doubles from the keyboard and stores them in the pointers,
 * modifying their initial values.
 * *r1 and *i1 represent the first complex number read.
 * *r2 and *i2 represent the second complex number read.
 */
void read_numbers(double *r1, double *i1, double *r2, double *i2)
{
    printf("Enter the real component for the first number: ");
    scanf("%lf", &(*r1));
    printf("Enter the imaginary component for the first number: ");
    scanf("%lf", &(*i1));
    printf("Enter the real component for the second number: ");
    scanf("%lf", &(*r2));
    printf("Enter the imaginary component for the second number: ");
    scanf("%lf", &(*i2));
}

/* Function: add
 * Description: Reads the numbers from 4 variables, performs calulations, and stores
 * the results in 2 pointers, modifying their initial values.
 * r1 and i1 represent the first complex number operand.
 * r2 and i2 represent the second complex number operand.
 * *r3 and *i3 represent the complex number resulting from the addition of (r1,i1)+(r2,i2)
 */
void add(double r1, double i1, double r2, double i2, double *r3, double *i3)
{
    *r3 = r1 + r2;
    *i3 = i1 + i2;
}

/* Function: subtract
 * Description: Reads the numbers from 4 variables, performs calulations, and stores
 * the results in 2 pointers, modifying their initial values.
 * r1 and i1 represent the first complex number operand.
 * r2 and i2 represent the second complex number operand.
 * *r3 and *i3 represent the complex number resulting from the substraction of (r1,i1)-(r2,i2)
 */
void subtract(double r1, double i1, double r2, double i2, double *r3, double *i3)
{
    *r3 = r1 - r2;
    *i3 = i1 - i2;

}

/* Function: multiply
 * Description: Reads the numbers from 4 variables, performs calulations, and stores
 * the results in 2 pointers, modifying their initial values.
 * r1 and i1 represent the first complex number operand.
 * r2 and i2 represent the second complex number operand.
 * *r3 and *i3 conform the complex number resulting from the product of (r1,i1)*(r2,i2)
 */
void multiply(double r1, double i1, double r2, double i2, double *r3, double *i3)
{
	*r3 = (r1*r2) - (i1*i2);
	*i3 = (r1*i2) + (i1*r2);
}

/* Function: print_complex
 * Description: Reads the numbers from 2 pointers and prints them.i
 * r3 and i3 represent a complex number.
 */
void print_complex(double r3, double i3)
{
	if(i3 >= 0)
		printf("The operation yields %.3f + %.3fi\n\n", r3, i3);
	else
		
		printf("The operation yields %.3f  %.3fi\n\n", r3, i3);
}


