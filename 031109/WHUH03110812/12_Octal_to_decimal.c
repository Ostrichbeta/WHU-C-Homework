#include <stdio.h>
#include <string.h>
#include <math.h>
//(Optional) Task 12: Convert an octal number to decimal number.

int string_verify(char *oct_str) {
    for (int i = 0; i < strlen(oct_str); ++i) {
        if (oct_str[i] > 55 || oct_str[i] < 48){
            // The string includes characters which is not in 0 - 7
            return 0;
        }
    }
    return 1;
}

long oct_to_dec (char *oct_str) {
    unsigned long length = strlen(oct_str);
    long result = 0;
    for (int i = 0; i < length; ++i) {
        result += ((long)oct_str[i] - 48) * powl(8, length - i - 1);
    }
    return result;
}

int main() {
    char octal_str[2048];
    printf("Input an octal: ");
    while (!(scanf("%s", &octal_str) == 1 && string_verify(octal_str))){
        printf("Invalid input, try again: ");
    }
    long decimal_result = oct_to_dec(octal_str);
    printf("Octal number %s can be converted to decimal number %ld.\n", octal_str, decimal_result);
    return 0;
}
