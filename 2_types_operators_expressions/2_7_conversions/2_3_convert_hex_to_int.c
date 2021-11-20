#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(const char s[]);

int main(void)
{
    int c, i;
    char s[1000] = "0fff";
    // printf("%zx\n", strlen(s));
    printf("%d\n", htoi(s));
}

htoi(const char s[])
{

    int i;
    int total = 0;
    int multiplicand = 1;
    int val;
    size_t len = strlen(s);
    int stop = 0;

    if (len >= 2 && s[0] == '0' && tolower(s[1]) == 'x')
    {
        stop = 2;
    }

    for (i = (int)len - 1; i >= stop; --i)
    {

        printf("%c\n", s[i]);
        if (isdigit(s[i]))
        {
            val = s[i] - '0';
        }
        else
        {
            val = tolower(s[i]) - 'a' + 10;
        }

        total = total + multiplicand * val;
        multiplicand *= 16;
    }
    return total;
}