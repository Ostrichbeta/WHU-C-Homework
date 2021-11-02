#include <stdio.h>
//Task 01: Pointer test

int main(){
    // Note: Two pointers cannot be added.
    double a = 1822;
    double b = 4.5;
    double *c = &a;
    double *d = &b;
    printf("*c + *d = %lf\n", *c + *d);
    printf("*c - *d = %lf\n", *c - *d);
    printf("c: %p\n", c);
    printf("*c + 5 = %lf, %p\n", c + 5, c + 1);
    printf("*c - 5 = %lf, %p\n", c - 5, c - 1);
    return 0;
}
