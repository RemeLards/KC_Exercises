#include <stdio.h>

#define LENGHTLIM 1000 /* maximum input line length */


int mygetline(char line[]);
void print_reverse(char str[], int lenght);

main()
{
    int len; /* current line length */
    char line[LENGHTLIM]; /* current input line */

    while ((len = mygetline(line)) > 0)
    {
        print_reverse(line,len);
    }
    return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[])
{
    int c, len;

    /* "len_limit" let a max amount of 997 chars without counting '\n' and '\0' */
    /* "len" counts the size of the input string, and also clears the buffer, since count all the chars */
    
    for (len = 0; len < LENGHTLIM-2 && (c=getchar())!=EOF && c!='\n'; ++len)
        s[len] = c;
    
    /* if it's an empty line, "len_limit" isn't initialized */
    if(len > 0)
    {
        if (c == '\n')
        {
            s[len] = c;
            ++len;
        }
        s[len] = '\0';
    }

    return len;
}

/* prints a reverse string */
void print_reverse(char str[], int lenght)
{
    int i,j;
    char inverse[LENGHTLIM];

    j = 0;

    for(i = lenght; i >= 0; i--)
        if(str[i] != '\n' && str[i] != '\0')
        {
            inverse[j] = str[i];
            ++j;
        }
    
    inverse[j] = '\n';
    ++j;
    inverse[j] = '\0';
    
    printf("%s", inverse);
}