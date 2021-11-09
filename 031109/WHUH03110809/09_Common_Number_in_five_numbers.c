#include <stdio.h>

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

long min(const long a[]) {
    long min = a[0];
    for (int i = 0; i < 5; ++i) {
        if (a[i] < a[0]) min = a[i];
    }
    return min;
}


int main() {
    printf("Input five numbers, divided by commas (e.g. a, b, c, d, e): ");
    long num[5];
    while (!(scanf("%ld, %ld, %ld, %ld, %ld", &num[0], &num[1], &num[2], &num[3], &num[4]) == 5 && min(num) > 0)){
        printf("Invalid input, please try again: ");
    }
    long common_number = get_largest_common_number(num[0], num[1]);
    for (int i = 2; i < 5; ++i) {
        common_number = get_largest_common_number(common_number, num[i]);
    }
    printf("The common number of the given numbers is %ld.\n", common_number);

    return 0;
}
