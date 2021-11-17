#include <stdio.h>
//Task 13: Do something hard to explain

void get_hist(int psrc[], int nlen, int phist[]);
void negative(int psrc[], int pdst[], int nlen);

int main() {
    int num_statitstics[8];
    int dat[15] = {0, 3, 6, 3, 5, 6, 7, 5, 4, 3, 5, 6, 7, 6, 4};
    for (int i = 0; i < 8; ++i) {
        num_statitstics[i] = 0;
    }
    get_hist(dat, 15, num_statitstics);
    int reversed[15];
    negative(dat, reversed, 15);
    printf("Numbers: ");
    for (int i = 0; i < 8; ++i) {
        printf("%2d ", i);
    }
    printf("\n");
    printf("Times:   ");
    for (int i = 0; i < 8; ++i) {
        printf("%2d ", num_statitstics[i]);
    }
    printf("\n");
    printf("Reversed: ");
    for (int i = 0; i < 15; ++i) {
        printf("%d ", reversed[i]);
    }
    printf("\n");
    return 0;
}

void get_hist(int psrc[], int nlen, int phist[]){
    for (int i = 0; i < nlen; ++i) {
        phist[psrc[i]] ++;
    }
}

void negative(int psrc[], int pdst[], int nlen){
    for (int i = 0; i < nlen; ++i) {
        pdst[i] = 7 - psrc[i];
    }
}
