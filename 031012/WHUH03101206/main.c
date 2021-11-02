#include <stdio.h>
#include <math.h>
//Task 06: Solver the piecewise function.

int main() {
    double x;
    printf("Assign a value to x: ");
    scanf("%lf", &x);
    if (x >= 0){
        printf("f(%lf) = %lf", x, pow(x - 2, 2) - 7);
    } else {
        printf("f(%lf) = %lf", x, 4 * x - 3);
    }
    return 0;
}
