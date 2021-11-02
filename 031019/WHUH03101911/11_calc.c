#include <stdio.h>
//Task 11: Multi-function calculator

int main() {
    int valid[] = {0, 0, 0, 0, 0};
    float number1[5];
    char operator[] = {32, 32, 32, 32, 32};
    float number2[5];
    float result[5];
    int isExit = 0;
    do {
        printf("History result: \n");
        for (int i = 0; i < 5; ++i) {
            if (valid[i]) {
                printf("%d. %f %c %f = %f\n", i + 1, number1[i], operator[i], number2[i], result[i]);
            }
        }
        printf("\n");
        int choice = 0;
        float a;
        float b;
        float temp_result;
        printf("Choose:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n(1~5): ");
        scanf("%d", &choice);
        if (choice > 0 && choice <= 5) {
            switch (choice) {
                case 1:
                    printf("Input two number, divided by space: ");
                    scanf("%f %f", &a, &b);
                    temp_result = a + b;
                    for (int i = 4; i > 0; --i) {
                        number1[i] = number1[i - 1];
                        number2[i] = number2[i - 1];
                        operator[i] = operator[i - 1];
                        result[i] = result[i - 1];
                        valid[i] = valid[i - 1];
                    }
                    number1[0] = a;
                    number2[0] = b;
                    operator[0] = '+';
                    result[0] = temp_result;
                    valid[0] = 1;
                    break;

                case 2:
                    printf("Input two number, divided by space: ");
                    scanf("%f %f", &a, &b);
                    temp_result = a - b;
                    for (int i = 4; i > 0; --i) {
                        number1[i] = number1[i - 1];
                        number2[i] = number2[i - 1];
                        operator[i] = operator[i - 1];
                        result[i] = result[i - 1];
                        valid[i] = valid[i - 1];
                    }
                    number1[0] = a;
                    number2[0] = b;
                    operator[0] = '-';
                    result[0] = temp_result;
                    valid[0] = 1;
                    break;

                case 3:
                    printf("Input two number, divided by space: ");
                    scanf("%f %f", &a, &b);
                    temp_result = a * b;
                    for (int i = 4; i > 0; --i) {
                        number1[i] = number1[i - 1];
                        number2[i] = number2[i - 1];
                        operator[i] = operator[i - 1];
                        result[i] = result[i - 1];
                        valid[i] = valid[i - 1];
                    }
                    number1[0] = a;
                    number2[0] = b;
                    operator[0] = '*';
                    result[0] = temp_result;
                    valid[0] = 1;
                    break;

                case 4:
                    printf("Input two number, divided by space: ");
                    while (scanf("%f %f", &a, &b)!= 2 || b == 0) {
                        printf("Try again: ");
                    }
                    temp_result = a / b;
                    for (int i = 4; i > 0; --i) {
                        number1[i] = number1[i - 1];
                        number2[i] = number2[i - 1];
                        operator[i] = operator[i - 1];
                        result[i] = result[i - 1];
                        valid[i] = valid[i - 1];
                    }
                    number1[0] = a;
                    number2[0] = b;
                    operator[0] = '/';
                    result[0] = temp_result;
                    valid[0] = 1;
                    break;

                case 5:
                    isExit = 1;

                default:
                    printf("WT*.");
            }
        }
    } while (!isExit);
    return 0;
}
