#include <stdio.h>
#define MAXLINE 10

int getcurrline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = getcurrline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("Max line is %d characters long\n---------\n", max);
        printf("%s\n", longest);
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
        line[maxline -1] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}