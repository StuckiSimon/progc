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
int calcRoundedMark(int maxPoints, int points);
stats calcStats(const int maxPoints, const int points[MAX_POINTS_SIZE],
    const int studentsAmount);

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
    CU_ASSERT_EQUAL(calcRoundedMark(100, 100), 6);
    CU_ASSERT_EQUAL(calcRoundedMark(100, 0), 1);
    CU_ASSERT_EQUAL(calcRoundedMark(100, 120), 6);
    CU_ASSERT_EQUAL(calcRoundedMark(120, 119), 6);
    CU_ASSERT_EQUAL(calcRoundedMark(120, 100), 5);
    CU_ASSERT_EQUAL(calcRoundedMark(12, 6), 4);
}

static void test_calc_stats(void)
{
    const int points[] = { 12, 8, 5, 12, 0 };
    stats stats = calcStats(12, points, 5);
    CU_ASSERT_EQUAL(stats.worstMark, 1);
    CU_ASSERT_EQUAL(stats.passedCount, 3);
    CU_ASSERT_EQUAL(stats.passedPercent, 60);
    CU_ASSERT_DOUBLE_EQUAL(stats.averageMark, 4.0, 0.1);
    CU_ASSERT_EQUAL(stats.perMarkCount[6 - 1], 2);
    CU_ASSERT_EQUAL(stats.perMarkCount[5 - 1], 0);
    CU_ASSERT_EQUAL(stats.perMarkCount[4 - 1], 1);
    CU_ASSERT_EQUAL(stats.perMarkCount[3 - 1], 1);
    CU_ASSERT_EQUAL(stats.perMarkCount[2 - 1], 0);
    CU_ASSERT_EQUAL(stats.perMarkCount[1 - 1], 1);
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
