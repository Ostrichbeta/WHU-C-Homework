#include <stdio.h>
#include <string.h>
//(Optional) Task 14: Convert all the Upper-case letter to Lower-case letter.
//P.s.: Uppercase letters are located at 65 to 90 in ASCII chart.

void upper_to_lower(char *str){
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
}

int main() {
    printf("Input a string which less than 2048 characters: ");
    char str[2048];
    scanf("%[^\n]s", str);
    upper_to_lower(str);
    printf("Converted string: %s.\n", str);
    return 0;
}
