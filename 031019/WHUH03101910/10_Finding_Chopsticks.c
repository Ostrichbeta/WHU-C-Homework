#include <stdio.h>
//Task 10: Finding chopsticks

int main() {
    printf("Input the length of remaining chopsticks: ");
    int chopsticks[7];
    while (scanf("%d %d %d %d %d %d %d", &chopsticks[0],
                 &chopsticks[1],
                 &chopsticks[2],
                 &chopsticks[3],
                 &chopsticks[4],
                 &chopsticks[5],
                 &chopsticks[6]) != 7) {
        printf("Try again: ");
    }
    int dup[] = {0, 0, 0, 0, 0, 0, 0};
    int pos = 0;
    int isHas = 0;
    for (int i = 0; i < 7; ++i) {
        for (int j = i + 1; j < 7; ++j) {
            if (chopsticks[i] == chopsticks[j]) {
                for (int k = 0; k < 7; ++k) {
                    if (dup[k] == chopsticks[i]) {
                        isHas = 1; break;
                    }
                }
                if (!isHas) {
                    dup[pos] = chopsticks[i];
                    pos ++;
                } else {
                    isHas = 0;
                }
            }
        }
    }
        printf("We have chopstick(s) in length: ");
        for (int i = 0; i < 7; ++i) {
            if (dup[i] == 0) break;
            printf("%d ", dup[i]);
        }
        printf("\n");
        for (int i = 0; i < 7; ++i) {
            int isInList = 0;
            int curr_length;
            for (int j = 0; j < 7; ++j) {
                curr_length = chopsticks[j];
                if (chopsticks[j] == dup[i]){
                    isInList = 1;
                }
            }
            if (!isInList) {
                printf("Chopstick with a length of %d has been abandoned.\n", curr_length);
            }
            isInList = 0;
        }

    return 0;
}
