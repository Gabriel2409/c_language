#include <stdio.h>

main()
{
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("CONVERSION TABLE : FARHENHEIT TO CELSIUS\n");
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr - 32);
        printf("%3d\t%6d\n", fahr, celsius);
        fahr = fahr + step;
    }
}