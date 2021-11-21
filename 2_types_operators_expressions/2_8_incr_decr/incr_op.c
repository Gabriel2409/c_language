#include <stdio.h>

void squeeze(char st[], int c);

int main(void)
{
    char s[6] = "azert";

    int j = 2;

    s[j++] = '!'; // assigns s[j] then increments j

    printf("%s\n", s);
    printf("%d\n", j);

    int k = 0;
    s[++k] = '?'; // increments k then assigns s[k]
    printf("%s\n", s);
    printf("%d\n", k);

    char sup[15] = "Je ne peux";
    squeeze(sup, 'e');
    printf("%s\n", sup);
}

void squeeze(char st[], int c)
{
    int i, j;
    for (i = j = 0; st[i] != '\0'; i++)
    {
        if (st[i] != c)
        {
            st[j++] = st[i];
        }
    }
    st[j] = '\0';
}