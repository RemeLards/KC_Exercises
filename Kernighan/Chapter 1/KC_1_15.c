#include <stdio.h>

#define UPPERLIM 300 /* upper temperature limit */
#define LOWERLIM 0 /* lower temperature limit */
#define STEP 20 /* increment in temperature */

/* Fahrenheit-Celsius conversion */
float Fahrenheit_to_Celsius(int fahr);

main()
{
    int fahr;

    printf("Fahrenheit:\t\tCelsius:\n");

    for(fahr = LOWERLIM; fahr <= UPPERLIM; fahr = fahr + STEP)
        printf("\t%4d\t\t%6.2f\n", fahr, Fahrenheit_to_Celsius(fahr));
    
    return 0;
}

float Fahrenheit_to_Celsius(int fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}