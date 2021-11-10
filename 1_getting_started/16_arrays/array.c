#include <stdio.h>

main()
{
    int c, i, nwhite, nother;
    int ndigit[10];
    int currentdigit;
    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
    {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            currentdigit = c - '0'; // substract value of character 0
            ++ndigit[currentdigit];
        }
        else if (c == '\n' || c == ' ' || c == '\t')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d = %6d\n", i, ndigit[i]);
    }
    printf("whites = %d\nothers = %d\n", nwhite, nother);
}