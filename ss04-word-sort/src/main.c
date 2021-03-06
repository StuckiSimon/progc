/* -----------------------
 ____  _  _   __   _  _
(__  )/ )( \ / _\ / )( \
 / _/ ) __ (/    \\ /\ /
(____)\_)(_/\_/\_/(_/\_)
-------------------------- */
/**
 * @file
 * @brief Sorts words from user input removing duplicates
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define S_(x) #x
#define S(x) S_(x)

const char END_WORD[] = "ZZZ";

// @brief compares two string based on their ASCII Value.
static int compare(const void * a, const void * b)
{
    return strncmp (*(const char **) a, *(const char **) b, MAX_WORD_SIZE);
}

// @brief dedupes words and prints the sorted list
// @attention This function depends on the fact that the list is already sorted!
static void print_deduped_word_list(char* words[MAX_WORD_COUNT], const int word_count)
{
  char* deduped[MAX_WORD_COUNT];
  int deduped_word_count = 0;
  for(int i = 0; i < word_count; i++) {
      // if the last word is not equal this one, add it to the new array
      if (i == 0 || strncmp(words[i-1], words[i], MAX_WORD_SIZE) != 0) {
          // store word in deduped array
          deduped[deduped_word_count] = words[i];
          deduped_word_count += 1;
      }
  }
  (void) printf("--------------\n");
  (void) printf("----Sorted----\n");
  (void) printf("--------------\n");
  for(int i = 0; i < deduped_word_count; i++) {
      (void) printf("%s\n", deduped[i]);
  }
  (void) printf("--------------\n");
}

static int check_pointer(char* pointer)
{
    int return_code = 0;
    if (pointer == NULL) {
        (void) printf("not enough memory\n");
        return_code = 1;
    }
    return return_code;
}

static int read_words(char* words[MAX_WORD_COUNT], int *word_count)
{
    (void) printf("Geben Sie Woerter ein:\n");
    int i = 0;
    char word[MAX_WORD_SIZE];
    int has_failed = 0;
    char* new_word;
    do {
        (void) strncpy(word, END_WORD, MAX_WORD_SIZE); // reset
        (void) scanf("%" S(MAX_WORD_SCAN_SIZE)"s", word);
        int len = strnlen(word, MAX_WORD_SIZE);
        if (len >= 0 && strncmp(END_WORD, word, MAX_WORD_SIZE) != 0) {
            new_word = (char *) malloc(len * sizeof(char));
            has_failed = check_pointer(new_word);
            strncpy(new_word, word, MAX_WORD_SIZE);
            words[i] = new_word;
            i++;
        }
    } while(has_failed == 0 && strncmp(END_WORD, word, MAX_WORD_SIZE) != 0);

    if (has_failed == 0) {
        *word_count = i;
    }
    return has_failed;
}

/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if there was an error reading the words.
 */
int main(void)
{
    char *word_list[MAX_WORD_COUNT];
    int word_count = 0;
    if (read_words(word_list, &word_count) == 0) {
        (void) qsort(word_list, word_count, sizeof (const char *), compare);
        print_deduped_word_list(word_list, word_count);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
