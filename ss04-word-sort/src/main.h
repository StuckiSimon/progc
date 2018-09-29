/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_COUNT 100
#define MAX_WORD_SIZE 20 - 1
#define MAX_WORD_SCAN_SIZE 19

static int compare(const void *a, const void *b);

static void printDedupedWordlist(char *words[MAX_WORD_COUNT], const int wordCount);

static int readWords(char *words[MAX_WORD_COUNT], int *wordCount);