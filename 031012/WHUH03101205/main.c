#include <stdio.h>
#include <math.h>
#include <complex.h>
//Task 05: Solving quadratic equation

int main() {
    double a, b, c;
    printf("What you input will be automatically rounded to two decimal places when displayed.\n");
    printf("Please input __ x^2 + b x + c = 0 : ");
    scanf("%lf", &a);
    printf("Please input %.2lf x^2 + __ x + c = 0 : ", a);
    scanf("%lf", &b);
    printf("Please input %.2lf x^2 + %.2lf x + __ = 0 : ", a, b);
    scanf("%lf", &c);
    printf("Your equation is %.2lf x^2 + %.2lf x + %.2lf = 0.\n", a, b, c);
    if (a != 0) {
        double delta = (b * b - 4 * a * c);
        double solution0, solution1;
        if (delta == 0) {
            solution0 = (0 - b) / (a * a);
            solution1 = solution0;
        }
        if (delta >= 0) {
            solution0 = ((-1 * b) + sqrt(delta)) / 2 * a;
            solution1 = ((-1 * b) - sqrt(delta)) / 2 * a;
            printf("The solutions are %.2lf and %.2lf.\n", solution0, solution1);
        }
        if (delta < 0){
            printf("The solutions are complex numbers.\n");
            double complex solution2 = ((-1 * b) + csqrt(delta)) / 2 * a;
            double complex solution3 = ((-1 * b) - csqrt(delta)) / 2 * a;
            printf("The solutions are %.2lf + %.2lf i and %.2lf + %.2lf i.\n", creal(solution2), cimag(solution2),
                   creal(solution3), cimag(solution3));

        }

    } else {
        double solution0 = (-1 * c) / b;
        printf("The solution is %.2lf.\n", solution0);
    }

    return 0;
}
