#include <stdio.h>
#include <math.h>
//Task 09: Square root.
long double square_root(long double num, long double original) {
    long double calc = 0.5 * (num + original / num);
    if (fabsl(calc - num) <= powl(10, -5)){
        return calc;
    } else {
        return square_root(calc, original);
    }
}

int main() {
    long double original_number = 0;
    printf("Import a number that larger than zero: \n");
    while (!(scanf("%Lf", &original_number) == 1 && original_number > 0)) {
        printf("Invalid number, try again: ");
    }
    if (original_number == 1){
        printf("sqrt(1) is just 1.\n");
        return 0;
    }
    printf("sqrt(%Lf) is %Lf.", original_number, square_root(original_number, original_number));
    return 0;
}
