#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXWORDS 100 /* max ammount of words to print the histogram */

/* the first word with lenght != 0 would enter in the "arraywordslen[1]" and not "arraywordslen[0], that's why the inital index value is -1" */
/* and when it indentifies a word it increments "i" by 1 */
/* the lenght of the first word is saved after reaching the second word, the lenght of the second after reaching the third word, and so on */
/* or if the last char is a '\n' he saves the lenght of the last word written correctly */
#define INDEX_VALUE -1 

main()
{
    int c,state,i,wordlen,maxlen;
    int arraywordslen[MAXWORDS];

    for(i = 0; i < MAXWORDS; i++)
        arraywordslen[i] = 0;
    
    maxlen = wordlen = state = OUT;

    i = INDEX_VALUE;

    while( (c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            if(c == '\n')arraywordslen[i] = wordlen;
        }
        else if(state == OUT)
        {
            if(i >= 0)arraywordslen[i] = wordlen;
            if(wordlen > maxlen)maxlen = wordlen;
            
            state = IN;
            wordlen = 0;

            ++wordlen;
            ++i;
        }
        else ++wordlen;
    }

    /* if there's a '\n' and a 'EOF', it will save the wordlen twice in the same index */
    /* but if the files end and there isn't a '\n' this conditional save the last lenght properly */
    if(c == EOF)arraywordslen[i] = wordlen;
    
    int j,k;
    for(j = maxlen; j > 0; j--)
    {
        for(k = 0; k <= i; k++)
        {
            if(arraywordslen[k] >= j)
                putchar('*');
            else
                putchar(' ');
            
            putchar(' ');
        }
        putchar('\n');
    }

    /* just to "freeze" the program, so its possible to see the print */ 
    getchar();
}