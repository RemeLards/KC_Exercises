#include <stdio.h> 

#define TABSTOP 8
#define LINELEN 40

int distance_to_next_tab_stop(int num);

main()
{
    int c,i;
    int nc,pos;
    char str[LINELEN + 1]; /* current input line */

    nc = pos = 0;

    while ( (c = getchar()) != EOF)
    {
        if(c != '\t' && c != '\n')
        {
            /* removing spaces before the first char in the line */
            if(pos == 0 && c == ' ')
                ++nc;
            else
            {
                str[pos] = c;
                ++pos;
                ++nc;
            } 
        }

        else if(c == '\t')
        {
            /* removing tabs before the first char in the line */
            if(pos == 0)
                nc = nc + distance_to_next_tab_stop(nc) ;

            /* if isn't the first char and isn't beyond the limit */
            else if(pos + distance_to_next_tab_stop(nc) < LINELEN)
            {
                for(i = 0; i < distance_to_next_tab_stop(nc); i++)
                {
                    str[pos + i] = ' ';
                }
                /* increase the "position" and "number of characters" */
                pos = pos + distance_to_next_tab_stop(nc);
                nc = nc + distance_to_next_tab_stop(nc); 
            }
            /* if isn't the first char and if the tabstop its beyond or equal to the "LINELEN" limit */
            else
            {
                for(i = pos; i < LINELEN ; i++)
                {
                    str[i] = ' ';
                    ++nc;
                }
                
                /* terminates the line */
                str[LINELEN] = '\0';
                printf("%s\n",str);
                pos = 0;
            }
        }

        /* terminates the line and splits it */
        else
        {
            str[pos] = '\0';
            printf("%s\n",str);
            pos = 0;
            nc = 0;
        }
        
        /* checks if the line will be splitted */
        if(pos == LINELEN)
        {
            str[pos] = '\0';
            printf("%s\n",str);
            pos = 0;
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