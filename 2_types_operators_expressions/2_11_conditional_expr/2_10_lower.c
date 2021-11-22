#include <stdio.h>

char lower(char c);

int main(void)
{
    char c = 'A';
    char c2 = 'e';

    printf("%c\n", lower(c));
    printf("%c\n", lower(c2));
}

char lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}