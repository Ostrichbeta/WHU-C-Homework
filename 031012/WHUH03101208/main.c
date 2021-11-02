#include <stdio.h>
//Task 08: Rectangle Calculation

int main() {
    double x1, y1, w1, h1;
    double x5, y5, w2, h2;
    printf("Define the first rectangle, in x, y, w, h format: ");
    scanf("%lf, %lf, %lf, %lf", &x1, &y1, &w1, &h1);
    printf("Define the second rectangle, in x, y, w, h format: ");
    scanf("%lf, %lf, %lf, %lf", &x5, &y5, &w2, &h2);
    if(w1 <= 0 || w2 <= 0 || h1 <= 0 || h2 <= 0){
        printf("Check your input carefully next time!\n");
        return 1;
    }
    double x4 = x1 + w1;
    double y4 = y1 + h1;
    double x8 = x5 + w2;
    double y8 = y5 + h2;
    double xc1 = x1 + 0.5 * w1;
    double yc1 = y1 + 0.5 * h1;
    double xc2 = x5 + 0.5 * w1;
    double yc2 = y5 + 0.5 * h1;
    // Check if one is included in another first
    if((x5 >= x1 && x8 <= x4 && y5 >= y1 && y8 <= y4) || (x1 >= x5 && x4 <= x8 && y1 >= y5 && y4 <= y8)) {
        printf("The one is included in another.\n");
    } else if ((xc1 + xc2) / 2 < (w1 + w2) / 2 && (yc1 + yc2) / 2 < (h1 + h2)) {
        printf("The two are intersecting.");
    } else {
        printf("The two are separated.");
    }
}
