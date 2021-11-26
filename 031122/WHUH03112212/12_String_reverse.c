#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Task 12: Reverse the string.

void invertChar(char* pdata);

void ogets (char *pointer, int length) {
    fgets(pointer, length, stdin);
    if (pointer[strlen(pointer) - 1] == '\n') pointer[strlen(pointer) - 1] = '\0';
}

int main() {
    printf("Input a string that less than 1024 characters: ");
    char *k = malloc(1025 * sizeof(char));
    ogets(k, 1024);
    invertChar(k);
    printf("Reversed: %s.\n", k);
    return 0;
}

void invertChar(char* pdata) {
    for (int i = 0; i < strlen(pdata) / 2; ++i) {
        char swap = pdata[i];
        pdata[i] = pdata[strlen(pdata) - i - 1];
        pdata[strlen(pdata) - i - 1] = swap;
    }
}

