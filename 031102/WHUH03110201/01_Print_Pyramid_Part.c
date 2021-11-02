#include <stdio.h>
//Task 01: Print a half of pyramid

int main() {
    for (int i = 0; i < 4; ++i) {
        int star_count = 4 + 2 * i;
        int left_blank = (10 - star_count) / 2;
        for (int j = 0; j < left_blank; ++j) {
            printf("  ");
        }
        for (int j = 0; j < star_count; ++j) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
