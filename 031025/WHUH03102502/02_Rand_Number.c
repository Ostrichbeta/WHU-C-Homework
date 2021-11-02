#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//Task 02: Random number list

long double get_current_time(void) {
    struct timespec curr_time;
    timespec_get(&curr_time, TIME_UTC);
    long double nanosecond = (long double) curr_time.tv_nsec / powl(10, 9);
    long double curr_time_double = (long double)curr_time.tv_sec + nanosecond;
    return curr_time_double;
}

int range_random_number(int min, int max) {
    int num = 0;
    struct timespec curr_time;
    timespec_get(&curr_time, TIME_UTC);
    srand((int)curr_time.tv_sec);
    do {
        num = rand();
    } while (num < min || num > max);
    return num;
}

int main() {
    double initial_time = get_current_time();
    int num_list[100];
    int stat[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 100; ++i) {
        int rand_num = range_random_number(0, 9);
        double curr_time = get_current_time();
        printf("[%03d/100][%6.2f s] Got %d.\n", i + 1, (curr_time - initial_time), rand_num);
        fflush(stdout);
        num_list[i] = rand_num;
        stat[num_list[i]]++;
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        printf("Number %d has appeared %d time(s).\n", i, stat[i]);
    }

    return 0;
}
