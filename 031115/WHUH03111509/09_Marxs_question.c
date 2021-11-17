#include <stdio.h>
//Task 09: Marx's question

int main() {
    printf("How many people? ");
    int people;
    while (!(scanf("%d", &people) == 1 && people > 0));
    printf("How many shillings? ");
    int shilling;
    while (!(scanf("%d", &shilling) == 1 && shilling > 0));
    // Calculate the amount of men
    int solution_count = 0;
    int max_men = shilling / 3;
    for (int i = max_men; i > 0; --i) {
        //Calculate the amount of women
        int max_women = (shilling - 3 * i) / 2;
        for (int j = max_women; j > 0; --j) {
            //Calculate the amount of children
            int max_children = shilling - 3 * i - 2 * j;
            for (int k = max_children; k > 0; --k) {
                if (k + 2 * j + 3 * i == 50 && i + j + k == 30) {
                    solution_count ++;
                    printf("Solution %d: Men: %d, Women: %d, Children: %d.\n",solution_count, i, j, k);
                }
            }
        }
    }
    return 0;
}
