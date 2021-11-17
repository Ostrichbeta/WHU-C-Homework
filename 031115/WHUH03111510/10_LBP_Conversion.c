#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Task 10: Local binary pattern calculation

int binray_char_to_decimal ( char *str){
    int result = 0;
    for (int i = 0; i < 8; ++i) {
        if (str[i] == '1') {
            result += (int) pow(2, 7 - i);
        }
    }
    return result;
};

int LBP_convert(int **arr){
    int **comparison = arr;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!(i == 1 && j == 1)) {
                comparison[i][j] = comparison[i][j] > comparison[1][1] ? 1 : 0;
            }
        }
    }
    char binary_char[9];
    for (int i = 0; i <= 2; ++i) {
        binary_char[i] = comparison[0][i] == 0 ? '0' : '1';
    }
    binary_char[3] = comparison[1][2] == 0 ? '0' : '1';
    for (int i = 6; i >= 4; --i) {
        binary_char[i] = comparison[2][i - 4] == 0 ? '0' : '1';
    }
    binary_char[7] = comparison[1][0] == 0 ? '0' : '1';
    printf("Binary char: %s\n", binary_char);
    return binray_char_to_decimal(binary_char);
}

int main() {
    int **matrix = malloc(3 * sizeof(long*));
    for (int i = 0; i < 3; ++i) {
        matrix[i] = malloc(3 * sizeof(long));
    }
    for (int i = 0; i < 3; ++i) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < 3; ++j) {
            printf("Column %d, it must be larger than zero: ", j + 1);
            while (!(scanf("%d", &matrix[i][j]) == 1 && matrix[i][j] > 0)) {
                printf("Invalid input, please try again: ");
            }
        }
    }
    int LBP_Value = LBP_convert(matrix);
    printf("Result: %d.\n", LBP_Value);
    return 0;
}
