#include <stdio.h>
#define MAXLINE 1000
#define linesize 12

int getcurrline(char line[], int maxline);
void divide(char line[], char dividedline[], int len);

int main(void)
{
    int len, newlen;

    char line[MAXLINE];
    char dividedline[MAXLINE];

    while ((len = getcurrline(line, MAXLINE)) > 0)
    {
        divide(line, dividedline, len);
        printf("%s", dividedline);
    }
    return 0;
}

void divide(char line[], char dividedline[], int len)
{
    int i, j, n, lastblank, stop, prev_limit, next_limit, extracarac;
    ;
    for (i = 0; i < MAXLINE; ++i)
    {
        dividedline[i] = '\0';
    }

    lastblank = 0;
    extracarac = 0;
    j = 0;
    n = 0;
    stop = 0;
    prev_limit = 0;
    next_limit = linesize;
    while (stop == 0)
    {
        for (i = prev_limit; i < next_limit && i- extracarac < len; ++i)
        {
            dividedline[i] = line[i- extracarac];
            if (line[i- extracarac] == ' ')
            {
                lastblank = i ;
            }

            if (i == len - 1)
            {
                stop = 1;
            }
        }
        if (stop == 0)
        {
            if (lastblank > prev_limit)
            {
                dividedline[lastblank] = '\n';
                prev_limit = lastblank + 1;
                next_limit = prev_limit + linesize;
            } else {
                lastblank = next_limit - 2;
                dividedline[lastblank] = '-';
                dividedline[lastblank +1] = '\n';
                prev_limit = lastblank + 2;
                next_limit = prev_limit + linesize;
                extracarac = extracarac +2;
        
            }
        }
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
