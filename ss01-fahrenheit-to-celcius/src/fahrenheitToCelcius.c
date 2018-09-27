#include "fahrenheitToCelcius.h"
#include <stdio.h>
#include <stdlib.h>

double fahrenheit_to_celcius(const int fahrenheit)
{
    return (5 * (fahrenheit - 32)) / 9.0;
}

void print_temparature_table(const int min, const int max, const int step)
{
    (void)printf("Fahrenheit\tCelcius\n");
    (void)printf("-----------------------\n");
    for (int i = min; i <= max; i += step) {
        (void)printf("%4d\t\t%7.2f\n", i, fahrenheit_to_celcius(i));
    }
}