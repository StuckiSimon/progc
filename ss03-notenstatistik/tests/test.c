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

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"
/// @brief test input
#define INFILE "test.input"

#ifndef TARGET // must be given by the make file --> see test target
#define TARGET "../bin/markStats"
#endif

/// UUT - Unit-Under-Test
int calc_rounded_mark(int max_points, int points);
stats calc_stats(const int max_points, const int points[MAX_POINTS_SIZE],
    const int students_amount);

// setup & cleanup
static int setup(void)
{
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0; // success
}

static int teardown(void)
{
    // Do nothing.
    // Especially: do not remove result files - they are removed in int
    // setup(void) *before* running a test.
    return 0; // success
}

// tests
static void test_rounded_mark(void)
{
    CU_ASSERT_EQUAL(calc_rounded_mark(100, 0), 1);
    CU_ASSERT_EQUAL(calc_rounded_mark(100, 120), 6);
    CU_ASSERT_EQUAL(calc_rounded_mark(100, 100), 6);
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

static void test_mark_stats(void)
{
    const char *out_txt[] = {
        "Generate stats: \n",
        "Type in the points of your students:\n",
        "How many points are needed for mark 6? \n",
        "------------------------------------------\n",
        "Statistic (6 students, 12 Points for Mark 6):\n",
        "\n",
        "Mark 6:	  4\n",
        "Mark 5:	  1\n",
        "Mark 4:	  1\n",
        "Mark 3:	  0\n",
        "Mark 2:	  0\n",
        "Mark 1:	  0\n",
        "\n",
        "Best Mark:	6\n",
        "Worst Mark:	4\n",
        "Average Mark:	5\n",
        "Mark >= 4:	6 Students (100.00%)\n",
        "------------------------------------------\n",
        "Try out another metric? (Yes=1 / No=0) \n",
    };
    // act
    // system("../bin/wordSort  1> stdout.txt 2> stderr.txt < test.input");
    int exit_code
        = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE);
    // assert
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("Test next date calculator", setup, teardown,
        test_rounded_mark, test_calc_stats, test_mark_stats
    );
}
