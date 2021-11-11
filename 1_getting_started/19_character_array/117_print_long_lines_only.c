#include <stdio.h>
#define MAXLINE 100
#define MINLEN 10

int getcurrline(char line[], int maxline);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = getcurrline(line, MAXLINE)) > 0)
    {
        if (len > MINLEN)
        {
            printf("---------------\n");
            printf("%s\n", line);
            printf("---------------\n");
        }
    }
    return 0;
}

int getcurrline(char line[], int maxline)
{
    int c, i;
    for (i = 0; ((c = getchar()) != EOF) && c != '\n'; ++i)
    {
        if (i < maxline - 1)
            line[i] = c;
    }
    if (c == '\n')
    {
        if (i < maxline - 1)
            line[i] = c;
        ++i;
    }
    if (i < maxline)
        line[i] = '\0';
    else
        line[maxline - 1] = '\0';
    return i;
}
