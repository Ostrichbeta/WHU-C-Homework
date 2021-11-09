#include <stdio.h>
#include <stdlib.h>
//(Optional) Task 13: Encapsulate the bubble sort algorithm into a function.

void bubble_sort(int *array, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (array[i] >= array[j]) {
                int swap = array[i];
                array[i] = array[j];
                array[j] = swap;
            }
        }
    }
}

int main() {
    int array_len = 5;
    int *num_array = malloc(array_len * sizeof(int));
    printf("Input five numbers, divided by comma: ");
    while (scanf("%d, %d, %d, %d, %d", &num_array[0], &num_array[1], &num_array[2], &num_array[3], &num_array[4]) != 5){
        printf("Invalid input, try again: ");
    }
    bubble_sort(num_array, 5);
    printf("Sorted array: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", num_array[i]);
    }
    free(num_array);
    printf("\n");
    return 0;
}
