#include <stdio.h>
//Task 06: Constantly input numbers, when the number is prime number, the program will exit.

int is_prime_number(long num){
    int isPrimeNumber = 1;
    for (long j = 2; j < num; ++j) {
        if (num % j == 0 && num != j) isPrimeNumber = 0;
    }
    if (isPrimeNumber) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    long num = 0;
    do {
        printf("Input a integer number: ");
    } while (!(scanf("%ld", &num) == 1 && num >= 2 && is_prime_number(num)));
    printf("%ld is prime number, exit now.", num);
    return 0;
}
