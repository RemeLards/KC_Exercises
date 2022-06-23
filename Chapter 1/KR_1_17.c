#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define MINLEN 80 /* Minium Lenght to get printed */

int mygetline(char line[]);

main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = mygetline(line)) > 0)
        if (len > MINLEN)
            printf("\nLenght : %d\n Line: %s\n",len,line);
    
    return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[])
{
    int c, len, len_limit;

    /* "len_limit" let a max amount of 997 chars without counting '\n' and '\0' */
    /* "len" counts the size of the input string, and also clears the buffer, since count all the chars */
    
    for (len = 0; (c=getchar())!=EOF && c!='\n'; ++len)
    {
        if(len < MAXLINE-2)
        {
            s[len] = c;
            len_limit = len;
        }
    }
    
    /* if it's an empty line, "len_limit" isn't initialized */
    if(len > 0)
    {
        if (c == '\n')
        {
            ++len_limit;
            s[len_limit] = c;
            ++len_limit;
        }
        s[len_limit] = '\0';
    }

    return len;
}