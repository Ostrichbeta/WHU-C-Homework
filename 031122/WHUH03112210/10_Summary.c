#include <stdio.h>
//Task 10: get the first Nth number's summary

unsigned long sumRecursively(unsigned long n) {
    return n == 1 ? 1: n + sumRecursively(n - 1);
}

unsigned long sumLoopy(unsigned long n) {
    unsigned long result = 0;
    for (unsigned long i = 1; i <= n; ++i) {
        result += i;
    }
    return result;
}

int main() {
    printf("Input a number that larger than zero: ");
    long n;
    while (!(scanf("%ld", &n) == 1 && n > 0)) {
        printf("Try again: ");
    }
    printf("Answer (Recursively): %ld.\n", sumRecursively(n));
    printf("Answer (Loopy): %ld.\n", sumLoopy(n));
    return 0;
}
