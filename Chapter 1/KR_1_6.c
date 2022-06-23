#include <stdio.h>

main()
{
    int c;
    while(c = (getchar() != EOF))
        printf("%d",c);

    /* in this case, after the while the 'c' value is 0 */
    printf("%d",c);

    /* just to "freeze" the program, so its possible to see the value of 'c' after the while */ 
    getchar();
}