#include <stdio.h>

main()
{

    char c;
    char lastchar = ' ';
    int nbwords = 0;

    while ((c = getchar()) != EOF)
    {
        if ((c == '\t' || c == '\n' || c == ' ') && (lastchar != '\t' && lastchar != '\n' && lastchar != ' '))
        {
            ++nbwords;
            putchar('\n');
        } else{
            putchar(c);
        }

        lastchar = c;
    }

    if (lastchar != '\t' && lastchar != '\n' && lastchar != ' ')
        ++nbwords;

    printf("Nb of words is %d\n", nbwords);
}