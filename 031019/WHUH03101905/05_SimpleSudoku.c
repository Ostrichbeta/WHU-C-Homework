#include <stdio.h>
//Task 05: Simple Sudoku

int main() {
    int sudoku[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    for (int i = 0; i < 3; ++i) {
        while (1 == 1){
            fflush(stdout);
            printf("Input line %d, use space to separate: ", i + 1);
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            if (a >= 1 && a <= 3 && b >= 1 && b <= 3 && c >= 1 && c <= 3){
                sudoku[i][0] = a, sudoku[i][1] = b, sudoku[i][2] = c;
                break;
            }
        }
    }
    printf("Sudoku list:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    int isOK = 1;
    //Vertical check
    for (int i = 0; i < 3; ++i) {
        if(isOK){
            for (int j = 0; j < 3; ++j) {
                for (int k = j + 1; k < 3; ++k) {
                    if (sudoku[j][i] == sudoku[k][i]){
                        isOK = 0;
                    }
                }
            }
        }
    }

    // Horizon Check
    if (isOK){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = j + 1; k < 3; ++k) {
                    if (sudoku[i][j] == sudoku[i][k]){
                        isOK = 0;
                    }
                }
            }
        }
    }
    if (isOK) {
        printf("This is a simple sudoku.");
    } else {
        printf("This is not a simple sudoku.");
    }
    return 0;
}
