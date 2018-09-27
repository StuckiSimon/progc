#ifndef _PARSE_ARGS_H_
#define _PARSE_ARGS_H_

#include "options.h"

/**
 * @brief           Entry point for calculating.
 * @param[in] text  Text to be processed.
 * @return          Calculated value.
 */
options parse_args(options DEFAULT_OPTIONS, int argc, char *argv[]);

#endif