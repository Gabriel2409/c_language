#include <ctype.h>
#include <stdio.h>
/* atof: converts string s to double  */

double satof(char s[])
{
    double val, power;
    int i, sign;
    int exp, expsign ;
    double expval;
    int j;
    for (i = 0; isspace(s[i]); i++)
        ; // skips first white spaces
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;

    expsign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (exp = 0; isdigit(s[i]); i++)
        exp = 10.0 * exp + (s[i] - '0');
    expval = 1;
    for (j = 0; j < exp; j++)
        expval *= 10;
    if (expsign == -1)
    {
        expval =  1.0 / expval;
    }

    return sign * val * expval / power;
}
int main(void)
{
    char s[100] = "15.786e-3";
    double num;
    num = satof(s);
    printf("%f\n", num);
}