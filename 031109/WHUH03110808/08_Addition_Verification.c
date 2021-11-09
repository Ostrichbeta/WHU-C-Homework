#include <stdio.h>
#include <stdlib.h>
//Task 08: Verify if a number can be divided into the addition of two prime numbers.
int verify(long num) {
    int prime_list_len = 1;
    long *prime_list = malloc(prime_list_len * sizeof(long));
    prime_list[0] = 0;
    int is_prime = 1;
    // Get all the prime number between 2 and even_num, create a dynamic array and store them.
    for (int i = 2; i < num; ++i) {
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
    //Now try to divide the even number
    int can_be_divided = 0;
    for (int i = 0; i < prime_list_len; ++i) {
        for (int j = i; j < prime_list_len; ++j) {
            if (prime_list[i] + prime_list[j] == num) {
                can_be_divided = 1;
                printf("%ld = %ld + %ld\n", num, prime_list[i], prime_list[j]);
            }
        }
    }
    if (can_be_divided) return 1; else return 0;
    free(prime_list);
}

int main() {
    printf("Input a number that larger than 2: ");
    long num = 0;
    while (!(scanf("%ld", &num) == 1 && num >= 2)) {
        printf("Invalid input, please try again: ");
    }
    if (verify(num)){
        printf("This number can be divided into the addition of two prime numbers.");
    } else {
        printf("This number cannot be divided into the addition of two prime numbers.");
    }
    return 0;

}
