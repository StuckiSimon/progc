#include "countWords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *str)
{
    char *part;
    int count = 0;
    char delimiters[] = " \t\n";

    part = strtok(str, delimiters);
    while (part != NULL) {
        count++;
        // pass NULL because strtok saved a pointer to the string internally
        part = strtok(NULL, delimiters);
    }
    return count;
}