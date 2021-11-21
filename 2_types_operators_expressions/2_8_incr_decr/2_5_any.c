#include <stdio.h>
#include <string.h>

int any(const char s1[], const char s2[]);

int main(void)
{
#define MAXSIZE 100
    char s1[MAXSIZE] = "Je ne pense pas";
    char s2[MAXSIZE] = "zpe";

    printf("%d\n", any(s1, s2));

    char *p = strpbrk(s1, s2);

    if (p != 0)
        printf("First matching character: %c\n", *p);
    else
        printf("Character not found\n");
}

int any(const char s1[], const char s2[])
{

    int i, j, k, in;
    for (i = j = 0; s1[i] != '\0'; i++)
    {
        in = 0;
        for (k = 0; s2[k] != '\0' && in == 0; k++)
        {
            if (s1[i] == s2[k])
            {
                in = 1;
            }
        }

        if (in != 0)
        {
            return i;
        }
    }
    return -1;
}