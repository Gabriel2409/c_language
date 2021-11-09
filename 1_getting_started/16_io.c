#include <stdio.h>

main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        // putchar(c);

        printf("%d\t", c);
        printf("%d\n", c != EOF);
    }
    printf("EOF\t"); // CTRl+d to do EOF
    printf("%d\t", c != EOF);
    printf("%d", c);
}