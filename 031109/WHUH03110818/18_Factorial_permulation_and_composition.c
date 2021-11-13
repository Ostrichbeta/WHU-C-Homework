#include <stdio.h>
#include <stdlib.h>
//(Optional) Task 18: Make factorial, permutation and composition into three different functions.

long factorial(long n){
    if (n == 1) {
        return n;
    } else {
        return factorial( n - 1 ) * n;
    }
}

long permutation(long n, long  m) {
    return factorial(m) / factorial(m - n);
}


long composition(long n, long m) {
    return permutation(n, m) / factorial(n);
}

int main() {
    printf("What calculations do you want?\n"
           "1. Permutation\n2. Composition\n"
           "3. Factorial\n4. Exit\nInput your choice (1, 2, 3 or 4): ");
    int choice = 0;
    while (!scanf("%d", &choice) == 1 && choice >= 1 && choice <= 4) {
        printf("Invalid input, please try again: ");
    }
    switch (choice) {
        long j, k;
        case 3:
            printf("Input a integer number that larger than or equal to zero: ");
            long num = 0;
            while (!(scanf("%ld", &num)== 1 && num >= 0)) {
                printf("Invalid input, please try again: ");
            }
            printf("The factorial of %ld is %ld.\n\n\n", num, factorial(num));
            break;

        case 1:
            printf("Input two integer number j and k to make a permutation calculation. j <= k: ");
            while (!(scanf("%ld, %ld", &j, &k) == 2 && j <= k)) {
                printf("Invalid input, please try again: ");
            }
            printf("%ld P %ld is %ld.\n\n\n", j, k, permutation(j, k));
            break;

        case 2:
            printf("Input two integer number j and k to make a composition calculation. j <= k: ");
            while (!(scanf("%ld, %ld", &j, &k) == 2 && j <= k)) {
                printf("Invalid input, please try again: ");
            }
            printf("%ld C %ld is %ld.\n\n\n", j, k, composition(j, k));
            break;

        case 4:
            exit(0);
            break;

        default:
            exit(0);
    }
    return 0;
}
