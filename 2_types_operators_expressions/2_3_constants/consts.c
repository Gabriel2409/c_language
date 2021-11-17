#include <string.h>
#include <stdio.h>

int main(void)
{
    printf("%zx\n", strlen("12sgfsg"));
    enum months
    {
        JAN = 1,
        FEB,
        MAR
    };
    enum bools
    {
        F,
        T
    };
    printf("%d\n", F);
    printf("%d\n", T);
    printf("%d\n", JAN);
    printf("%d\n", MAR);
}