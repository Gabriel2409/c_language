#include <stdio.h>

void squeeze(char s1[], const char s2[]);

int main(void)
{
#define MAXSIZE 100
    char s1[MAXSIZE] = "Je ne pense pas";
    char s2[MAXSIZE] = "peterparker";

    squeeze(s1, s2);

    printf("%s\n", s1);
}

void squeeze(char s1[], const char s2[])
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

        if (in ==0)
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}