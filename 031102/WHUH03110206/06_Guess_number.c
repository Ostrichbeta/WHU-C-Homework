#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//Task 06: Guessing number

long double get_current_time(void) {
    struct timespec curr_time;
    timespec_get(&curr_time, TIME_UTC);
    long double nanosecond = (long double) curr_time.tv_nsec / powl(10, 9);
    long double curr_time_double = (long double)curr_time.tv_sec + nanosecond;
    return curr_time_double;
}

int main() {
    srand((int) get_current_time());
    int target_number = (rand() % 99 ) + 1;
    printf("We have written down a number(range from 1 to 99), you need to guess it.\n");
    for (int i = 0; i < 5; ++i) {
        printf("This is your %d(st/nd/rd/th) try. Input a number: ", i + 1);
        int guess = 0;
        while (scanf("%d", &guess) != 1 || guess < 1 || guess > 99) {
            printf("Invalid number. This would not be counted as your try. Input again: ");
        }
        if (target_number == guess) {
            printf("Congratulations! You get it!\n");
            break;
        } else if (guess > target_number && i != 4) {
            printf("Too large. Try a smaller one next time.\n");
        } else if (guess < target_number && i != 4) {
            printf("Too small. Try a biger one next time.\n");
        } else {
            printf("Sorry, the right number is %d.\n", target_number);
        }
    }
    return 0;
}
