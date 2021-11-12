#include <stdio.h>
#define MAXLINE 100
#define tabsize 4

int getcurrline(char line[], int maxline);
int entab(char line[], char newline[], int len);

int main(void)
{
    int len, newlen;

    char line[MAXLINE];
    char newline[MAXLINE];

    while ((len = getcurrline(line, MAXLINE)) > 0)
    {
        newlen = entab(line, newline, len);
        printf("*******************\n");

        printf("%s", line);
        printf("%s", newline);

        printf("Initial length : %d\t final length: %d\n", len, newlen);
        printf("************************************\n");
    }
    return 0;
}

int entab(char line[], char newline[], int len)
{
    int i, k, l;
    int j = 0;
    int nb_tabs;
    int remaining_blanks;
    int consecutive_blanks;

    for (i = 0; i < MAXLINE; ++i)
    {
        newline[i] = '\0';
    }

    consecutive_blanks = 0;
    for (i = 0; i < len; ++i)
    {
        if (line[i] == ' ')
        {
            ++consecutive_blanks;
        }
        else
        {

            nb_tabs = consecutive_blanks / tabsize;
            remaining_blanks = consecutive_blanks % tabsize;
            for (k = 0; k < nb_tabs; k++)
            {
                newline[j] = '\t';
                ++j;
            }
            for (l = 0; l < remaining_blanks; l++)
            {
                newline[j] = ' ';
                ++j;
            }
            consecutive_blanks = 0;
            newline[j] = line[i];
            ++j;
        }
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
