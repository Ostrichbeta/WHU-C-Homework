#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//(Optional) Task 17: Find the absolute biggest number in an array
struct max_Object{
    long double largest;
    unsigned int pos;
};

struct array_with_len_Obj{
    long double *array;
    unsigned int len;
};

struct max_Object find(struct array_with_len_Obj obj){
    unsigned int max_pos = 0;
    long double max_value = obj.array[0];
    for (int i = 0; i < obj.len; ++i) {
        if (fabsl(obj.array[i]) > fabsl(max_value)) {
            max_pos = i;
            max_value = obj.array[i];
        }
    }
    struct max_Object output;
    output.pos = max_pos;
    output.largest = max_value;
    return output;
}

int main() {
    printf("How many number do you wanna input? ");
    unsigned int arr_len = 0;
    while (!(scanf("%d", &arr_len) == 1 && arr_len > 0)){
        printf("Invalid input, please try again: ");
    }
    struct array_with_len_Obj check_arr;
    // Store the array pointer and array length in a single structure for convenience.
    check_arr.array = malloc(sizeof(long double) * arr_len);
    check_arr.len = arr_len;
    for (int i = 0; i < arr_len; ++i) {
        printf("Input the number No. %d: ", i + 1);
        while (scanf("%Lf", &check_arr.array[i]) != 1) {
            printf("Invalid input, try again: ");
        }
    }
    printf("Input complete.\n");
    struct max_Object max = find(check_arr);
    printf("The absolute maximum number is %Lf, at the pos %i.", max.largest, max.pos);
    free(check_arr.array);
    return 0;
}
