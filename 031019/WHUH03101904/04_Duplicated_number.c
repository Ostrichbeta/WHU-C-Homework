#include <stdio.h>
//Task 04: Duplicated number search

int main() {
    printf("Hello, World!\n");
    int list[8];
    printf("Input 8 numbers, divided by period sign: ");
    scanf("%d, %d, %d, %d, %d, %d, %d, %d", &list[0], &1[list], &list[2], &3[list],
          &list[4], &5[list], &list[6], &7[list]);
    int duplist[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int isdup[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int dupcount = 0;
    int isHas = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i != j && list[i] == list[j]) {
                if(dupcount != 0){
                    for (int k = 0; k < dupcount; ++k) {
                        if (duplist[k] == list[i]){
                            isHas = 1;
                            break;
                        }
                    }
                    if (!isHas) {
                        duplist[dupcount] = list[i];
                        isdup[dupcount] = 1;
                        dupcount++;
                    } else {
                        isHas = 0;
                    }
                } else {
                    duplist[dupcount] = list[i];
                    isdup[dupcount] = 1;
                    dupcount++;
                }
            }
        }
    }
    if (dupcount) {
        printf("Duplicated numbers: ");
        for (int i = 0; i < dupcount; ++i) {
            if (isdup[i]) printf("%d ", duplist[i]);
        }
    }
    return 0;
}
