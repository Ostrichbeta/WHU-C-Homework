#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Task 02: Split the string from the middle of it, and put the former part behind the later part.
char* split_and_move(char *original) {
    char *result = malloc(sizeof(char) * strlen(original) + 1);
    for (int i = 0, j = strlen(original) / 2 + i; j < strlen(original); ++i, ++j) {
        result[i] = original[j];
    }
    for (int j = 0; j < strlen(original) / 2; ++j) {
        result[(strlen(original) % 2 == 0 ? strlen(original) / 2: strlen(original) / 2 + 1) + j] = original[j];
    }

    return result;
}

int main() {
    printf("Input a string that less than 1024 characters: ");
    char str[1025];
    scanf("%[^\n]s", str);
    printf("Your input: %s\n", str);
    char *result = split_and_move(str);
    printf("What you will get: %s\n", result);
    free(result);
    return 0;
}
