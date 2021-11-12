#include <stdio.h>
#define MAXLINE 100
#define tabsize 4

int getcurrline(char line[], int maxline);
int detab(char line[], char newline[], int len);

int main(void)
{
    int len, newlen;

    char line[MAXLINE];
    char newline[MAXLINE];

    while ((len = getcurrline(line, MAXLINE)) > 0)
    {
        newlen = detab(line, newline, len);
        printf("------------------------------\n");
        
        printf("%s", line);
        printf("%s", newline);

        printf("Initial length : %d\t final length: %d\n", len, newlen);
        printf("------------------------------\n");

    }
    return 0;
}

int detab(char line[], char newline[], int len)
{
    int j = 0;
    int n;

    for (int i = 0; i < len; i++)
    {
        if (line[i] == '\t')
        {
            for (n = 0; n < tabsize; n++)
            {
                newline[j + n] = '_';
            }
            j = j + n;
        }
        else
        {
            newline[j] = line[i];
        }
        j++;
    }

    return j;
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
