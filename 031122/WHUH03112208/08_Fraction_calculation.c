#include <stdio.h>
//Task 08: Fractions

struct fraction {
    long numerator;
    long dominator;
};

typedef struct fraction fraction;

fraction simplify (fraction frac);
fraction add (fraction a, fraction b);

long get_largest_common_number(long num1, long num2){
    long a = num1, b = num2;
    if (num2 > num1){
        long swap = a;
        a = b;
        b = swap;
    }
    if (a % b == 0) {
        return b;
    } else {
        return get_largest_common_number(b, a % b);
    }
}

fraction add (fraction a, fraction b) {
    long first_fraction[2] = {a.numerator, a.dominator};
    long second_fraction[2] = {b.numerator, b.dominator};
    long addup[2] = {first_fraction[0] * second_fraction[1] + first_fraction[1] *
                     second_fraction[0], first_fraction[1] * second_fraction[1]};
    fraction addupFrac;
    addupFrac.numerator = addup[0];
    addupFrac.dominator = addup[1];
    addupFrac = simplify(addupFrac);
    return addupFrac;
}

fraction multiple (fraction a, fraction b) {
    fraction result;
    result.numerator = a.numerator * b.numerator;
    result.dominator = a.dominator * b.dominator;
    result = simplify(result);
    return result;
}

fraction simplify (fraction frac) {
    long commonNumber = get_largest_common_number(frac.numerator, frac.dominator);
    fraction result;
    result.dominator = frac.dominator / commonNumber;
    result.numerator = frac.numerator / commonNumber;
    return result;
}

void printFraction (fraction frac) {
    if (frac.dominator == 1) {
        printf("%ld", frac.numerator);
    } else if (frac.dominator != 0 && frac.numerator == 0){
        printf("0");
    } else {
        printf("%ld / %ld", frac.numerator, frac.dominator);
    }
}

int main() {
    printf("Input the first fraction, in a / b format: ");
    fraction fracA;
    while (!(scanf("%ld / %ld", &fracA.numerator, &fracA.dominator) == 2 &&
    fracA.dominator > 0 && fracA.numerator >= 0)) {
        printf("Try again: ");
    }
    printf("Input the second fraction, in a / b format: ");
    fraction fracB;
    while (!(scanf("%ld / %ld", &fracB.numerator, &fracB.dominator) == 2 &&
             fracB.dominator > 0 && fracB.numerator >= 0)) {
        printf("Try again: ");
    }
    printFraction(fracA);
    printf(" + ");
    printFraction(fracB);
    printf(" = ");
    printFraction(add(fracA, fracB));
    printf("\n");
    printFraction(fracA);
    printf(" * ");
    printFraction(fracB);
    printf(" = ");
    printFraction(multiple(fracA, fracB));
    return 0;
}
