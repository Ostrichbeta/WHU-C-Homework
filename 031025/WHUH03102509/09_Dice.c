#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//Task 09: Throw dices.

long double get_current_time(void) {
    struct timespec curr_time;
    timespec_get(&curr_time, TIME_UTC);
    long double nanosecond = (long double) curr_time.tv_nsec / powl(10, 9);
    long double curr_time_double = (long double)curr_time.tv_sec + nanosecond;
    return curr_time_double;
}

int main() {
    int dice_result[1000][2];
    int stat_result[6][6];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            stat_result[i][j] = 0;
        }
    }
    struct timespec seed_time;
    timespec_get(&seed_time, TIME_UTC);
    srand(seed_time.tv_nsec);
    long double initial_time = get_current_time();
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 2; ++j) {
            //Generate a random number.
            do {
                dice_result[i][j] = (rand() % 6) + 1;
            } while (dice_result[i][j] < 1 || dice_result[i][j] > 6);
        }
        // Sort the number here
        if (dice_result[i][0] >= dice_result[i][1]) {
            int swap = dice_result[i][0];
            dice_result[i][0] = dice_result[i][1];
            dice_result[i][1] = swap;
        }
        stat_result[dice_result[i][0] - 1][dice_result[i][1] - 1] ++;
        long double current_time = get_current_time();
        printf("[%.6Lf s] Dice Try %4d, got %d and %d.\n", current_time - initial_time, i + 1, dice_result[i][0], dice_result[i][1]);
    }
    printf("Generation complete.\n");
    printf(" \t 1\t 2\t 3\t 4\t 5\t 6\n");
    for (int i = 0; i < 6; ++i) {
        printf("%2d\t", i + 1);
        for (int j = 0; j < 6; ++j) {
            if (j >= i) {
                printf("%2d\t", stat_result[i][j]);
            } else {
                printf("  \t");
            }
        }
        printf("\n");
    }
    printf("\nNow check the frequency...\n");
    int max = 0;
    int max_pattern[2] = {0, 0};
    for (int i = 0; i < 6; ++i) {
        for (int j = i; j < 6; ++j) {
            if (stat_result[i][j] >= max) {
                max = stat_result[i][j];
                max_pattern[0] = i;
                max_pattern[1] = j;
            }
        }
    }
    printf("The most frequent pattern is %d with %d, its frequency is %.2lf%%.\n",
           max_pattern[0] + 1,
           max_pattern[1] + 1,
           (double) max / 10);
    return 0;
}
