#include <stdio.h>
#include <stdlib.h>
//Task 05: Use functions to implement the insert sorting algorithm.

struct arrayld {
    long double *array;
    int count;
};

void input_array_sort (struct arrayld input_arr);
void output_array (struct arrayld arr);
void sort (struct arrayld input_arr);
struct arrayld insert (struct arrayld input_arr, long double input_element);

int main() {
    struct arrayld init_array;
    init_array.count = 10;
    init_array.array = malloc(sizeof(init_array.count));
    input_array_sort(init_array);
    output_array(init_array);
    printf("How much number do you wanna insert? ");
    int insert_count = 0;
    while (!(scanf("%d", &insert_count) == 1 && insert_count > 0)) {
        printf("Invalid input, please try again: ");
    }
    for (int i = 0; i < insert_count; ++i) {
        printf("Input the insertion No. %d: ", i + 1);
        long double insert_element = 0;
        while (scanf("%Lf", &insert_element) != 1) {
            printf("Invalid input, please try again: ");
        }
        init_array = insert(init_array, insert_element);
        output_array(init_array);
    }
    free(init_array.array);
    return 0;
}

void input_array_sort (struct arrayld input_arr) {
    for (int i = 0; i < input_arr.count; ++i) {
        printf("Array position %d (start form 1): ", i + 1);
        while (scanf("%Lf", input_arr.array + i) != 1) {
            printf("Invalid input, please try again: ");
            fflush(stdin);
        }
    }
    printf("Input complete, now sorting...");
    struct arrayld result_struct = input_arr;
    sort(input_arr);
}

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

void output_array (struct arrayld arr) {
    for (int i = 0; i < arr.count; ++i) {
        printf("(%d) %.2Lf | ", i, arr.array[i]);
    }
    printf("\n");
}

struct arrayld insert (struct arrayld input_arr, long double input_element) {
    long double *new_array = malloc((input_arr.count + 1) * sizeof(long double));
    for (int i = 0; i < input_arr.count; ++i) {
        new_array[i] = input_arr.array[i];
    }
    input_arr.array = new_array;

    if (input_element >= input_arr.array[0]) {
        for (int i = input_arr.count; i >= 0 ; --i) {
            input_arr.array[i] = input_arr.array[i - 1];
        }
        input_arr.array[0] = input_element;
    } else {
        int input_pos = 0;
        for (int i = 0; i < input_arr.count - 1; ++i) {
            if (input_arr.array[i] > input_element && input_arr.array[i + 1] <= input_element) input_pos = i + 1;
        }
        for (int i = input_arr.count; i > input_pos; --i) {
            input_arr.array[i] = input_arr.array[i - 1];
        }
        input_arr.array[input_pos] = input_element;
    }
    input_arr.count += 1;
    return input_arr;
}