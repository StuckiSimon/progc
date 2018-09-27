/* -----------------------
 ____  _  _   __   _  _
(__  )/ )( \ / _\ / )( \
 / _/ ) __ (/    \\ /\ /
(____)\_)(_/\_/\_/(_/\_)
-------------------------- */
/**
 * @file
 * @brief Converts Fahrenheit to Celcius
 * Accepts the lower (-l), upper (-u) limit and the stepsize (-s) as arguments
 * E.g. ./src/main -l -100 -u 50 -s 30
 */
#include "fahrenheitToCelcius.h"
#include "options.h"
#include "parseArgs.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments
 *                  with argv[0] being the command call
 *                  argv[1] the 1st argument, ...
 *                  argv[argc-1] the last argument.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 */
int main(int argc, char *argv[])
{
    const options DEFAULT_OPTIONS = { -100, 200, 20 };

    const options opts = parse_args(DEFAULT_OPTIONS, argc, argv);

    (void)print_temparature_table(opts.min, opts.max, opts.step);

    return EXIT_SUCCESS;
}
