
#ifndef _NEXT_DATE_H_
#define _NEXT_DATE_H_

#include <time.h>

/**
 * @brief           calculates the next date
 * @param[in] struct tm  Date.
 * @return          Next date.
 */
struct tm get_next_day_date(struct tm date);

/**
 * @brief           Prints the next date
 * @param[in] struct tm  Date.
 */
void print_next_day(struct tm date);

#endif