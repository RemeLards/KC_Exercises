#include <stdio.h>

#define TABSTOP 8

/* if I'm not mistaken, K&R didn't introduced the '%' operator, so I made a function that does the same */
int distance_to_next_tab_stop(int num, int divisor);

main()
{
    int c,nc,TABSTOP_distance,i;

    TABSTOP_distance = nc = 0;

    while( (c = getchar()) != EOF)
    {
        
        if(c == '\t')
        {
            TABSTOP_distance = distance_to_next_tab_stop(nc,TABSTOP);

            /* if its a tab after a tabstop, then this "if" will execute this exclusive case */
            if(c == '\t' && TABSTOP_distance == 0)
                for(i = 0; i < TABSTOP; i++)
                {
                    putchar(' ');
                    ++nc;
                }    

            /* if "TABSTOP_distance" is 0, the above "if" execute the exclusive case */
            else
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

distance_to_next_tab_stop(int num, int divisor)
{
    while(num > 0)
        num = num - divisor;
    return -num;
}