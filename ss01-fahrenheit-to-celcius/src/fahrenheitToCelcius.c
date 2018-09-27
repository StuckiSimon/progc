#include "fahrenheitToCelcius.h"
#include <stdio.h>
#include <stdlib.h>

double fahrenheitToCelcius(const int fahrenheit)
{
    return (5 * (fahrenheit - 32)) / 9.0;
}

void printTemparatureTable(const int MIN, const int MAX, const int STEP)
{
    printf("Fahrenheit\tCelcius\n");
    printf("-----------------------\n");
    for (int i = MIN; i <= MAX; i += STEP) {
        printf("%4d\t\t%7.2f\n", i, fahrenheitToCelcius(i));
    }
}