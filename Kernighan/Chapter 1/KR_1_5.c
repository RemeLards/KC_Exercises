#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
main()
{
    float fahr;
    float lower, upper, step;
    
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    printf("Fahrenheit:\t\tCelsius:\n");

    for(fahr = upper; fahr >= lower ; fahr = fahr - step)
        printf("\t%4.0f\t\t\t%6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
        /* the expression "(5.0/9.0) * (fahr-32.0)", corresponds to Celsius Degree */ 
}