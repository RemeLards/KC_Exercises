#include <stdio.h>

main()
{
    int c,lastc;

    while( (c = getchar()) != EOF)
    {
        if(!(lastc == ' ' && c == ' '))putchar(c);
        lastc = c;
    }
}