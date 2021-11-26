#include <stdio.h>
#include <stdlib.h>
//Task 06: Find the maximum and the minimum in sub-array

struct subArray {
    double *list;
    size_t count;
};

struct fatherArray {
    struct subArray *subArray;
    size_t count;
};

int main() {
    printf("Hou many sub-arrays? ");
    int sub;
    while (!(scanf("%d", &sub) == 1 && sub > 0)) {
        printf("Invalid input, please try again: ");
    }
    printf("How many elements in a sub-array? ");
    int element;
    while (!(scanf("%d", &element) == 1 && element > 0)){
        printf("Invalid input, please try again: ");
    }
    struct fatherArray father;
    father.count = sub;
    father.subArray = malloc(father.count * sizeof(struct subArray));
    for (int i = 0; i < father.count; ++i) {
        father.subArray[i].count = element;
        father.subArray[i].list = malloc(father.subArray[i].count * sizeof(double));
    }
    printf("Now input the number.\n");
    for (int i = 0; i < father.count; ++i) {
        for (int j = 0; j < father.subArray[i].count; ++j) {
            printf("Father No. %d, Child No. %d: ", i + 1, j + 1);
            while (scanf("%lf", &father.subArray[i].list[j]) != 1);
            fflush(stdin);
        }
    }
    printf("Input complete.\n");
    for (int i = 0; i < father.count; ++i) {
        printf("Father No. %d: ", i + 1);
        for (int j = 0; j < father.subArray[i].count; ++j) {
            printf("%.2lf ", father.subArray[i].list[j]);
        }
        printf("\n");
    }
    double *max = malloc(father.count * sizeof(double));
    double *min = malloc(father.count * sizeof(double));
    for (int i = 0; i < father.count; ++i) {
        max[i] = father.subArray[i].list[0];
        min[i] = father.subArray[i].list[0];
        for (int j = 0; j < father.subArray[i].count; ++j) {
            if (father.subArray[i].list[j] > max[i]) {
                max[i] = father.subArray[i].list[j];
            }
            if (father.subArray[i].list[j] < min[i]) {
                min[i] = father.subArray[i].list[j];
            }
        }
    }
    for (int i = 0; i < father.count; ++i) {
        printf("Father No. %d, the maximum is %.2lf, the minimum is %.2lf.\n", i + 1, max[i], min[i]);
    }
    return 0;
}
