#include "markStats.h"
#include <stdio.h>
#include <stdlib.h>

int calc_rounded_mark(int max_points, int points)
{
    double mark = 5 * ((points) / (max_points * 1.0)) + 1;
    int rounded_down = mark;
    double rest = mark - rounded_down;
    int result = rounded_down;
    if (rest >= 0.5) {
        result += 1;
    }
    if (result > 6) {
        result = 6;
    }
    if (result < 1) {
        result = 1;
    }
    return result;
}

stats calc_stats(const int max_points, const int points[MAX_POINTS_SIZE],
    const int students_amount)
{
    stats stats = { { 0 } };
    stats.worst_mark = 6;
    stats.best_mark = 0;
    stats.mark_sum = 0;
    stats.average_mark = 0;
    stats.passed_count = 0;
    stats.passed_percent = 0;

    for (int i = 0; i < students_amount; i++) {
        int point = points[i];
        int mark = calc_rounded_mark(max_points, point);
        stats.best_mark = stats.best_mark > mark ? stats.best_mark : mark;
        stats.worst_mark = stats.worst_mark < mark ? stats.worst_mark : mark;
        stats.mark_sum += mark;
        stats.passed_count
            = mark >= 4 ? stats.passed_count + 1 : stats.passed_count;
        stats.per_mark_count[mark - 1] += 1;
    }
    stats.average_mark = stats.mark_sum / students_amount;
    stats.passed_percent = stats.passed_count * 1.0 / students_amount * 100;
    return stats;
}

void print_stats(
    const int max_points, const int students_amount, const stats stats)
{
    (void)printf("------------------------------------------\n");
    (void)printf("Statistic (%d students, %d Points for Mark 6):\n",
        students_amount, max_points);
    (void)printf("\n");
    for (int i = 5; i >= 0; i--) {
        (void)printf("Mark %d:\t%3d\n", i + 1, stats.per_mark_count[i]);
    }
    (void)printf("\n");
    (void)printf("Best Mark:\t%d\n", stats.best_mark);
    (void)printf("Worst Mark:\t%d\n", stats.worst_mark);
    (void)printf("Average Mark:\t%d\n", stats.average_mark);
    (void)printf("Mark >= 4:\t%d Students (%5.2f%%)\n", stats.passed_count,
        stats.passed_percent);
    (void)printf("------------------------------------------\n");
}