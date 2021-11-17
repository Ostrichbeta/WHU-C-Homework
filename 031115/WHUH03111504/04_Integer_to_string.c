#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Task 04: Recursively convert a integer into string
int get_digit (long num, int digits) {
    long k = num / 10;
    if (num / 10 >= 1) {
        return get_digit(num / 10, digits + 1);
    } else {
        return digits + 1;
    }
}

int main() {
    printf("Input a integer number, it can be less than zero: ");
    long num = 0;
    while (scanf("%ld", &num) != 1) {
        printf("Invalid input, please try again: ");
        fflush(stdin);
    }
    int digit_with_mark = num >= 0 ? get_digit(num, 0) : get_digit(0 - num, 0) + 1;
    char *num_str = malloc(sizeof(char) * digit_with_mark + 1);
    if (num < 0) num_str[0] = '-';
    for (int i = num >= 0 ? 0 : 1; i < digit_with_mark; ++i) {
        long process_num = num >= 0 ? num : 0 - num;
        int digit = num >= 0 ? digit_with_mark : digit_with_mark - 1;
        num_str[i] = ((process_num / (long) pow(10, digit - 1 - (num >= 0 ? i : i - 1))) % 10) + 48;
    }
    printf("Result in string: %s\n", num_str);
    return 0;
}
