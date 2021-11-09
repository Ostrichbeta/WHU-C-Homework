#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Task 10: String process
//P.S.: The ASCII position of alphabets are from 65 to 90 and from 97 to 122.
char* delete_non_alphabetical_elements(const char* str){
    unsigned long str_len = strlen(str);
    char *result = malloc(sizeof(char) * (str_len + 1));
    int pos = 0;
    for (int i = 0; i < 2048 && str[i] != 0; ++i) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)){
            result[pos] = str[i];
            pos++;
        }
    }
    return result;
}

char* reverse_string(const char* str1){
    unsigned long str_len = strlen(str1);
    char *result = malloc(sizeof(char) * (str_len + 1));
    for (int i = 0; i < str_len; ++i) {
        result[str_len - i - 1] = str1[i];
    }
    return result;
}

char* remain_even_element(const char* str){
    long result_len = 1;
    char *result = malloc(sizeof(char) * result_len);
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] % 2 == 0) {
            result_len ++;
            result = realloc(result, sizeof(char) * result_len);
            result[result_len - 2] = str[i];
        }
    }
    return result;
}

int main() {
    printf("WARNING: THIS PROGRAM IS LACK OF INPUT CHECK, "
           "IF YOU INPUT SOMETHING THAT CAN MAKE IT BREAK DOWN, YOU ARE ON YOUR OWN!\n\n");
    printf("Input a string below: ");
    char str1[2048];
    fgets(str1, 2048, stdin);
    char *str2 = NULL;
    str2 = delete_non_alphabetical_elements(str1);
    printf("Deleted string: %s\n", str2);
    str2 = reverse_string(str2);
    printf("Reversed string: %s\n", str2);
    str2 = remain_even_element(str2);
    printf("Remaining: %s\n", str2);
    printf("The length of a is %lu.\n", strlen(str2));
    return 0;
}
