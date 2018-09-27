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
int compare(const void * a, const void * b)
{
    return strcmp (*(const char **) a, *(const char **) b);
}

// @brief dedupes words and prints the sorted list
// @attention This function depends on the fact that the list is already sorted!
void printDedupedWordlist(char* words[MAX_WORD_COUNT], const int wordCount)
{
  char* deduped[MAX_WORD_COUNT];
  int dedupedWordCount = 0;
  for(int i = 0; i < wordCount; i++) {
    // if the last word is not equal this one, add it to the new array
    if (i == 0 || strcmp(words[i-1], words[i]) != 0) {
        // store word in deduped array
        deduped[dedupedWordCount] = words[i];
        dedupedWordCount += 1;
    }
  }
  (void) printf("--------------\n");
  (void) printf("----Sorted----\n");
  (void) printf("--------------\n");
  for(int i = 0; i < dedupedWordCount; i++) {
    (void) printf("%s\n", deduped[i]);
  }
  (void) printf("--------------\n");
}

int readWords(char* words[MAX_WORD_COUNT], int *wordCount)
{
    (void) printf("Geben Sie Woerter ein:\n");
    int i = 0;
    char word[MAX_WORD_SIZE];
    int hasFailed = 0;
    char* newWord;
    do {
        (void) strcpy(word, END_WORD); // reset
        (void) scanf("%" S(MAX_WORD_SCAN_SIZE)"s", word);
        int len = strlen(word);
        if (len >= 0 && strcmp(END_WORD, word) != 0) {
            newWord = (char *) malloc(len * sizeof(char));
            if (newWord == NULL) {
                (void) printf("not enough memory\n");
                hasFailed = 1;
            }
            strcpy(newWord, word);
            words[i] = newWord;
            i++;
        }
    } while(hasFailed == 0 && strcmp(END_WORD, word) != 0);
    if (hasFailed == 1) {
        return 0;
    }
    *wordCount = i;
    return 1;
}

/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if there was an error reading the words.
 */
int main(void)
{
    char *wordList[MAX_WORD_COUNT];
    int wordCount = 0;
    if (readWords(wordList, &wordCount)) {
        (void) qsort(wordList, wordCount, sizeof (const char *), compare);
        printDedupedWordlist(wordList, wordCount);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
