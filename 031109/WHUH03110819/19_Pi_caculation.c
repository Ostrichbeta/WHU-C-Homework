#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//(Optional) Task 19: Calculate the value of pi using the Ramanujan Formula

long double factorial(long double n){
    if (n == 0) return 1;
    if (n - floorl(n) != 0) return -1;
    if (n == 1) return 1; else return factorial(n - 1) * n;
}

void pi_calc(long double *pi_pointer, long double toleration, long double times){
    long double next_number = 1 / ( (*pi_pointer == 0 ? 0 : 1 / *pi_pointer) +
            1 / (2 * sqrtl(3)) * (((8 * times) + 1) * factorial(4 * times)) /
            (powl(4 * sqrtl(3), 4 * times) * powl(factorial(times), 4)));
    printf("[%.0Lf] Current value: %.15Lf\n", times + 1, *pi_pointer);
    fflush(stdout);
    if (fabsl(next_number - *pi_pointer) <= toleration) {
        return;
    } else {
        *pi_pointer = next_number;
        pi_calc(pi_pointer, toleration, times + 1);
    }
}

int main() {
    long double pi_value = 0;
    long double toleration = 0;
    printf("Input the toleration, expressed in scientific notation: ");
    while (!(scanf("%Le", &toleration) == 1 && toleration >= 0)){
        printf("Invalid input, please try again: ");
    }
    long double *pi_pointer = &pi_value;
    printf("Calculating...\n");
    pi_calc(pi_pointer, toleration, 0);
    printf("The final value of pi is %.15Lf", *pi_pointer);
    return 0;
}
