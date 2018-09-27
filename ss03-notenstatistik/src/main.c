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

void readMinPoints(int *minPoints)
{
    (void)printf("How many points are needed for mark 6? ");
    scanf("%5d", minPoints);
    (void)printf("\n");
}

int readPoints(int points[MAX_POINTS_SIZE], int *pointsLen)
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
    if (point == -1) {
        *pointsLen = i;
        return 1;
    }
    // Otherwise there was an illegal input
    (void)printf("Illegal input!\n");
    return 0;
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
    int pointsLen;
    int minPoints;
    int repeat;

    if (readPoints(points, &pointsLen)) {
        do {
            repeat = 0;
            minPoints = 0;
            (void)readMinPoints(&minPoints);

            if (minPoints == 0) {
                return EXIT_FAILURE;
            }
            stats stats = calcStats(minPoints, points, pointsLen);
            (void)printStats(minPoints, pointsLen, stats);

            (void)printf("Try out another metric? (Yes=1 / No=0) \n");
            scanf("%1d", &repeat);
        } while (repeat);

        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
