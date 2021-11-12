#include <stdio.h>
#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getcurrline(void);
void copy(void);

/* extern keyword with redeclaration is optional if the variable is declared in the same file
Usual practice is to collect extern declarations inside a header, which is why we have
#include <stdio.h>
I can modify variables from the outer scope inside a function */
int main(void)
{
    int len;
    // extern int max;
    // extern char longest[];

    max = 0;
    while ((len = getcurrline()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getcurrline(void)
{
    int c, i;
    // extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(void)
{
    int i;
    // extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}