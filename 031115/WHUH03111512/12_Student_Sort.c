#include <stdio.h>
#include <stdlib.h>
//Task 12: Sort out the students

struct arrayld {
    long double *array;
    int count;
};

void sort (struct arrayld input_arr) {
    for (int i = 0; i < input_arr.count; ++i) {
        for (int j = i + 1; j < input_arr.count; ++j) {
            if (input_arr.array[i] <= input_arr.array[j]) {
                long double swap = input_arr.array[i];
                input_arr.array[i] = input_arr.array[j];
                input_arr.array[j] = swap;
            }
        }
    }
}

int main() {
    printf("How many students? ");
    struct arrayld student_score;
    while (!(scanf("%d", &student_score.count) == 1 && student_score.count > 0 && student_score.count < 50)) {
        printf("Invalid input, please try again: ");
    }
    student_score.array = malloc(student_score.count * sizeof(long double));
    for (int i = 0; i < student_score.count; ++i) {
        printf("Input the No. %d's score: ", i + 1);
        while (!(scanf("%Lf", &student_score.array[i]) == 1 && student_score.array[i] >= 0)) {
            printf("Invalid input, please try again: ");
        }
    }
    sort(student_score);
    int student_grade_count[3];
    for (int i = 0; i < 3; ++i) {
        student_grade_count[i] = 0;
    }
    for (int i = 0; i < student_score.count; ++i) {
        long double current = student_score.array[i];
        if (current >= 85) student_grade_count[0]++;
        if (current >= 60 && current < 85) student_grade_count[1]++;
        if (current < 60) student_grade_count[2]++;
    }
    printf("All the marks: ");
    for (int i = 0; i < student_score.count; ++i) {
        printf("%.2Lf ", student_score.array[i]);
    }
    printf("\n(Rounded two digits)\n");
    printf("Excellent student(s): %d, so-so student(s): %d, not-good student(s): %d\n",
           student_grade_count[0], student_grade_count[1], student_grade_count[2]);
    return 0;
}
