#include <stdio.h>

/* tab ('\t') work as follow -> |-------|-------|-------|-------| ... */
/* the tab goes to the next tabstop ( -> | ), so if there's a tab ('\t') after a tabstop, tab equals 8 blanks */
/* if there's 1 char and a tab ('\t') , tab equals 7 blanks, if there's 2 chars and a tab, tab equals 6 blanks, and so on */
#define TABSTOP 8 /* tabstop has a 8 char lenght */

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

distance_to_next_tab_stop(int num)
{
    while(num > 0)
        num = num - TABSTOP;
    return -num;
}
