#include <stdio.h>
#include <stdlib.h>

//Task 10: Divide a number to the sum of several contiguous numbers.
int main() {
    long original_num;
    int is_dividable = 0;
    printf("Input a number that larger than zero: ");
    while (!(scanf("%ld", &original_num) == 1 && original_num > 0)){
        printf("Invalid number, try again: ");
    }
    for (long i = 1; i < original_num; ++i) {
        long attempt_num = 0;
        long j = 0;
        for (j = i; j < original_num; ++j) {
            attempt_num += j;
            if (original_num == attempt_num) {
                printf("%ld = %ld", original_num, i);
                //Truncate long lines into short lines
                int k_count = 0;
                long last_k = 0;
                for (long k = i + 1; k <= j; ++k) {
                    k_count ++;
                    last_k = k;
                    if (k_count < 4) {
                        printf(" + %ld", k);
                    }
                }
                if (k_count > 4){
                    printf(" + ... + %ld", last_k);
                }
                printf("\n");
                is_dividable = 1;
                break;
            } else if (original_num < attempt_num) {
                break;
            }
        }
    }
    if (!is_dividable) {
        printf("NONE");
    }
    return 0;
}
