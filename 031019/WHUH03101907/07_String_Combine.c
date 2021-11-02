#include <stdio.h>
//Task 07: String Combine

int main() {
    char a[4096];
    char b[4096];
    char combine[8192];
    printf("Input the first string: ");
    scanf("%[^\n]s", a);
    fflush(stdin);
    printf("Input the second string: ");
    scanf("%[^\n]s", b);
    int pos = 0;
    for (int i = 0; i < 4096; ++i) {
        if (a[i] == 0) break; else {
            combine[pos] = a[i];
            pos += 1;
        }
    }
    for (int i = 0; i < 4096; ++i) {
        if (b[i] == 0) break; else {
            combine[pos] = b[i];
            pos += 1;
        }
    }
    printf("Combined string: %s", combine);
    return 0;
}
