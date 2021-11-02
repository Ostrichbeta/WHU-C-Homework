#include <stdio.h>
#include <string.h>
//Task 06: '\0' String

int main() {
    char a[] = "abcd\0efgh";
    printf("strlen() result: %lu\n", strlen(a));
    printf("Size of a: %lu\n", sizeof(a));
    printf("a: %s\n", a);
    puts(a);

    return 0;
}
