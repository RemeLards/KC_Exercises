#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int mygetline(char line[]);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = mygetline(line)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }

    if (max > MAXLINE-2) /* if the input line is bigger than the limit of words shown */
        printf("Size : %d \n Line: %s",max, longest);
    else
        if(max > 0)
            printf("%s", longest);
    
    /* just to "freeze" the program, so its possible to see the print */ 
    getchar();

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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}