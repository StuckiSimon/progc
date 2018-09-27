#include "markStats.h"
#include <stdio.h>
#include <stdlib.h>

int calcRoundedMark(int maxPoints, int points)
{
    double mark = 5 * ((points) / (maxPoints * 1.0)) + 1;
    int roundedDown = mark;
    double rest = mark - roundedDown;
    int result = roundedDown;
    if (rest >= 0.5) {
        result += 1;
    }
    if (result > 6) {
        return 6;
    }
    if (result < 1) {
        return 1;
    }
    return result;
}

stats calcStats(const int maxPoints, const int points[MAX_POINTS_SIZE],
    const int studentsAmount)
{
    stats stats = { { 0 } };
    stats.worstMark = 6;
    stats.bestMark = 0;
    stats.markSum = 0;
    stats.averageMark = 0;
    stats.passedCount = 0;
    stats.passedPercent = 0;

    for (int i = 0; i < studentsAmount; i++) {
        int point = points[i];
        int mark = calcRoundedMark(maxPoints, point);
        stats.bestMark = stats.bestMark > mark ? stats.bestMark : mark;
        stats.worstMark = stats.worstMark < mark ? stats.worstMark : mark;
        stats.markSum += mark;
        stats.passedCount
            = mark >= 4 ? stats.passedCount + 1 : stats.passedCount;
        stats.perMarkCount[mark - 1] += 1;
    }
    stats.averageMark = stats.markSum / studentsAmount;
    stats.passedPercent = stats.passedCount * 1.0 / studentsAmount * 100;
    return stats;
}

void printStats(
    const int maxPoints, const int studentsAmount, const stats stats)
{
    (void)printf("------------------------------------------\n");
    (void)printf("Statistic (%d students, %d Points for Mark 6):\n",
        studentsAmount, maxPoints);
    (void)printf("\n");
    for (int i = 5; i >= 0; i--) {
        (void)printf("Mark %d:\t%3d\n", i + 1, stats.perMarkCount[i]);
    }
    (void)printf("\n");
    (void)printf("Best Mark:\t%d\n", stats.bestMark);
    (void)printf("Worst Mark:\t%d\n", stats.worstMark);
    (void)printf("Average Mark:\t%d\n", stats.averageMark);
    (void)printf("Mark >= 4:\t%d Students (%5.2f%%)\n", stats.passedCount,
        stats.passedPercent);
    (void)printf("------------------------------------------\n");
}