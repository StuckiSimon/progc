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
 * @brief Test suite for the given package.
 */
#include "../../testlib/include/test_utils.h"
#include "CUnit/Basic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/// UUT - Unit-Under-Test
int countWords(char *str);

/// Epsilon for double comparisons.
#define EPSILON 0.001

// setup & cleanup
static int setup(void)
{
    // Do nothing.
    return 0; // success
}

static int teardown(void)
{
    // Do nothing.
    return 0; // success
}

// tests
static void test_count_words(void)
{
    // arrange
    // act
    char s[] = "werewr rewqrw rewqr";
    int d = countWords(s);
    // assert
    CU_ASSERT_DOUBLE_EQUAL(d, 3, EPSILON);
}

static void test_count_words_empty(void)
{
    // arrange
    // act
    char s[] = "";
    int d = countWords(s);
    // assert
    CU_ASSERT_DOUBLE_EQUAL(d, 0, EPSILON);
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("Test word count", setup, teardown, test_count_words,
        test_count_words_empty);
}
