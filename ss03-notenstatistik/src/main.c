/* -----------------------
 ____  _  _   __   _  _
(__  )/ )( \ / _\ / )( \
 / _/ ) __ (/    \\ /\ /
(____)\_)(_/\_/\_/(_/\_)
-------------------------- */
/**
 * @file
 * @brief Generates Marks and Stats given points
 * User can input the scores of their students and then generate stats based
 * on the minimum score needed for mark 6.
 * The same scores can be used to generate different stats with different
 * minimum points.
 */
#include "markStats.h"
#include <stdio.h>
#include <stdlib.h>

static void readmin_points(int *min_points)
{
    (void)printf("How many points are needed for mark 6? ");
    scanf("%5d", min_points);
    (void)printf("\n");
}

static int read_points(int points[MAX_POINTS_SIZE], int *points_len)
{
    (void)printf("Type in the points of your students:\n");
    int i = 0;
    int point;
    do {
        point = -2; // reset point so it fails when no number is entered.
        (void)scanf("%5d", &point);
        if (point >= 0) {
            points[i] = point;
            i += 1;
        }
    } while (point >= 0);

    // if input is -1 the user broke out correctly.
    int exit_code = EXIT_FAILURE;
    if (point == -1) {
        *points_len = i;
        exit_code = EXIT_SUCCESS;
    } else {
      // Otherwise there was an illegal input
      (void)printf("Illegal input!\n");
    }
    return exit_code;
}

/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if there was an illegal input
 */
int main(void)
{
    (void)printf("Generate stats: \n");
    int points[MAX_POINTS_SIZE];
    int points_len;
    int min_points;
    int repeat;

    if (read_points(points, &points_len) == 0) {
        do {
            repeat = 0;
            min_points = 0;
            (void)readmin_points(&min_points);

            if (min_points == 0) {
                return EXIT_FAILURE;
            }
            stats stats = calc_stats(min_points, points, points_len);
            (void)print_stats(min_points, points_len, stats);

            (void)printf("Try out another metric? (Yes=1 / No=0) \n");
            (void)scanf("%1d", &repeat);
        } while (repeat);

        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
