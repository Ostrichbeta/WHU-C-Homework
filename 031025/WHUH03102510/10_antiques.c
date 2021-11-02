#include <stdio.h>
#include <string.h>
//Task 10: Dynasty investigation.

int main() {
    //Define Song as the first element, and Qing as the second.
    int stupid[3][2];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            stupid[i][j] = 0;
        }
    }
    //The first stupid
    stupid[0][0] = 0, stupid[0][1] = 0;
    //The second stupid
    stupid[1][0] = 1, stupid[1][1] = 0;
    //The third stupid
    stupid[2][0] = 0, stupid[2][1] = 1;
    //Set the correct answer. 0 stands for Song, 1 stands for Qing,
    //2 stands for none of these, 3 stands for not calculated.
    int correct = 3;

    for (int i = 0; i < 3; ++i) {
        // Define i as the totally correct answer.
        for (int j = 0; j < 3; ++j) {
            //Define j as the partly correct answer.
            int other_index = 4;
            for (int k = 0; k < 3; ++k) {
                if (k != i && k != j) other_index = k;
            }
            if (i == j) continue;
                if (((stupid[i][0] == stupid[j][0] && stupid[i][1] != stupid[j][1]) ||
                (stupid[i][1] == stupid[j][1] && stupid[i][0] != stupid[j][0])) &&
                (stupid[i][0] != stupid[other_index][0] && stupid[i][1] != stupid[other_index][1]))
                {
                    if (stupid[i][0] == 1){
                        correct = 0;
                    } else if (stupid[i][1] == 1){
                        correct = 1;
                    } else {
                        correct = 2;
                    }
                    char dynasty[10];
                    switch (correct) {
                        case 0:
                            strcpy(dynasty, "Song");
                            break;

                        case 1:
                            strcpy(dynasty, "Qing");
                            break;

                        case 2:
                            strcpy(dynasty, "Unknown");
                            break;

                        default:
                            strcpy(dynasty, "<Error>");
                    }
                    printf("Person %d is all correct, "
                           "person %d is partly correct, "
                           "and person %d is completely wrong.\n"
                           "The antique is from %s Dynasty.\n\n",
                           i + 1, j + 1, other_index + 1, dynasty);
                }

        }

    }
    return 0;
}
