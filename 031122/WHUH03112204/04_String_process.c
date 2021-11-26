#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Task 04: String process

//Change uppercase alphabet to lower, please check https://github.com/Ostrichbeta/WHU-C-Homework/blob/80da27316695f7639dbf7b781548493d9deca1f2/031109/WHUH03110814/14_Upper_to_lower.c

char* deleteNumberInChar (char *original) {
    char *result = malloc((strlen(original) + 1) * sizeof(char));
    for (int i = 0, j = 0; i < strlen(original); ++i, ++j) {
        if (original[i] >= 48 && original[i] <= 57) j++;
        result[i] = original[j];
    }
    return result;
}

void sortStr (char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        for (int j = i; j < strlen(str); ++j) {
            if (str[i] > str[j]) {
                char swap = str[i];
                str[i] = str[j];
                str[j] = swap;
            }
        }
    }
}

char* sortCombine (char *str1, char *str2) {
    char *result = malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
    for (int i = 0; i < strlen(str1); ++i) {
        result[i] = str1[i];
    }
    strcat(result, str2);
    sortStr(result);
    return result;
}



int main() {
    char original[1024];
    char original2[1024];
    printf("Input a string that less than 1024 characters: ");
    scanf("%[^\n]s", original);
    fflush(stdin);
    printf("Input the second string, less than 1024 characters: ");
    scanf("%[^\n]s", original2);
    char *numberDeleted = NULL;
    numberDeleted = deleteNumberInChar(original);
    printf("Original, but delete the numeric elements: %s.\n", numberDeleted);
    char *combination = NULL;
    combination = sortCombine(original, original2);
    sortStr(original);
    printf("Sorted original: %s.\n", original);
    printf("The sorted combination is %s.\n", combination);
    free(combination);
    return 0;
}
