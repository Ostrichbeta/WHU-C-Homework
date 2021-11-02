#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//Task 04: Seeded random number list.

long double get_current_time(void) {
    struct timespec curr_time;
    timespec_get(&curr_time, TIME_UTC);
    long double nanosecond = (long double) curr_time.tv_nsec / powl(10, 9);
    long double curr_time_double = (long double)curr_time.tv_sec + nanosecond;
    return curr_time_double;
}


int main() {
    srand(111);
    int a[100];
    long double initial_time = get_current_time();
    for (int i = 0; i < 100; ++i) {
        int random_number = 0;
        do {
            random_number = rand();
        } while (random_number > 199 || random_number < 1);
        long double current_time = get_current_time();
        printf("[%4.3Lf s] Number %d is %d.\n", current_time - initial_time, i + 1, random_number);
        fflush(stdout);
        a[i] = random_number;
    }
    printf("\nStart sorting...\n");
    initial_time = get_current_time();
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (a[i] <= a[j]){
                int swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
        }
        if (i == 9) {
            for (int j = 29; j < 39 ; ++j) {
                printf("[%.6Lf s] a[%d] = %d\n", get_current_time() - initial_time, j, a[j]);
            }
        }
    }
    //The 30th element to 39th element in the 10th process.
    //[0.000003 s] a[29] = 140
    //[0.000023 s] a[30] = 101
    //[0.000027 s] a[31] = 108
    //[0.000029 s] a[32] = 130
    //[0.000031 s] a[33] = 37
    //[0.000034 s] a[34] = 7
    //[0.000036 s] a[35] = 60
    //[0.000038 s] a[36] = 194
    //[0.000041 s] a[37] = 3
    //[0.000043 s] a[38] = 106
    return 0;
}
