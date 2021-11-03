#include <stdio.h>
//Task 08: Mathematical Blackhole

int verify_number(int num){
    if (num < 1000 || num > 9999) return 0;
    int digit[4];
    digit[0] = num / 1000,
    digit[1] = (num / 100) % 10,
    digit[2] = (num / 10) % 10,
    digit[3] = num % 10;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (digit[i] == digit[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int sort_number(int num, int reverse){
    int digit[4];
    digit[0] = num / 1000,
    digit[1] = (num / 100) % 10,
    digit[2] = (num / 10) % 10,
    digit[3] = num % 10;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!reverse) {
                if (digit[i] <= digit[j]) {
                    int swap = digit[i];
                    digit[i] = digit[j];
                    digit[j] = swap;
                }
            } else {
                if (digit[i] >= digit[j]) {
                    int swap = digit[i];
                    digit[i] = digit[j];
                    digit[j] = swap;
                }
            }
        }
    }
    return digit[0] * 1000 + digit[1] * 100 + digit[2] * 10 + digit[3];
}

int main() {
    int initial_num = 0;
    printf("Input a 4-digit number: ");
    while (!(scanf("%d", &initial_num) == 1 && verify_number(initial_num))) {
        printf("Invalid number. Try again: ");
    }
    int count = 0;
    do {
        count++;
        int maxsort = sort_number(initial_num, 1);
        int minsort = sort_number(initial_num, 0);
        initial_num = maxsort - minsort;
    } while (initial_num != 6174);
    printf("Done %d count(s).", count);
    return 0;
}
