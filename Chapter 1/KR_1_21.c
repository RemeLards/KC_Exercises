#include <stdio.h>

/* tab ('\t') work as follow -> |-------|-------|-------|-------| ... */
/* the tab goes to the next tabstop ( -> | ), so if there's a tab ('\t') after a tabstop, tab equals 8 blanks */
/* if there's 1 char and a tab ('\t') , tab equals 7 blanks, if there's 2 chars and a tab, tab equals 6 blanks, and so on */
#define TABSTOP 8 /* tabstop has a 8 char lenght */

int distance_to_next_tab_stop(int num);

main()
{
    int c,i;
    int nc, nb; /* 'n' numbers,'c' means char, 'b' means blanks */

    i = nc = nb = 0;

    while ( (c = getchar()) != EOF )
    {
        if(c == ' ')
        {
            ++nb;
            if(distance_to_next_tab_stop(nc) == nb)
            {
                putchar('\t');
                
                nc = nc + nb;
                nb = 0;
            }
        }
        
        /* if there's blanks remaining before a char */
        else if(nb > 0)
        {
            /* printing blanks remaining */
            for(i = 0; i < nb; ++i)
                putchar(' ');

            nc = nc + nb;
            nb = 0;

            putchar(c);

            /* checking the char */
            if(c == '\t')
                nc = nc + distance_to_next_tab_stop(nc);
            else if(c == '\n')
                nc = 0;
            else 
                ++nc;
        }
        /* if there isn't blanks remaining before a char */
        else
        {
            putchar(c);
            
            /* checking the char */
            if(c == '\t')
                nc = nc + distance_to_next_tab_stop(nc);
            else if(c == '\n')
                nc = 0;
            else 
                ++nc;
        }
    }
    return 0;
}

/* calculates the amount of chars needed to reach the next tabstop */
/* K&R didn't show '%' operator, so I did this function */
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
