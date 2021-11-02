#include <stdio.h>
//Task 03: Reverse the number, and export as characters.

int main(){
    int originalNum = 0;
    printf("Input a 3-digit number: ");
    scanf("%d", &originalNum);
    if(originalNum < 100 || originalNum > 999){
        printf("The number you inputed is out of our range.\n");
        return 1;
    }
    int hundred = originalNum / 100;
    int tenth = (originalNum / 10) % 10;
    int decimal = originalNum % 10;
    printf("%d%d%d\n", decimal, tenth, hundred);
    printf("Reversed: %c%c%c\n", (char) decimal + 48, (char) tenth + 48, (char) hundred + 48);
    return 0;
}
