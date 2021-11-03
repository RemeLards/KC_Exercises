#include <stdio.h>

main()
{
    int c,lastc;
    lastc = 0;

    while( (c = getchar()) != EOF)
    {
        if(lastc == ' ' && c == ' ');
        else putchar(c);
        
        lastc = c;
    }
}