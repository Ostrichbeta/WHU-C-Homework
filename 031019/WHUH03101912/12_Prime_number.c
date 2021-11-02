#include <stdio.h>
//Task 12: Sort out the prime number.

int main() {
    int min, max;
    printf("From: ");
    scanf("%d", &min);
    printf("To: ");
    scanf("%d", &max);
    if (min > max || min < 2) {
        printf("Out of range.");
        return 1;
    }
    for (int i = min; i < max + 1; ++i) {
        int isPrimeNumber = 1;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) isPrimeNumber = 0;
        }
        if (isPrimeNumber) {
            printf("%d ", i);
            fflush(stdout);
        }
    }
    return 0;
}
