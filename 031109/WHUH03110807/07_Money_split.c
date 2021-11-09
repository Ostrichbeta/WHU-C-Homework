#include <stdio.h>
#include <stdlib.h>
//Task 07: Money split

int* exchange(int money, int* wallet){
    //Return a 6-space array, which means [$100 note, $50 note, $10 note, $5 note, $2 note, $1 note]

    wallet[0] = money / 100;
    int cash_type[] = {100, 50, 10, 5, 2, 1};
    for (int i = 1; i < 6; ++i) {
        int k = wallet[i - 1] * cash_type[i - 1];
        money -= wallet[i - 1] * cash_type[i - 1];
        wallet[i] = money / cash_type[i];
    }
    return wallet;
}

int main(){
    printf("Input your total cash: ");
    int cash;
    int cash_type[] = {100, 50, 10, 5, 2, 1};
    while (!(scanf("%d", &cash) == 1 && cash >= 0)){
        printf("Invalid input, please try again: ");
    }
    int *wallet = malloc(6 * sizeof(int));
    wallet = exchange(cash, wallet);
    printf("$%d can be exchanged into", cash);
    if (cash == 0){
        printf(" nothing!\n");
    } else {
        for (int i = 0; i < 6; ++i) {
            if (wallet[i] != 0) {
                printf(" %d $%d note", wallet[i], cash_type[i]);
                if (wallet[i] > 1) {
                    printf("s");
                }
                printf(",");
            }
        }
        printf("\n");
    }
    free(wallet);
}