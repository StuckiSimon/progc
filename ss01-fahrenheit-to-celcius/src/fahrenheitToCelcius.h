#ifndef _FAHRENHEIT_TO_CELCIUS_H_
#define _FAHRENHEIT_TO_CELCIUS_H_

/**
 * @brief           Turns a fahrenheit value to a celcius value
 * @param[in] fahrenheit  Value in fahrenheit.
 * @return          Value in celcius.
 */
double fahrenheit_to_celcius(const int fahrenheit);

void print_temparature_table(const int min, const int max, const int step);

#endif