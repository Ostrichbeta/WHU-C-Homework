#include <stdio.h>
//Task 03: Draw a rectangle with certain length

int draw(int a){
    if (a > 6 || a < 3) {
        printf("Invalid length.\n");
        return 1;
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if ((i == 0 || i == a - 1) || (j == 0 || j == a - 1)) printf("* "); else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}

int main() {
    int a;
    printf("Input the length of the rectangle, between 3 and 6: ");
    while (scanf("%d", &a) != 1 || a > 6 || a < 3) {
        printf("Invalid input, try again: ");
    }
    if (draw(a) == 0){
        printf("Print succeed.\n");
    } else {
        printf("Print failed.\n");
    }
}
