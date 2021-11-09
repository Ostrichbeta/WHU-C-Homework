#include <stdio.h>
#include <string.h>
//(Optional) Task 15: Find substring in a string
//Uppercase letters located at 65-90 in ASCII chart, while the lowercase located at 97-122

int char_equ_not_sensitive(char a, char b){
    return (a == b || (a >= 65 && a <= 90 && a == b - 32) || (a >= 97 && a <= 122 && a == b + 32));
}

int str_find(char *mainstr, char *substr){
    int isMatch = 0;
    for (int i = 0; i < strlen(mainstr); ++i) {
        if (char_equ_not_sensitive(mainstr[i], substr[0])){
            //When the (i+1)th character matchs the first character of the substring, start the verification process.
            for (int j = 0; j < strlen(substr); ++j) {
                if (!char_equ_not_sensitive(mainstr[i + j], substr[j])) break;
                if (j == strlen(substr - 1)) {isMatch == 1;return 1;}
            }
        }
    }
    return 0;
}

int main() {
    char str[2048];
    printf("Input a string whose length is less than 2048: ");
    scanf("%[^\n]s", str);
    fflush(stdin);
    char sub_str[2048];
    printf("Input a substring whose length is less than 2048: ");
    scanf("%[^\n]s", sub_str);
    if(str_find(str, sub_str)){
        printf("%s is included in %s.\n", sub_str, str);
    }
    return 0;
}
