#include <stdio.h>
#include <stdlib.h>
//Task 03: Find the max value in an array recursively
struct max_obj{
    long double max_value;
    int pos;
};

struct array_with_len {
    long double *array;
    int length;
};

struct max_obj find_the_maximum_in_an_array_and_forced_to_do_it_recursively (struct array_with_len arr_obj,
        struct max_obj max_obj, int pos){
    struct max_obj max_result = max_obj;
    if (pos == arr_obj.length) {
        return max_result;
    }
    if (arr_obj.array[pos] > max_obj.max_value) {
        // When the element is larger than current maximum
        max_result.max_value = arr_obj.array[pos];
        max_result.pos = pos;
    }
    return find_the_maximum_in_an_array_and_forced_to_do_it_recursively(arr_obj, max_result, pos + 1);
}

int main() {
    printf("How many numbers do you wanna input? ");
    int count = 0;
    while (!(scanf("%d", &count) == 1 && count > 0)) {
        printf("Invalid input, please try again: ");
        fflush(stdin);
    }
    struct array_with_len arr_obj;
    struct max_obj max;
    arr_obj.length = count;
    arr_obj.array = malloc(sizeof(long double) * count);
    for (int i = 0; i < arr_obj.length; ++i) {
        printf("Input number No. %d: ", i + 1);
        while (scanf("%Lf", arr_obj.array + i) != 1) {
            printf("Invalid input, please try again: ");
            fflush(stdin);
        }
    }
    max.pos = 0;
    max.max_value = arr_obj.array[0];
    max = find_the_maximum_in_an_array_and_forced_to_do_it_recursively(arr_obj, max, 0);
    printf("Finding complete.\n");
    printf("The maximum value is in the position %d with a value of %Lf.\n", max.pos, max.max_value);
    free(arr_obj.array);

    return 0;
}
