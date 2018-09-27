#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tm get_next_day_date(struct tm date)
{
    date.tm_mday += 1;
    mktime(&date);
    return date;
}

void print_next_day(struct tm date)
{
    printf("Next Day:\t\t\t%02d.%02d.%d\n", date.tm_mday, date.tm_mon + 1,
        date.tm_year + 1900);
}