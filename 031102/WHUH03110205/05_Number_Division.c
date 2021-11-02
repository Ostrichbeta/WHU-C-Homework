#include <stdio.h>
#include <stdlib.h>
//Task 05: Divide a even number into two prime number.

int main() {
    printf("Input an odd number, larger than 2: ");
    long even_num = 0;
    while (scanf("%ld", &even_num) != 1 || even_num <= 2 || even_num % 2 != 0){
        printf("Invalid number. Try again: ");
    }
    int prime_list_len = 1;
    long *prime_list = malloc(prime_list_len * sizeof(long));
    prime_list[0] = 0;
    int is_prime = 1;
    // Get all the prime number between 2 and even_num, create a dynamic array and store them.
    for (int i = 2; i < even_num; ++i) {
        for (int j = 2; j < i; ++j) {
            if (i != j && i % j == 0) {
                is_prime = 0;
            }
        }
        if (is_prime) {
            if (prime_list_len == 1 && prime_list[0] == 0) {
                prime_list[0] = i;
            } else {
                prime_list_len ++;
                prime_list = realloc(prime_list, prime_list_len * sizeof(long));
                prime_list[prime_list_len - 1] = i;
            }
        }
        is_prime = 1;
    }
    //Now try to divide the even numver
    for (int i = 0; i < prime_list_len; ++i) {
        for (int j = i; j < prime_list_len; ++j) {
            if (prime_list[i] + prime_list[j] == even_num) {
                printf("%d = %d + %d\n", even_num, prime_list[i], prime_list[j]);
            }
        }
    }
    return 0;
}
