#include <stdio.h>
#include <stdlib.h>
//Task 06: Find the common multiple number in several numbers

struct arrayl {
    long *array;
    int count;
};

struct arrayl get_prime_number_list (long max_num) {
    struct arrayl result;
    result.count = 1;
    result.array = malloc(1 * sizeof(long));
    int list_len = 0;
    int max = 1;
    for (int i = 2; i <= max_num; ++i) {
        for (int j = 2; j < i; ++j) {
            if (i != j && i % j == 0) {
                max = 0;
            }
        }
        if (max) {
            if (result.count == 1 && result.array[0] == 0) {
                result.array[0] = i;
            } else {
                result.count++;
                result.array = realloc(result.array, result.count * sizeof(long));
                result.array[result.count - 1] = i;
            }
        }
        max = 1;
    }
    return result;
}

long get_largest_common_number(long num1, long num2){
    long a = num1, b = num2;
    if (num2 > num1){
        long swap = a;
        a = b;
        b = swap;
    }
    if (a % b == 0) {
        return b;
    } else {
        return get_largest_common_number(b, a % b);
    }
}

long find_common_multiple (long a, long b) {
    long result = a * b / get_largest_common_number(a, b);
    return result;
}

int main() {
    struct arrayl input_array;
    printf("How many numbers do you wanna input? ");
    while (!(scanf("%d", &input_array.count) == 1 && input_array.count > 0)) {
        printf("Invalid input, please try again: ");
    }
    input_array.array = malloc(input_array.count * sizeof(long));
    for (int i = 0; i < input_array.count; ++i) {
        printf("(n >= 2)Array [%d] = ", i);
        while (!(scanf("%ld", &input_array.array[i]) == 1 && input_array.array[i] >= 2)) {
            printf("Invalid input, please try again: ");
        }
    }
    long result = 0;
    if (input_array.count == 1) {
        result = input_array.array[0];
    } else {
        result = find_common_multiple(input_array.array[0], input_array.array[1]);
        for (int i = 2; i < input_array.count; ++i) {
            result = find_common_multiple(result, input_array.array[i]);
            // printf("result = %ld.\n", result);
        }
    }
    printf("The common multiple of the given array is %ld.\n", result);
    return 0;
}
