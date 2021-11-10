#include <stdio.h>

main()
{
#define BUFFER 1000

    int c, i;
    int maxval = 0;
    int nchar[BUFFER];

    for (i = 0; i < BUFFER; i++)
    {
        nchar[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        ++nchar[c];
        if (nchar[c] > maxval)
        {
            maxval = nchar[c];
        }
    }
    printf("\n\n");

    /* Horizontal version histogram */
    for (i = 0; i < BUFFER; i++)
    {
        if (nchar[i] > 0)
        {

            if (i == '\n')
            {
                printf("\\n ");
            }
            else if (i == '\t')
            {
                printf("\\t ");
            }

            else
            {
                printf("%c  ", i);
            }
            for (int ii = 0; ii < nchar[i]; ++ii)
                printf("#");
            printf("\n");
        }
    }
    printf("------------------------------\n");

    /* Vertical version histogram */
    for (int j = 0; j < maxval; j++)
    {
        for (i = 0; i < BUFFER; i++)
        {
            if (nchar[i] > 0)
            {
                if (nchar[i] >= maxval - j)
                {
                    printf("#  ");
                }
                else
                {
                    printf("   ");
                }
            }
        }
        printf("\n");
    }

    for (i = 0; i < BUFFER; i++)
    {
        if (nchar[i] > 0)
        {

            if (i == '\n')
            {
                printf("\\n ");
            }
            else if (i == '\t')
            {
                printf("\\t ");
            }

            else
            {
                printf("%c  ", i);
            }
        }
    }
}