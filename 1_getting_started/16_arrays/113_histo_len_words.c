#include <stdio.h>

main()
{
#define IN 1
#define OUT 0

    int c, i, nwhite, nother;
    int ndigit[15];
    int currentdigit;
    int len;
    int state;
    int maxval = 0;

    nwhite = nother = 0;
    for (i = 0; i < 15; i++)
    {
        ndigit[i] = 0;
    }

    state = OUT;
    len = 0;
    while ((c = getchar()) != EOF)
    {
        if (c != '\n' && c != ' ' && c != '\t')
        {
            if (state == OUT)
            {
                state = IN;
                len = 1;
            }
            else
            {
                ++len;
            }
        }
        else
        {
            if (state == IN)
            {
                state = OUT;
                ++ndigit[len];
                if (len > maxval)
                {
                    maxval = len;
                }
                len = 0;
            }
        }
    }

    if (state == IN)
    {
        ++ndigit[len];
        if (len > maxval)
        {
            maxval = len;
        }
    }
    printf("\n");

    /* Horizontal version histogram */
    for (i = 0; i < 15; i++)
    {
        for (int ii = 0; ii < ndigit[i]; ++ii)
            printf("#");
        printf("\n");
    }
        printf("------------------------------\n");

    /* Vertical version histogram */
    for (int j = 0; j < maxval; j++){
        for (i = 0; i < 15; i++){
            if (ndigit[i] >= maxval -j){
                printf("#");
            } else{
                printf(" ");
            }
        }
        printf("\n");
    }
}