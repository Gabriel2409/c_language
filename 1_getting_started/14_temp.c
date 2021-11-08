#include <stdio.h>

main()
{
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("CONVERSION TABLE : CELSIUS TO FARENHEIT\n");
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr - 32);
        printf("%6d\t%3d\n",  celsius, fahr);
        fahr = fahr + step;
    }
    
}