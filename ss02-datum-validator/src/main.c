/* -----------------------
 ____  _  _   __   _  _
(__  )/ )( \ / _\ / )( \
 / _/ ) __ (/    \\ /\ /
(____)\_)(_/\_/\_/(_/\_)
-------------------------- */
/**
 * @file
 * @brief Returns the next day of the given date
 * converts user input to date (Format: dd.mm.YYYY)
 * and prints the next day
 */
#include "nextDate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 10 + 1

static char *read_input()
{
    (void)printf("Enter a date (dd.mm.yyyy):\t");
    char *text = malloc(MAX_STRING_SIZE * sizeof(const char));
    (void)fgets(text, MAX_STRING_SIZE, stdin);
    if ((strlen(text) > 0) && (text[strlen(text) - 1] == '\n'))
        text[strlen(text) - 1] = '\0';
    return text;
}

/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if unable to parse userinput to a date.
 */
int main(void)
{
    struct tm date = { 0 };
    char *input = read_input();

    // parse user input to date
    if (strptime(input, "%d.%m.%Y", &date) == NULL) {
        (void)printf("Cannot parse date\n");
        return EXIT_FAILURE;
    }
    date = get_next_day_date(date);
    (void)print_next_day(date);
    return EXIT_SUCCESS;
}
