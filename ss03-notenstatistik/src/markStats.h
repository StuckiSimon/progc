
#ifndef _MARK_STATS_H_
#define _MARK_STATS_H_

#define MAX_POINTS_SIZE 100

typedef struct {
    int perMarkCount[6];
    int worstMark;
    int bestMark;
    int markSum;
    int averageMark;
    int passedCount;
    double passedPercent;
} stats;

int calcRoundedMark(int maxPoints, int points);

stats calcStats(const int maxPoints, const int points[MAX_POINTS_SIZE],
    const int studentsAmount);

void printStats(
    const int maxPoints, const int studentsAmount, const stats stats);

#endif