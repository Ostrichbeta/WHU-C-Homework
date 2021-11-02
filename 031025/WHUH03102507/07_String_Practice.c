#include <stdio.h>
#include <string.h>
//Task 07: String function practice.
int gets_s (char *str, length) {
    fgets(str, length, stdin);
    str[(int) strlen(str) - 1] = 0;
    return strlen(str);
}

int main() {
    char name[1024];
    printf("Input your name, less than 20 characters (spaces included): ");
    //cmake don't have gets_s function, use fgets instead.
    while (gets_s(&name, 1024) > 20);
    printf("Length of string name: %lu\n", strlen(name));
    char namecopy[1024];
    strcpy(namecopy, name);
    strcpy(name, "Ostrichbeta Yick-Ming Chan");
    printf("Namecopy: %s, Name: %s.\n", namecopy, name);
    int compare_result = strcmp(name, namecopy);
    if (!compare_result) {
        printf("The two strings are not equal!\n");
    } else {
        printf("The two strings are equal.\n");
    }
    char occupation[1024];
    printf("Enter the occupation of %s: ", name);
    gets_s(occupation, 1024);
    strcat(name, " is a(n) ");
    strcat(name, occupation);
    printf("%s.\n", name);
    printf("Enter something to find: ");
    char find[5];
    gets_s(find, 5);
    char first_index[30];
    strcpy(first_index, strstr(name, find));
    return 0;
}
