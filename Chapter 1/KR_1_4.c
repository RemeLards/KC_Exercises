#include <stdio.h>
/* print Celsius-Fahrenheit table
for fahr = 0, 20, ..., 300 */
main()
{
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    printf("Celsius:\t\tFahrenheit:\n");

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0/5.0)  * celsius + 32;
        printf("%4.0f\t\t\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}