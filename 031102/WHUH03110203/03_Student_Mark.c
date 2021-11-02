#include <stdio.h>
#include <math.h>
//Task 03: Student Mark Statistic

int main() {
    printf("Now input the score of 10 students, ranged from 0 to 100.\n");
    double score[10];
    double total_score = 0;
    for (int i = 0; i < 10; ++i) {
        do {
            printf("Enter student No. %d's score: ", i + 1);
            scanf("%lf", &score[i]);
        } while (score[i] > 100 || score[i] < 0);
        total_score += score[i];
    }
    printf("Average score is %.2lf.\n", total_score / 10);
    double total_variance = 0;
    for (int i = 0; i < 10; ++i) {
        total_variance += pow(score[i] - total_score / 10, 2);
    }
    printf("Variance is %.2lf.\n", total_variance / 10);
    printf("(All the results have been rounded to two digits)\n");
    return 0;
}
