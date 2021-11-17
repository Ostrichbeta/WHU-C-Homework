#include <stdio.h>
#include <stdlib.h>
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

struct arrayld array_combine (struct arrayld a, struct arrayld b) {
    struct arrayld result;
    result.count = a.count + b.count;
    result.array = malloc(result.count * sizeof(long double));
    for (int i = 0; i < a.count; ++i) {
        result.array[i] = a.array[i];
    }
    for (int i = 0; i < b.count; ++i) {
        result.array[a.count + i] = b.array[i];
    }
    sort(result);
    return result;
}

int main() {
    int count_a, count_b;
    printf("How many elements would you like in the first array? ");
    while (!(scanf("%d", &count_a) == 1 && count_a > 0)) {
        printf("Invalid input, please try again: ");
        fflush(stdin);
    }
    printf("How many elements would you like in the second array? ");
    while (!(scanf("%d", &count_b) == 1 && count_b > 0)) {
        printf("Invalid input, please try again: ");
        fflush(stdin);
    }
    struct arrayld array_a, array_b;
    array_a.count = count_a;
    array_b.count = count_b;
    array_a.array = malloc(array_a.count * sizeof(long double));
    array_b.array = malloc(array_b.count * sizeof(long double));
    for (int i = 0; i < count_a; ++i) {
        printf("Define array a pos %d: ", i);
        while (scanf("%Lf", &array_a.array[i]) != 1);
    }
    sort(array_a);
    printf("Array a is: ");
    for (int i = 0; i < array_a.count; ++i) {
        printf("%Lf ", array_a.array[i]);
    }
    printf("\n");
    for (int i = 0; i < count_b; ++i) {
        printf("Define array b pos %d: ", i);
        while (scanf("%Lf", &array_b.array[i]) != 1);
    }
    sort(array_b);
    printf("Array b is: ");
    for (int i = 0; i < array_b.count; ++i) {
        printf("%Lf ", array_b.array[i]);
    }
    printf("\n");
    struct arrayld combination = array_combine(array_a, array_b);
    printf("The combination is: ");
    for (int i = 0; i < combination.count; ++i) {
        printf("%Lf ", combination.array[i]);
    }
    printf("\n");
    free(combination.array);
    free(array_b.array);
    free(array_a.array);
    return 0;
}
