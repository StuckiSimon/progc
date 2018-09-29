/**
 * @file
 * @brief Lab implementation
 */
#include "../../testlib/include/test_utils.h"
#include "../src/color.h"
#include "CUnit/Basic.h"
#include <stdio.h>
#include <stdlib.h>

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

/// @brief test input
#define INFILE "test.input"

#ifndef TARGET // can be given by the Makefile --> see test target
/// @brief fix value in case TARGET has not been set
#define TARGET "../bin/linkedList"
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
    const char *out_txt[] = { "What do you want to do?\n",
        "i(nsert), r(emove), s(how), c(lear), e(xit) >[31mempty list\n",
        "[0mWhat do you want to do?\n",
        "i(nsert), r(emove), s(how), c(lear), e(xit) >Name: \n",
        "Firstname: \n", "Age: \n", "What do you want to do?\n",
        "i(nsert), r(emove), s(how), c(lear), e(xit) >[34mWayne               "
        "     [35m Bruce                    [0m  30\n",
        "What do you want to do?\n",
        "i(nsert), r(emove), s(how), c(lear), e(xit) >it was a pleasure "
        "serving you\n" };
    // act
    int exit_code
        = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE);
    // assert
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
}

/**
 * @brief Registers and runs the tests.
 * @return returns 0 if test has been run
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic(
        "IntegrationTestLinkedList", setup, teardown, test_print_deduped_list);
    return EXIT_SUCCESS;
}
