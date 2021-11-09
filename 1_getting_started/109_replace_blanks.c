#include <stdio.h>

main()
{

    char lastchar;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || lastchar != ' ')
        {
            putchar(c);
        }
        lastchar = c;
    }
}