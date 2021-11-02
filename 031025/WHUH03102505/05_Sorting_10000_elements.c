#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#if defined(_WIN32)
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#endif
//Task 05: Sorting a big array.


long double get_current_time(void) {
#ifdef __APPLE__
    struct timespec curr_time;
    timespec_get(&curr_time, TIME_UTC);
    long double nanosecond = (long double) curr_time.tv_nsec / powl(10, 9);
    long double curr_time_double = (long double)curr_time.tv_sec + nanosecond;
#else
    DWORD curr_time = timeGetTime();
    long double curr_time_double = (long double) curr_time / 1000;
#endif
    return curr_time_double;


}

int range_random_number(int min, int max) {
    int num = 0;
#ifdef __APPLE__
    struct timespec curr_time;
    timespec_get(&curr_time, TIME_UTC);
    srand((int)curr_time.tv_nsec);
#else
    DWORD btime = timeGetTime();
    srand((int)timeGetTime());
#endif
    do {
        num = rand();
    } while (num < min || num > max);
    return num;
}

int main() {
#if defined(_WIN32)
    int i, j;
    long double sorting_done_time;
#endif
    long double initial_time = get_current_time();
    int num_list[10000];
#if defined(__APPLE__)
    for (int i = 0; i < 10000; ++i) {
#else
    DWORD btime = timeGetTime();
    srand((int)timeGetTime());
    for (i = 0; i < 10000; ++i) {
#endif
#if defined(__APPLE__)
        num_list[i] = range_random_number(1, 9999);
#else
        do {
            num_list[i] = rand();
        } while (num_list[i] > 9999 || num_list[i] < 1);
#endif
        printf("[%.6Lf s] Number %d is %d.\n", get_current_time() - initial_time, i + 1, num_list[i]);
        fflush(stdout);
    }

    printf("Start sorting...\n");
    initial_time = get_current_time();
#if defined(__APPLE__)
    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < 10000; ++j) {
#else
    for (i = 0; i < 10000; ++i) {
        for (j = 0; j < 10000; ++j) {
#endif
            if (num_list[i] <= num_list[j]){
                int swap = num_list[i];
                num_list[i] = num_list[j];
                num_list[j] = swap;
            }
        }
    }
#if defined(__APPLE__)
    long double sorting_done_time = get_current_time();
#else
    sorting_done_time = get_current_time();
#endif
//    printf("After sorted:");
//    for (int i = 0; i < 10000; ++i) {
//        if (i == 9999){
//            printf(" %d.\n", num_list[i]);
//        } else {
//            printf(" %d,", num_list[i]);
//        }
//    }
    printf("Sorting complete in %.3Lf s.", sorting_done_time - initial_time);
#if defined(_WIN32)
    scanf_s("%d", &i);
#endif
    //Time:
    //macOS 11.6 Release: ~0.34s (Clion 2021.1)
    //macOS 11.6 Debug: ~0.30s (Clion 2021.1)
    //Windows 7 Release: ~0.062s (Visual Studio 2012 Ultimate)
    //Windows 7 Debug: ~0.187s
    return 0;
}
