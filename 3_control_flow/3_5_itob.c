#include <limits.h>
#include <stdio.h>
#include <string.h>
void itob(int n, char s[], int b, int minwidth);
void reverse(char s[]);

int main(void)
{

    printf("Min value signed int: %d\n", INT_MIN); // -2147483648
    printf("Max value signed int: %d\n", INT_MAX); // 2147483647

    int b = 16;
    char s[100];
    int myint = 255;
    int minwidth = 4;
    itob(myint, s, b, minwidth);
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

void itob(int n, char s[], int b, int minwidth)
{
    int i, sign;
    int extra = 0;
    int lastcharac;

    if (b < 10)
        lastcharac = '0' + b;
    else
        lastcharac = b - 10 + 'A';
    if (n == INT_MIN)
    {
        n++;

        extra = 1;
    }

    if ((sign = n) < 0){
        n = -n; // records sign and make n positive
        minwidth--;
    }

    i = 0;
    do
    {

        s[i] = n % b;

        if (s[i] >= 10)
            s[i] = s[i] - 10 + 'A';
        else
            s[i] = s[i] + '0';
        // handles cas if for an alien reason, the minimum allowed int ends with a 0
        if (extra && s[i] != lastcharac)
        {
            if (s[i] == 9)
                s[i] == 'A';
            else
                s[i] = s[i] + 1;
            extra = 0;
        }
        else if (extra && s[i] == lastcharac)
        {
            s[i] = '0';
        }
        i++;
    } while ((n /= b) > 0);


    while (i < minwidth)
        s[i++] = '0';

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}