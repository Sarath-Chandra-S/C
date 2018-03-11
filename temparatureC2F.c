// Program to convert Fahrenheit to Celsius

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lowerBound, upperBound, stepValue;

    lowerBound = 0;
    upperBound = 300;
    stepValue = 20;

    printf("Fahrenheit\tCelsius\n");
    printf("----------\t-------\n");

    fahr = lowerBound;
    while(fahr <= upperBound)
    {
        celsius = (5.0 * (fahr - 32.0)) / 9.0;
        //printf("%d\t\t%d\n", fahr, celsius);
        // Adding the Width for the Statements. To Make Right Justification for the digits
        //printf("%5d\t\t%4d\n", fahr, celsius);
        // With Floats
        printf("%5.0f\t\t%6.1f\n", fahr, celsius);
        fahr += stepValue;
    }

    return 0; // Success
}