#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define MINLEN 80 /* Minium Lenght to get printed */

int mygetline(char line[]);
void remove_blanks_tabs(char str[], int lenght);

main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = mygetline(line)) > 0)
    {
        remove_blanks_tabs(line,len);
        printf("Line: %s", line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[])
{
    int c, len;

    /* "len_limit" let a max amount of 997 chars without counting '\n' and '\0' */
    /* "len" counts the size of the input string, and also clears the buffer, since count all the chars */
    
    for (len = 0; len < MAXLINE-2 && (c=getchar())!=EOF && c!='\n'; ++len)
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

void remove_blanks_tabs(char str[], int lenght)
{
    int i,j;
    char without_spaces[MAXLINE];
    
    /* removes trailing blanks/tabs */
    while(str[lenght-1] == '\t' || str[lenght-1] == ' '|| str[lenght-1] == '\n')
        --lenght;
    
    ++lenght;
    str[lenght] = '\n';

    ++lenght;
    str[lenght] = '\0';


    /* removes entire blank lines */
    for(i = j = 0; i <= lenght; i++)
    {
        if(str[i] != '\0')
            if(str[i] == ' ' && str[i+1] == ' ')
                ;
            else
            {
                without_spaces[j] = str[i];
                ++j;
            }
        else
            without_spaces[j] = str[i];
    }
    
    /* copies string without entire blank lines to "str" */
    for(i = 0; i <= j; i++)
        str[i] = without_spaces[i];
}