#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//Task 02: Add up numbers

long double get_current_time(void) {
    struct timespec curr_time;
    timespec_get(&curr_time, TIME_UTC);
    long double nanosecond = (long double) curr_time.tv_nsec / powl(10, 9);
    long double curr_time_double = (long double)curr_time.tv_sec + nanosecond;
    return curr_time_double;
}

int main() {
    long n;
    long result = 0;
    printf("Calculate 1+(1+2)+(1+2+3)+...+(1+2+3+...+n). n = ");
    scanf("%ld", &n);
    long double initial_time = get_current_time();
    for (long i = 1; i <= n; ++i) {
        for (long j = 1; j <= i; ++j) {
            result += j;
            printf("[%.6Lf s] i = %ld, Result is now %ld.\n", get_current_time() - initial_time, i, result);
            fflush(stdout);
        }
    }
    printf("The final result is %ld.\n", result);
    return 0;
}
