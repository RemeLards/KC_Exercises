#include <stdio.h>

main()
{
    /* warning : unknown escape sequence: '\c' */
    /* in this case 'c' can be any char that with a '\' isn't a escape sequecence */
    printf("hello, world\c");

}