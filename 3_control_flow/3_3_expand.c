#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main(void)
{
    char s1[1000] = "-a-zA-Z0-9-";
    // char s1[1000] = "0-0-0-1-1-4-0-7";
    char s2[1000];
    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}

void expand(char s1[], char s2[])
{

    int i;
    int j = 0;
    int k;
    for (i = 0; s1[i] != '\0'; i++)
    {

        if (s1[i] == '-')
        {
            if (i == 0)
            {
                s2[j] = '-';
                j++;
            }
            else if (s1[i + 1] == '\0')
            {
                s2[j] = '-';
                j++;
            }
            else
            {

                if ((isdigit(s1[i - 1]) && isdigit(s1[i + 1])) || (islower(s1[i - 1]) && islower(s1[i + 1])) || (isupper(s1[i - 1]) && isupper(s1[i + 1])))
                {
                    if (s1[i - 1] > s1[i + 1])
                    {
                        s2[j] = '-';
                        s2[j + 1] = s1[i + 1];
                        j += 2;
                        i++;
                    }
                    else
                    {
                        for (k = 1; s1[i - 1] + k <= s1[i + 1]; k++)
                        {
                            s2[j] = s1[i - 1] + k;
                            j++;
                        }
                        i++;
                    }
                }
            }
        }
        else
        {
            s2[j] = s1[i];
            j++;
        }
        s2[j] = '\0';
    }
}
