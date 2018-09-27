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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CUnit/Basic.h"
#include "../../../testlib/src/test_utils.h"

/// UUT - Unit-Under-Test
double fahrenheitToCelcius(int f);

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
	CU_ASSERT_DOUBLE_EQUAL(fahrenheitToCelcius(-20), -28.89, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(fahrenheitToCelcius(0), -17.78, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(fahrenheitToCelcius(40), 4.44, EPSILON);
	CU_ASSERT_DOUBLE_EQUAL(fahrenheitToCelcius(120), 48.89, EPSILON);
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("Test fahrenheit to celcius converter", setup, teardown,
		test_fahrenheit_to_celcius
	);
}
