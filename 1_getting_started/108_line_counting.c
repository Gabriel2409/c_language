#include <stdio.h>

/* count blanks, tabls and newlines */
main()
{
    int c, nl, nt, nb;
    nl = 0;
    nt = 0;
    nb = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == '\t')
            ++nt;
        else if (c == ' ')
            ++nb;

    printf("Nb lines: %d\n", nl);
    printf("Nb tabs: %d\n", nt);
    printf("Nb blanks: %d\n", nb);
}