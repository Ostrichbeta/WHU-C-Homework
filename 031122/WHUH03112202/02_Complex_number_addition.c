#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Task 02: Complex number addition

struct complex {
    long double real;
    long double imaginary;
};

typedef struct complex complex;

complex addition (complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

complex subtraction (complex a, complex b) {
    complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

complex multiplication (complex a, complex b) {
    complex result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + b.real * a.imaginary;
    return result;
}

complex division (complex a, complex b) {
    complex result;
    if (powl(b.real, 2) + powl(b.imaginary, 2) == 0) {
        printf("Cannot divided by zero");
    }
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / (powl(b.real, 2) + powl(b.imaginary, 2));
    result.imaginary = (b.real * a.imaginary - a.real * b.imaginary) / (powl(b.real, 2) + powl(b.imaginary, 2));
    return result;
}

void print_complex (complex num) {
    if (num.imaginary == 0) {
        printf("%Lf", num.real);
    } else if (num.imaginary != 0 && num.real == 0) {
        printf("%Lfi", num.imaginary);
    } else {
        printf("(%Lf + %Lfi)", num.real, num.imaginary);
    }
}

int main() {
    complex numlist[2];
    for (int i = 0; i < 2; ++i) {
        printf("Enter the complex number No. %d, with the format real, imaginary: ", i + 1);
        while (scanf("%Lf, %Lf", &numlist[i].real, &numlist[i].imaginary) != 2) {
            printf("Invalid input, please try again: ");
        }
    }
    printf("What calculation do you wanna do?\n"
           "1. Addition\n"
           "2. Subtraction\n"
           "3. Multiplication\n"
           "4. Division.\n"
           "Enter your choice: ");
    int choice;
    while (!(scanf("%d", &choice) == 1 && choice >= 1 && choice <= 4)) {
        printf("Invalid input, please try again: ");
    }
    complex result;
    char calc_char = ' ';
    switch (choice) {
        case 1:
            calc_char = '+';
            result = addition(numlist[0], numlist[1]);
            break;

        case 2:
            calc_char = '-';
            result = subtraction(numlist[0], numlist[1]);
            break;

        case 3:
            calc_char = '*';
            result = multiplication(numlist[0], numlist[1]);
            break;

        case 4:
            calc_char = '/';
            result = division(numlist[0], numlist[1]);
            break;

        default:
            printf("Error!");
            exit(139);
    }
    //Output the equation
    print_complex(numlist[0]);
    printf(" %c ", calc_char);
    print_complex(numlist[1]);
    printf(" = ");
    print_complex(result);
    printf("\n");
    return 0;
}
