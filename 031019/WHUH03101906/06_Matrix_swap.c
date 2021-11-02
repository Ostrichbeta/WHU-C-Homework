#include <stdio.h>
//Task 06: Swap the matrix's line and row;

int main() {
    int matrix[3][3];
    for (int i = 0; i < 3; ++i) {
        printf("Input line %d, use space to separate:\n", i + 1);
        while (scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]) != 3);
    }
    printf("Before: \n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    //Convertion
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            int swap = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = swap;
        }
    }
    printf("After: \n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
