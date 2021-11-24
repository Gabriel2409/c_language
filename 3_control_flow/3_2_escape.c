#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void)
{
    char s[1000] = "Je ne \nsais \tpas";
    char t[1000];
    char u[1000] = "Je ne \\nsais \\a \\tpas";
    ;
    char v[1000];
    escape(s, t);
    printf("%s\n", s);
    printf("%s\n", t);

    unescape(u, v);
    printf("%s\n", u);
    printf("%s\n", v);
}

void escape(char s[], char t[])
{
    int i;
    int j;

    for (i = j = 0; s[i] != '\0'; i++, j++)
    {
        switch (s[i])
        {
        case '\n':
            t[j] = '\\';
            t[++j] = 'n';
            break;
        case '\t':
            t[j] = '\\';
            t[++j] = 't';
            break;
        default:
            t[j] = s[i];
        }
    }
    t[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i;
    int j;

    for (i = j = 0; s[i] != '\0'; i++, j++)
    {
        switch (s[i])
        {
        case '\\':
            switch (s[++i])
            {
            case 'n':
                t[j] = '\n';
                break;
            case 't':
                t[j] = '\t';
                break;
            default:
                t[j] = '\\';
                --i;
            }
            break;
        default:
            t[j] = s[i];
            break;
        }
    }
    t[j] = '\0';
}