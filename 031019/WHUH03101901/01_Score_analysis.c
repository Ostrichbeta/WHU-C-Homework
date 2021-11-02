#include <stdio.h>
//Task 01: Score Analysis

int main() {
    double mark[10];
    printf("Import 10 float number as the students' score.\n");
    double gtr90 = 0;
    for (int i = 0; i < 10; ++i) {
        printf("Student No. %d: ", i + 1);
        scanf("%lf", &mark[i]);
        if (mark[i] >= 90.0) gtr90+= 1;
    }
    double avg = 0;
    for (int i = 0; i < 10; ++i) {
        avg += mark[i];
    }
    avg /= 10;
    double lesavg = 0;
    for (int i = 0; i < 10; ++i) {
        if (mark[i] < avg) lesavg += 1;
    }
    printf("Average score: %.2lf\n", avg);
    printf("Ratio of students whose score is greater than 90: %.2lf%%\n", gtr90 / 10 * 100);
    printf("Ratio of students whose score is below the average: %.2lf%%\n", lesavg / 10 * 100);
    return 0;
}
