#include <stdio.h>

main()
{
    int c;
    int bl,tabs,nl;
    bl = tabs = nl = 0;
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            bl = bl + 1;
        if(c == '\t')
            tabs = tabs + 1;
        if(c == '\n')
            nl = nl + 1;
    }
    printf("Blanks : %d   Tabs : %d  NewLines : %d",bl,tabs,nl);

    /* just to "freeze" the program, so its possible to see the print after the while */ 
    getchar();
}