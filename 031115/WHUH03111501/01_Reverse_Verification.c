#include <stdio.h>
#include <stdlib.h>
//Task 01: Verify an array reversal function
void reverse(int *x,int n) {
    int *p, temp, *i, *j;
    i = x;
    j = x + n - 1;
    p = x + (n - 1) / 2;
    for (; i <= p; i++, j--) {
        temp = *i;
        *i = *j;
        *j = temp;
    }
}


int main() {
    printf("How many numbers do you wanna input? ");
    int count;
    while (!(scanf("%d", &count) == 1 && count > 0)) {
        printf("Invalid input, please try again: ");
    }
    int *array = malloc(sizeof(int) * count);
    for (int i = 0; i < count; ++i) {
        printf("Input the integer number No. %d: ", i + 1);
        while (scanf("%d", array + i) != 1) {
            fflush(stdin);
            printf("Invalid input, please try again: ");
        }
    }
    printf("Input complete.\nBefore reversal: \n");
    for (int i = 0; i < count; ++i) {
        printf("array[%d] = %d\n", i, *(array + i));
    }
    reverse(array, count);
    printf("After reversal: \n");
    for (int i = 0; i < count; ++i) {
        printf("array[%d] = %d\n", i, *(array + i));
    }
    return 0;
}
//Analysis: i if the first address of the given array while j is the last address.
// p is the middle address, e.g. i + 2 while j = i + 4 (length 5) and j = i + 5. (length 6)
//This will make sure that elements won't be exchanged twice.

