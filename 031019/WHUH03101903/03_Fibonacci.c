#include <stdio.h>
//Task 03: Fibonacci Number

int fibo(int n){
    if (n == 1 || n == 2){
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main() {
    int count = 0;
    printf("Input how much number do you want to see: ");
    scanf("%d", &count);
    for (int i = 1; i <= count; ++i) {
        printf("%d ", fibo(i));
        fflush(stdout);
    }
    return 0;
}
