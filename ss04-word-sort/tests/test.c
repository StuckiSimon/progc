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
#include "../../testlib/include/test_utils.h"
#include "CUnit/Basic.h"
#include <stdio.h>
#include <stdlib.h>

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

/// @brief test input
#define INFILE "test.input"

#ifndef TARGET // must be given by the make file --> see test target
#define TARGET "../bin/wordSort"
#endif

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
static void test_print_deduped_list(void)
{
    // arrange
    const char *out_txt[] = {
        "Geben Sie Woerter ein:\n",
        "--------------\n",
        "----Sorted----\n",
        "--------------\n",
        "aaa\n",
        "aaaa\n",
        "bbb\n",
        "bbbbbb\n",
        "--------------\n",
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
    TestMainBasic("Wordsort", setup, teardown, test_print_deduped_list);
}
