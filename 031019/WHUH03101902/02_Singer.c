#include <stdio.h>
//Task 02: Singer Mark

int main() {
    printf("Hello, World!\n");
    int mark[11];
    for (int i = 0; i < 10; ++i) {
        printf("Hello! Judge No. %d, please input your score: ", i + 1);
        while ((scanf("%d", &mark[i]), (mark[i] < 80 || mark[i] > 100))){
            printf("Please input a right number: ");
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (mark[i] <= mark[j]){
                int swap = mark[i];
                mark[i] = mark[j];
                mark[j] = swap;
            }
        }
    }
    printf("Marks: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", mark[i]);
    }
    printf("\n");
    printf("Judge No. 11, You are so late: ");
    while ((scanf("%d", &mark[10]), (mark[10] < 80 || mark[10] > 100))){
        printf("Please input a right number: ");
    }
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (mark[i] <= mark[j]){
                int swap = mark[i];
                mark[i] = mark[j];
                mark[j] = swap;
            }
        }
    }
    printf("Marks: ");
    for (int i = 0; i < 11; ++i) {
        printf("%d ", mark[i]);
    }
    printf("\n");
    return 0;
}
