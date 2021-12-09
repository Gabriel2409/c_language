#include <stdio.h>

/* returns index of t in s, -1 if none */
int rightstrindex(char s[], char t[])
{
    int i, j, k;
    int matched = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            matched = i;
    }
    return matched;
}

int main(void)
{
    char s[100] = "Je ne sais pas";
    int lim = 100;
    char pattern[50] = "AA";

    printf("%d\n", rightstrindex(s, pattern));

    return 0;
}