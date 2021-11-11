#include <stdio.h>
#define MAXLINE 100
#define MINLEN 10

int getcurrline(char line[], int maxline);
int remove_blank(char line[], int len);

int main(void)
{
    int len, shortlen;

    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getcurrline(line, MAXLINE)) > 0)
    {
        shortlen = remove_blank(line, len);
        if (shortlen == 0)
            printf("\nDeleted\n");
        else
            printf("%s", line);

        printf("Initial length : %d\t final length: %d\n", len, shortlen);
    }
    return 0;
}

int remove_blank(char line[], int len)
{
    int i = len - 1;

    int keepgoing = 1;
    int endwithreturn = 0;
    int endwitheof = 0;

    if (line[i] == '\n')
        endwithreturn = 1;
    --i;

    while (keepgoing == 1)
    {
        if (line[i] == ' ' || line[i] == '\t')
        {
            line[i] = '\0';
            --i;
        }
        else
        {
            keepgoing = 0;
        }
    }
    if (endwithreturn == 1)
    {
        line[i + 1] = '\n';
        i++;
    }

    return i + 1;
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
