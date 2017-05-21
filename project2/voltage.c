/* Name: voltage.c
 *  Description: Calculates and prints the voltages in time of an experiment 
 *  Student: Patricia Wilthew
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double time;
    double voltage;

    printf("Time\t\t Voltage\n");
    for (time = 0; time <= 12; time = time + 0.5) 
    {
        printf("%.2f\t\t", time);
        if (time < 1) 
        { 
            voltage = (0.5*sin(2*time));
        }
        else if (time >= 1.0 && time <= 10.0)
        {
            voltage = sin(time);
        }
        else if (time > 10)
        {
            voltage = sin(10);
        }
        printf("%.2f\n", voltage);

    }
    return(0);
}
