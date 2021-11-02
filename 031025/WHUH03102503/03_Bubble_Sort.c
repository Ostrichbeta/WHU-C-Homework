#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//Task 03: Sorting using bubble sort.

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
    srand((int)curr_time.tv_nsec);
    do {
        num = rand();
    } while (num < min || num > max);
    return num;
}

int main() {
    int num_list[10];
    long double initial_time = get_current_time();
    for (int i = 0; i < 9; ++i) {
        num_list[i] = range_random_number(1, 99);
        long double current_time = get_current_time();
        printf("[%3.2Lf s] Got %d.\n", current_time - initial_time, num_list[i]);
    }
    printf("Generation Complete. Start sorting process...\n");
    initial_time = get_current_time();
    int swap_count = 0;
    int compare_count = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            long double current_time = get_current_time();
            compare_count++;
            printf("[%.6Lf s] %d compare(s) have/has been made.\n", current_time - initial_time, compare_count);
            if (num_list[i] <= num_list[j]) {
                int swap = num_list[i];
                num_list[j] = num_list[i];
                num_list[i] = swap;
                swap_count++;
                printf("[%.6Lf s] %d swap(s) have/has been made.\n", current_time - initial_time, swap_count);
            }
        }
    }
    return 0;
}
