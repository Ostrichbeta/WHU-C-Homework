#include <stdio.h>
//Task 08: Delete all the non-alphabet and non-numeric elements
//Number's and alphabet's ASCII range are 48-57, 65-90 and 97-122

int main() {
    char a[4096];
    printf("Input a string: ");
    scanf("%[^\n]", a);
    for (int i = 0; i < 4096; ++i) {
        if(a[i] == 0) break;
        if((a[i] >= 48 && a[i] <= 57)||(a[i] >= 65 && a[i] <= 90)||(a[i] >= 97 && a[i] <= 122)){
            printf("%c", a[i]);
        }
    }
    return 0;
}
