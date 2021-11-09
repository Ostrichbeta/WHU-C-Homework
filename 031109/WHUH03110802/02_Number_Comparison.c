#include <stdio.h>
//Task 02: Write a function that can pick the largest number in three

int threeinone(int a, int b, int c) {
    if (a > b){
        if (a > c) {
            return a;
        } else return c;
    } else {
        if (c > b) return c; else
            return b;
    }
}

int main(){
    printf("Input three numbers, divided by period and space. E.g. 3, 6, 9: ");
    int a, b, c;
    while (scanf("%d, %d, %d", &a, &b, &c) != 3) {
        printf("Invalid input, try again: ");
    }
    printf("The maximum is %d.\n", threeinone(a, b, c));
}
