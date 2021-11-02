#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Task 08: Interrupt by non-alphabetical chars
int gets_s (char *str, length) {
    fgets(str, length, stdin);
    str[(int) strlen(str) - 1] = 0;
    return strlen(str);
}

int main() {
    char str[1024];
    printf("Input a string who only consists of alphabetical characters.\nEven space is not allowed: ");
    gets_s(str, 1024);
    int str_len = strlen(str);
    for (int i = 0; i < str_len; ++i) {
        if (str[i] >= 97 && str[i] <= 122) {
            printf("%c", (char) str[i] - 32);
        } else if (str[i] >= 65 && str[i] <= 90) {
            printf("%c", str[i]);
        } else {
            printf("<-\nNon-alphabetical elements detected, exit now.\n");
            exit(0);
        }
    }
    return 0;
}
