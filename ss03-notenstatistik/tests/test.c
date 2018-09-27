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
#include "../src/markStats.h"
#include "CUnit/Basic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// UUT - Unit-Under-Test
int calc_rounded_mark(int max_points, int points);
stats calc_stats(const int max_points, const int points[MAX_POINTS_SIZE],
    const int students_amount);

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
static void test_rounded_mark(void)
{
    CU_ASSERT_EQUAL(calc_rounded_mark(100, 100), 6);
    CU_ASSERT_EQUAL(calc_rounded_mark(100, 0), 1);
    CU_ASSERT_EQUAL(calc_rounded_mark(100, 120), 6);
    CU_ASSERT_EQUAL(calc_rounded_mark(120, 119), 6);
    CU_ASSERT_EQUAL(calc_rounded_mark(120, 100), 5);
    CU_ASSERT_EQUAL(calc_rounded_mark(12, 6), 4);
}

static void test_calc_stats(void)
{
    const int points[] = { 12, 8, 5, 12, 0 };
    stats stats = calc_stats(12, points, 5);
    CU_ASSERT_EQUAL(stats.worst_mark, 1);
    CU_ASSERT_EQUAL(stats.passed_count, 3);
    CU_ASSERT_EQUAL(stats.passed_percent, 60);
    CU_ASSERT_DOUBLE_EQUAL(stats.average_mark, 4.0, 0.1);
    CU_ASSERT_EQUAL(stats.per_mark_count[6 - 1], 2);
    CU_ASSERT_EQUAL(stats.per_mark_count[5 - 1], 0);
    CU_ASSERT_EQUAL(stats.per_mark_count[4 - 1], 1);
    CU_ASSERT_EQUAL(stats.per_mark_count[3 - 1], 1);
    CU_ASSERT_EQUAL(stats.per_mark_count[2 - 1], 0);
    CU_ASSERT_EQUAL(stats.per_mark_count[1 - 1], 1);
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("Test next date calculator", setup, teardown,
        test_rounded_mark, test_calc_stats);
}
