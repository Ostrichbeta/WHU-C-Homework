#include <stdio.h>
//Task 09: Count the total words.
//Space ASCII code: 32

int main() {
    char a[4096];
    printf("Input a string: ");
    scanf("%[^\n]", a);
    int word_count = 0;
    int is_first_spaces = 1;
    for (int i = 0; i < 4096; ++i) {
        if (a[i] == 0) {
            if (((!is_first_spaces && word_count == 0)||a[i-1] != 32) && i != 0){
                word_count += 1;
            }
            break;
        }
        if (i >= 0){
            if (a[i] == 32){
                if(!is_first_spaces){
                    word_count++;
                }
            } else {
                is_first_spaces = 0;
            }
        }
    }
    printf("There is/are %d word(s) in your string.", word_count);
    return 0;
}
