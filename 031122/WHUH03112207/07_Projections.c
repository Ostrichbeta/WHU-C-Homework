#include <stdio.h>
#include <stdlib.h>
//Task 07: Make vertical projection and horizontal projection

struct subArray {
    double *list;
    size_t count;
};

struct fatherArray {
    struct subArray *subArray;
    size_t count;
};

int main() {
    printf("Hou many sub-arrays? ");
    int sub;
    while (!(scanf("%d", &sub) == 1 && sub > 0)) {
        printf("Invalid input, please try again: ");
    }
    printf("How many elements in a sub-array? ");
    int element;
    while (!(scanf("%d", &element) == 1 && element > 0)){
        printf("Invalid input, please try again: ");
    }
    struct fatherArray father;
    father.count = sub;
    father.subArray = malloc((father.count + 1) * sizeof(struct subArray));
    for (int i = 0; i < father.count + 1; ++i) {
        father.subArray[i].count = element;
        father.subArray[i].list = malloc((father.subArray[i].count + 1) * sizeof(double));
    }
    // The last element is used for storing the projection result;
    printf("Now input the number.\n");
    for (int i = 0; i < father.count; ++i) {
        for (int j = 0; j < father.subArray[i].count; ++j) {
            printf("Father No. %d, Child No. %d: ", i + 1, j + 1);
            while (scanf("%lf", &father.subArray[i].list[j]) != 1);
            fflush(stdin);
        }
    }
    printf("Input complete.\n");
    for (int i = 0; i < father.count + 1; ++i) {
        if (i < father.count) {
            double horizontalProjection = 0;
            for (int j = 0; j < father.subArray[i].count; ++j) {
                horizontalProjection += father.subArray[i].list[j];
            }
            father.subArray[i].list[father.subArray[i].count] = horizontalProjection;
        } else {
            for (int j = 0; j < father.subArray[i].count; ++j) {
                double verticalProjection = 0;
                for (int k = 0; k < father.count; ++k) {
                    verticalProjection += father.subArray[k].list[j];
                }
                father.subArray[i].list[j] = verticalProjection;
            }
        }
    }
    for (int i = 0; i < father.count + 1; ++i) {
        for (int j = 0; j < father.subArray[i].count + 1; ++j) {
            if (!(i == father.count && j == father.subArray[i].count)) {
                printf("%5.2lf|", father.subArray[i].list[j]);
                fflush(stdout);
            }
        }
        printf("\n");
    }
    return 0;
}
