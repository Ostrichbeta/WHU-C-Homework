#include <stdio.h>
#include <stdlib.h>
//Task 09: Get the nth number of Fibonacci array using two ways

unsigned long fibonacciRecursively(unsigned long n) {
    if (n == 1 || n == 2) return 1; else return fibonacciRecursively(n - 2) + fibonacciRecursively(n - 1);
}

unsigned long fibonacciLoopy(unsigned long n) {
    if (n == 1 || n == 2) return 1; else {
        long *fibonacciArray = malloc(n * sizeof(long));
        fibonacciArray[0] = fibonacciArray[1] = 1;
        for (int i = 2; i < n; ++i) {
            fibonacciArray[i] = fibonacciArray[i - 1] + fibonacciArray[i - 2];
        }
        long result = fibonacciArray[n - 1];
        free(fibonacciArray);
        return result;
    }
}


int main() {
    printf("Input the position of the array: ");
    long pos = 0;
    while (!(scanf("%ld", &pos) == 1 && pos > 0)) {
        printf("Try again: ");
    }
    printf("Answer (Recursive way): %ld.\n", fibonacciRecursively(pos));
    printf("Answer (Loopy way): %ld.\n", fibonacciLoopy(pos));
    return 0;
}
