/* -----------------------
 ____  _  _   __   _  _
(__  )/ )( \ / _\ / )( \
 / _/ ) __ (/    \\ /\ /
(____)\_)(_/\_/\_/(_/\_)
-------------------------- */
/**
 * @file
 * @brief Prints the amount of words and characters of the user input
 */
#include "countWords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 256

static char *readAndParseInput(char *text)
{
    fgets(text, MAX_STRING_SIZE, stdin);
    if ((strnlen(text, MAX_STRING_SIZE) > 0) && (text[strnlen(text, MAX_STRING_SIZE) - 1] == '\n'))
        text[strnlen(text, MAX_STRING_SIZE) - 1] = '\0';

    return text;
}

/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 */
int main(void)
{
    int word_count = 0;
    int char_count = 0;
    char *text = malloc(MAX_STRING_SIZE);

    if (text == NULL) {
      return EXIT_FAILURE;
    }

    text = readAndParseInput(text);

    char_count = strnlen(text, MAX_STRING_SIZE);

    word_count = count_words(text);

    (void)printf("Anzahl Zeichen:\t%3d\n", char_count);
    (void)printf("Anzahl Wörter:\t%3d\n", word_count);

    return EXIT_SUCCESS;
}
