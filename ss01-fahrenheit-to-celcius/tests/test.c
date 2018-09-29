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
double fahrenheit_to_celcius(int f);

/// Epsilon for double comparisons.
#define EPSILON 0.01

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
static void test_fahrenheit_to_celcius(void)
{
    // arrange
    // act
    // assert
    CU_ASSERT_DOUBLE_EQUAL(fahrenheit_to_celcius(-20), -28.89, EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(fahrenheit_to_celcius(0), -17.78, EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(fahrenheit_to_celcius(40), 4.44, EPSILON);
    CU_ASSERT_DOUBLE_EQUAL(fahrenheit_to_celcius(120), 48.89, EPSILON);
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("Test fahrenheit to celcius converter", setup, teardown,
        test_fahrenheit_to_celcius);
}
