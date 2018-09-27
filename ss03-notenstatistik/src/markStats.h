
#ifndef _MARK_STATS_H_
#define _MARK_STATS_H_

#define MAX_POINTS_SIZE 100

typedef struct {
    int per_mark_count[6];
    int worst_mark;
    int best_mark;
    int mark_sum;
    int average_mark;
    int passed_count;
    double passed_percent;
} stats;

int calc_rounded_mark(int max_points, int points);

stats calc_stats(const int max_points, const int points[MAX_POINTS_SIZE],
    const int students_amount);

void print_stats(
    const int max_points, const int students_amount, const stats stats);

#endif