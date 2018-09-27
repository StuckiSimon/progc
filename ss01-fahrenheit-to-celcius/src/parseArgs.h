#ifndef _PARSE_ARGS_H_
#define _PARSE_ARGS_H_

#include "options.h"

/**
 * @brief           parses command line arguments to options with default options as fallback.
 * @param[in] options  Default options.
 * @param[in] argc, *argv
 * @return          options.
 */
options parse_args(options DEFAULT_OPTIONS, int argc, char *argv[]);

#endif