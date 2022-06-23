#include <stdio.h>

#define TABSTOP 8

int distance_to_next_tab_stop(int num);

main()
{
    int c,nc,TABSTOP_distance,i;

    TABSTOP_distance = nc = 0;

    while( (c = getchar()) != EOF)
    {
        
        if(c == '\t')
        {
            TABSTOP_distance = distance_to_next_tab_stop(nc);
            
            for(i = 0; i < TABSTOP_distance; i++)
            {
                putchar(' ');
                ++nc;
            }    
        }
        else if(c == '\n')
            {
                putchar(c);
                nc = 0;   
            }
        else
        {
            putchar(c);
            ++nc;
        }
    }
    return 0;
}

/* calculates the amount of chars needed to reach the next tabstop */ 
int distance_to_next_tab_stop(int num)
{
    while(num > 0)
        num = num - TABSTOP;
    
    /* if "num = 0", this means the '\t' its after the Tabstop, so its value is equal to TABSTOP */
    if(num == 0)
        return TABSTOP;
    else
        return -num;
}