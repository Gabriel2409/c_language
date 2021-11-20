#include <stdio.h>

int main(void)
{
    int lim = 1000;
    char s[lim];
    int c, i;

    // for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    for (i = 0; (i < lim - 1) == ((c = getchar()) != '\n') == (c != EOF) == 1; ++i)
    {
        s[i] = c;
    }
    printf("%s\n", s);
}