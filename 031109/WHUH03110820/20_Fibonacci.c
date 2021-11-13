#include <stdio.h>
//(Optional) Task 20: Get the nth number of Fibonacci list
unsigned long fibonacci(unsigned long n) {
    if (n == 1 || n == 2) return 1; else return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
    long pos = 0;
    printf("Which number in the array would you like to get: ");
    while (!(scanf("%ld", &pos) == 1 && pos > 0)) {
        printf("Invalid input, please try again: ");
    }
    printf("The %ld(st/nd/rd/th) number of the Fibonacci list is %ld.\n", pos, fibonacci((unsigned long) pos));
    return 0;
}
