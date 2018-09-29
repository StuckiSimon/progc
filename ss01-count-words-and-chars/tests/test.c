/* -----------------------
 ____  _  _   __   _  _
(__  )/ )( \ / _\ / )( \
 / _/ ) __ (/    \\ /\ /
(____)\_)(_/\_/\_/(_/\_)
-------------------------- */
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
int count_words(char *str);

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
    int d = count_words(s);
    // assert
    CU_ASSERT_DOUBLE_EQUAL(d, 3, EPSILON);
}

static void test_count_words_empty(void)
{
    // arrange
    // act
    char s[] = "";
    int d = count_words(s);
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
