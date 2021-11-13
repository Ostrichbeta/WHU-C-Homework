#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
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

//Calculate the patterns after the digit mark
long* after_digit(double num){
    long *after_digit_part = malloc(7 * sizeof(long));
    for (int i = 0; i < 7; ++i) {
        after_digit_part[i] = floor(num * 16);
        num = (num * 16) - floor(num * 16);
    }
    return after_digit_part;
}

int main() {
    char hex_char[] = "0123456789ABCDEF";
    printf("Input a decimal number to convert, it must be greater than or equal to zero: ");
    double decf;
    long dec = 0;
    while (!(scanf("%lf", &decf) == 1 && decf >= 0)){
        printf("Invalid input, try again: ");
    }
    dec = (long)floor(decf);
    double after_digit_num = decf - (double) dec;
    long digit = dec == 0 ? 1 : (long)(log(dec) / log(16) + 1);
    long *dec_array = dec_to_hex(dec);
    long *after_digit_array = malloc(7 * sizeof(long));
    after_digit_array = after_digit(after_digit_num);
    char *dec_string = malloc(sizeof(char) * (digit + 9));
    for (int i = 0; i < digit; ++i) {
        dec_string[i] = hex_char[dec_array[i]];
    }
    dec_string[digit] = '.';
    //for (int i = 0; i < 7; ++i) {
    //    long k = after_digit_array[i];
    //    printf("%ld, ", after_digit_array[i]);
    //}
    for (int i = 0; i < 7; ++i) {
        char k = hex_char[after_digit_array[i]];
        dec_string[digit + 1 + i] = hex_char[after_digit_array[i]];
    }
    printf("Decimal number %ld can be converted to hexdecimal number %s.", dec, dec_string);
    free(dec_string);
    free(after_digit_array);
    return 0;
}
