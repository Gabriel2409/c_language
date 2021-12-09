#include <stdio.h>
/* get line into s, return length */
int getcurrentline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* returns index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int main(void)
{
    char s[100];
    int lim = 100;
    char pattern[50] = "comb";
    int found = 0;
    while (getcurrentline(s, lim) > 0)
    {
        if (strindex(s, pattern) >= 0)
        {
            printf("%s", s);
            found++;
        }
    }
    return found;
}