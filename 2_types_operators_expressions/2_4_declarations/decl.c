#include <stdio.h>

int doesnotmodifyarray(const char mychar[]); // indicates that function does not alter array

int main(void)
{
    const double e = 2.718;
    char mychar[] = "bonjour";
    // e = 54; /* throws an error */
    // printf("%f\n", e);

    doesnotmodifyarray(mychar);
    printf("%s\n", mychar);
}

int doesnotmodifyarray(const char mychar[])
{
    mychar[0] = '5'; // throws an error
}