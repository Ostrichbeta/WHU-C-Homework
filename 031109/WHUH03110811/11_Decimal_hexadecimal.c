#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Task 11: Decimal to hexadecimal

long* dec_to_hex(long dec){
    long digit = (long)(log(dec) / log(16) + 1);
    //Create a dynamic array to store hexadecimal, from the top digit to the end.
    long *hex_array = malloc(sizeof(long) * digit);
    for (long i = 1; i <= digit ; ++i) {
        long k = (long)(dec / powl(16, digit - i)) % 16;
        hex_array[i - 1] = (long)(dec / powl(16, digit - i)) % 16;
    }
    return hex_array;
}

int main() {
    char hex_char[] = "0123456789ABCDEF";
    printf("Input a decimal number to convert, it must be greater than or equal to zero: ");
    long dec = 0;
    while (!(scanf("%ld", &dec) == 1 && dec >= 0)){
        printf("Invalid input, try again: ");
    }
    long digit = dec == 0 ? 1 : (long)(log(dec) / log(16) + 1);
    long *dec_array = dec_to_hex(dec);
    char *dec_string = malloc(sizeof(char) * (digit + 1));
    for (int i = 0; i < digit; ++i) {
        dec_string[i] = hex_char[dec_array[i]];
    }
    printf("Decimal number %ld can be converted to hexdecimal number %s.", dec, dec_string);
    free(dec_string);
    return 0;
}
