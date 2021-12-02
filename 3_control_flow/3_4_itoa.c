#include <limits.h>
#include <stdio.h>
#include <string.h>
void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    printf("Min value signed int: %d\n", INT_MIN); // -2147483648
    printf("Max value signed int: %d\n", INT_MAX); // 2147483647

    char s[100];
    int myint = INT_MIN;
    itoa(myint, s);
    printf("%s\n", s);

    // - INT_MIn causes integer overflow !
}

void reverse(char s[])
{
    int i, j, c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;
    int extra = 0;
    if (n == INT_MIN)
    {
        n++;

        extra = 1;
    }

    if ((sign = n) < 0)
        n = -n; // records sign and make n positive

    i = 0;
    do
    {

        s[i] = n % 10 + '0';
        // handles cas if for an alien reason, the minimum allowed int ends with a 0
        if (extra && s[i] != '9')
        {
            s[i] = s[i] + 1;
            extra = 0;
        }
        else if (extra && s[i] == '9')
        {
            s[i] = '0';
        }
        i++;
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}