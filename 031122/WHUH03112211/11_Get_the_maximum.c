#include <stdio.h>
#include <stdlib.h>
//Task 11: Find the maximum number ans its poosition.

struct ldArray {
    long double *array;
    size_t count;
};

struct maximum {
    long double value;
    size_t position;
};

typedef struct ldArray ldArray;
typedef struct maximum maximum;

maximum getMaximumRecursively(ldArray array) {
    static int currentPosition = 0;
    static maximum max;
    if (currentPosition == 0) {
        max.position = 0;
        max.value = array.array[0];
    } else {
        if (array.array[currentPosition] > max.value) {
            max.value = array.array[currentPosition];
            max.position = currentPosition;
        }
    }
    if (currentPosition == array.count) return max;
    currentPosition++;
    return getMaximumRecursively(array);
}

maximum getMaximumLoopy(ldArray array) {
    maximum max;
    max.value = array.array[0];
    max.position = 0;
    for (int i = 0; i < array.count; ++i) {
        if (array.array[i] > max.value) {
            max.value = array.array[i];
            max.position = i;
        }
    }
    return max;
}

int main() {
    printf("Hou many numbers? ");
    size_t len;
    while (!(scanf("%ld", &len) == 1 && len > 0)) {
        printf("Try again: ");
    }
    ldArray testArray;
    testArray.count = len;
    testArray.array = malloc(len * sizeof(long double));
    for (size_t i = 0; i < len; ++i) {
        do {
            printf("Input the element No. %zi: ", i + 1);
        } while (scanf("%Lf", &testArray.array[i]) != 1);
    }
    printf("Input complete.\n");
    maximum max1 = getMaximumRecursively(testArray);
    maximum max2 = getMaximumLoopy(testArray);
    printf("Answer (Recursive way): %Lf, at position %zi.\n", max1.value, max1.position);
    printf("Answer (Loop way): %Lf, at position %zi.\n", max2.value, max2.position);
    return 0;
}
