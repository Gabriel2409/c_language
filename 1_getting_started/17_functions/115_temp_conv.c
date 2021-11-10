#include <stdio.h>

//no need for prototype as it is defined before main

/**
 * Converts fahrenheit to celsius
 * @param fahr the temperature in farenheit
 * @return the temp in celsius
 */
float convert_fahr_to_celsius(float fahr)
{
    float celsius = (5.0 / 9.0) * (fahr - 32);
    return celsius;
}

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("CONVERSION TABLE : FARENHEIT TO CELSIUS\n");
    while (fahr <= upper)
    {
        celsius = convert_fahr_to_celsius(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
