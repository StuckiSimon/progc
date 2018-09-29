
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

/**
 * @brief           calculates the mark given points and the max_points
 * @param[in] int   max_points.
 * @param[in] int   points.
 * @return int      The calculated mark.
 */
int calc_rounded_mark(int max_points, int points);

/**
 * @brief           calculates stats given max_points, scored points array and amount of students
 * @param[in] int   max_points.
 * @param[in] int[] points.
 * @param[in] int   students_amount.
 * @return stats    the stats.
 */
stats calc_stats(const int max_points, const int points[MAX_POINTS_SIZE],
    const int students_amount);

/**
 * @brief           prints stats given max_points, scored points array and amount of students
 * @param[in] int   max_points.
 * @param[in] int[] points.
 * @param[in] int   students_amount.
 */
void print_stats(
    const int max_points, const int students_amount, const stats stats);

#endif