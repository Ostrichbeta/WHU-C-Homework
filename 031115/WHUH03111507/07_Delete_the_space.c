#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Task 07: Delete all the spaces in the string
char* space_delete(char *str) {
    int count = 0;
    char *result = malloc(1 * sizeof(str));
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] != 32) {
            count ++;
            result = realloc(result, count * sizeof(str));
            result[count - 1] = str[i];
        }
    }
    return result;
}

int main() {
    printf("Input a string that less than 2047 characters: ");
    char str[2048];
    scanf("%[^\n]s", str);
    char *result = space_delete(str);
    printf("We got %s.\n", result);
    return 0;
}
