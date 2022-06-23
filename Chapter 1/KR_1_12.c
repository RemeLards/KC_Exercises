#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

main()
{
    int c;
    int nw,nl,nc;
    int state;

    nw = nl = nc = 0;
    state = OUT;

    while( (c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            if(c == '\n')
                ++nl;
        }
        
        else if(state == OUT)
            {
                state = IN;
                ++nw;
                putchar('\n');
            }
        putchar(c);
        ++nc;
    }
    printf("Lines: %d  Words: %d  Chars: %d\n", nl, nw, nc);

    /* just to "freeze" the program, so its possible to see the print */ 
    getchar();
}
