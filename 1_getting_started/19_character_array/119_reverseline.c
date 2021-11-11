#include <stdio.h>
#define MAXLINE 100

int getcurrline(char line[], int maxline);
void reverseline(char line[], int len);

int main(void)
{
    int len, shortlen;

    char line[MAXLINE];

    while ((len = getcurrline(line, MAXLINE)) > 0)
    {
        reverseline(line, len);

        printf("%s", line);
    }
    return 0;
}

void reverseline(char line[], int len)
{
    char templine[len];
    int i;

    int endwithreturn = 0;
    if (line[len - 1] == '\n')
        endwithreturn = 1;

    for (i = 0; i < len - endwithreturn; i++)
    {
        templine[i] = line[len - 1 - endwithreturn - i];
    }

    for (i = 0; i < len - endwithreturn; i++)
    {
        line[i] = templine[i];
    }
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
