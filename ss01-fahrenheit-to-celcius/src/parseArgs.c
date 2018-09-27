#include "options.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

options parse_args(options DEFAULT_OPTIONS, int argc, char *argv[])
{
    options opts = DEFAULT_OPTIONS;
    int c;
    char *txt;
    while ((c = getopt(argc, argv, "l:u:s:")) != -1) {
        switch (c) {
        case 'l':
            opts.min = strtol(optarg, &txt, 10);
            break;
        case 'u':
            opts.max = strtol(optarg, &txt, 10);
            break;
        case 's':
            opts.step = strtol(optarg, &txt, 10);
            break;
        default:
            break;
        }
    }
    return opts;
}