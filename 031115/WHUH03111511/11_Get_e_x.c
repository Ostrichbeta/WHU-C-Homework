#include <stdio.h>
#include <math.h>
//Task 11: Get e^x when x = 1 or 2 or 3

long double factorial (long double x) {
    if (fabsl(x - 1) <= 0.0001 || fabsl(x - 0) <= 0.0001) return 1; else return x * factorial(x - 1);
}

long double ex(long double x) {
    long double result = 1;
    for (int i = 1; i < 30; ++i) {
        result += powl(x, i) / factorial(i);
    }
    return result;
}

int main() {
    printf("e^1 = %Lf, e^2 = %Lf and e^3 = %Lf\n", ex(1), ex(2), ex(3));
    return 0;
}
