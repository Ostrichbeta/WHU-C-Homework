#include <stdio.h>
#include <stdlib.h>
//Task 04: Sorting Scores

double* sort_the_ratings_and_get_average_score_than_make_them_into_an_single_array (double *a, int len){
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (a[i] >= a[j]) {
                double swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
        }
    }
    a = realloc(a, sizeof(double) * (len + 1));
    double total_score = 0;
    for (int i = 0; i < len; i++) {
        total_score += a[i];
    }
//	printf("a[len] = %.2lf, avg = %.2lf\n", a[len], total_score / len);
    a[len] = total_score / len;
//	printf("a[len] = %.2lf\n", a[len]);
    return a;
}

int main(){
    int len = 10;
    double *a = malloc(sizeof(double) * len);
    for (int i = 0; i < len; i++) {
        printf("Enter the score by Judge No. %d, ranged from 80 to 100: ", i + 1);
        while (!(scanf("%lf", &a[i]) == 1 && a[i] >= 80 && a[i] <= 100)) {
            printf("Invalid input, try again: ");
        }
    }
    a = sort_the_ratings_and_get_average_score_than_make_them_into_an_single_array(a, len);
    printf("Sorted marks: ");
    for (int i = 0; i < len; i++) {
        printf("%.2lf ", a[i]);
    }
    printf("\nThe average score is %.2lf (rounded).", a[len]);
    for (int i = 11; i <= 15; i++) {
        printf("Enter the score by judge No. %d as the same range above: ", i);
        double mark = 0;
        while (!((scanf("%lf", &mark) == 1 && mark >= 80 && mark <= 100))) {
            printf("Invalid input, try again: ");
        }
        a[len] = mark;
//		printf("a[len] = %.2lf\n", a[len]);
        len++;
        a = sort_the_ratings_and_get_average_score_than_make_them_into_an_single_array(a, len);
        printf("Sorted marks: ");
        for (int j = 0; j < len; j++) {
            printf("%.2lf ", a[j]);
        }
        printf("\nThe average score is %.2lf (rounded).\n", a[len]);
    }
    free(a);
}
