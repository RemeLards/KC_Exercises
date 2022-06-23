#include <stdio.h>

#define ASCII_CHARS 256 /* quantity of chars in ASCII table */

main()
{
    int c,i,j;
    int vector_char[ASCII_CHARS];

    for(i = 0; i < ASCII_CHARS; i++)vector_char[i] = 0;

    while( (c = getchar()) != EOF)vector_char[c]++;

    for(i = 0; i < ASCII_CHARS; i++)
    {
        putchar(i);
        printf(" :");
        for(j = 0; j < vector_char[i]; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }

    /* just to "freeze" the program, so its possible to see the print */ 
    getchar();

}