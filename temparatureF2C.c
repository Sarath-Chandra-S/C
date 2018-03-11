// Program to convert Celsius to Fahrenheit

#include <stdio.h>

/* All Contstants */

#define UPPER_BOUND 300
#define LOWER_BOUND 0
#define STEP_VALUE 20

int main(void)
{
    float fahr, celsius;

    printf("Celsius\t\tFahrenheit\n");
    printf("-------\t\t----------\n");

    celsius = LOWER_BOUND;
    while(celsius <= UPPER_BOUND)
    {
        fahr = ((9.0 * celsius) / 5.0) + 32;
        printf("%5.0f\t\t%6.1f\n", celsius, fahr);
        celsius += STEP_VALUE;
    }

    return 0; // Success
}