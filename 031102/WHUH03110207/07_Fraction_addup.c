#include <stdio.h>
//Task 07: add up two fractions.
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

int main() {
    printf("Input two fractions.\n");
    long first_fraction[2] = {0, 0};
    long second_fraction[2] = {0, 0};
    printf("Input the first one, in a/b format: ");
    while (!(scanf("%ld/%ld", &first_fraction[0], &first_fraction[1]) == 2 || first_fraction[1] != 0)){
        printf("Invalid, try again: ");
    }
    printf("Input the second one, in a/b format: ");
    while (!(scanf("%ld/%ld", &second_fraction[0], &second_fraction[1]) == 2 || second_fraction[1] != 0)){
        printf("Invalid, try again: ");
    }
    long addup[2] = {first_fraction[0] * second_fraction[1] + first_fraction[1] * second_fraction[0], first_fraction[1] * second_fraction[1]};
    long maxinum_common_number = get_largest_common_number(addup[0], addup[1]);
    addup[0] /= maxinum_common_number;
    addup[1] /= maxinum_common_number;
    if (addup[1] != 1) {
        printf("%ld/%ld + %ld/%ld = %ld/%ld\n", first_fraction[0], first_fraction[1],
                                                second_fraction[0], second_fraction[1],
                                                addup[0], addup[1]);
    } else {
        printf("%ld/%ld + %ld/%ld = %ld\n", first_fraction[0], first_fraction[1],
                                                second_fraction[0], second_fraction[1],
                                                addup[0]);
    }
    return 0;
}
