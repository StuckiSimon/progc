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
#include "../../../testlib/src/test_utils.h"
#include "CUnit/Basic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// UUT - Unit-Under-Test
struct tm getNextDayDate(struct tm date);

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
static void test_next_date(void)
{
    struct tm date = { 0 };
    struct tm nextDate = { 0 };
    strptime("12.12.2000", "%d.%m.%Y", &date);

    nextDate = getNextDayDate(date);
    CU_ASSERT_EQUAL(nextDate.tm_mday, 13);
    CU_ASSERT_EQUAL(nextDate.tm_mon, 12 - 1);
    CU_ASSERT_EQUAL(nextDate.tm_year, 2000 - 1900);
}

static void test_next_date_year_change(void)
{
    struct tm date = { 0 };
    struct tm nextDate = { 0 };

    strptime("31.12.2000", "%d.%m.%Y", &date);
    nextDate = getNextDayDate(date);
    CU_ASSERT_EQUAL(nextDate.tm_mday, 1);
    CU_ASSERT_EQUAL(nextDate.tm_mon, 1 - 1);
    CU_ASSERT_EQUAL(nextDate.tm_year, 2001 - 1900);
}

static void test_next_date_leap_year(void)
{
    struct tm date = { 0 };
    struct tm nextDate = { 0 };

    strptime("28.02.2000", "%d.%m.%Y", &date);
    nextDate = getNextDayDate(date);
    CU_ASSERT_EQUAL(nextDate.tm_mday, 29);
    CU_ASSERT_EQUAL(nextDate.tm_mon, 2 - 1);
    CU_ASSERT_EQUAL(nextDate.tm_year, 2000 - 1900);
}

static void test_next_date_no_leap_year(void)
{
    struct tm date = { 0 };
    struct tm nextDate = { 0 };

    strptime("28.02.2001", "%d.%m.%Y", &date);
    nextDate = getNextDayDate(date);
    CU_ASSERT_EQUAL(nextDate.tm_mday, 1);
    CU_ASSERT_EQUAL(nextDate.tm_mon, 3 - 1);
    CU_ASSERT_EQUAL(nextDate.tm_year, 2001 - 1900);
}

/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("Test next date calculator", setup, teardown, test_next_date,
        test_next_date_year_change, test_next_date_leap_year,
        test_next_date_no_leap_year);
}
