#include <stdio.h>
#include <math.h>
#define PI acos(-1)
//Task 04: Triangle Calculator

double cosToRad(double cosine){
    if (cosine < -1 || cosine > 1){
        printf("Out of cosine Range.");
    }
    return acos(cosine);
}

double cosToDeg(double cosine){
    if (cosine < -1 || cosine > 1){
        printf("Out of cosine Range.");
    }
    return acos(cosine) / PI * 180;
}

int main(){
    double a[3];
    printf("Input the length of the three sides, format: a, b, c : ");
    scanf("%lf, %lf, %lf", &a[0], &a[1], &a[2]);
    //Sort the number
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a[i] <= a[j]) {
                double swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
        }
    }
    printf("The lengths of the triangle are %.2lf, %.2lf and %.2lf.\n", a[0], a[1], a[2]);
    if(a[0] + a[1] <= a[2] || a[2] - a[1] >= a[0]){
        printf("If you can draw that rectangle, I can get it for you.\n");
        return 1;
    }
    double cosine0 = (pow(a[1], 2) + pow(a[2], 2) - pow(a[0], 2))/(2 * a[1] * a[2]);
    double cosine1 = (pow(a[0], 2) + pow(a[2], 2) - pow(a[1], 2))/(2 * a[0] * a[2]);
    double cosine2 = (pow(a[1], 2) + pow(a[0], 2) - pow(a[2], 2))/(2 * a[1] * a[0]);
    double triangleSquare = 0.5 * a[1] * a[2] * sqrt(1 - pow(cosine0, 2));
    printf("==== Triangle Information ====\n");
    printf("Side length: %.2lf, %.2lf and %.2lf\n", a[0], a[1], a[2]);
    printf("Three angles:\n");
    printf("\tIn degree: %.2lf, %.2lf and %.2lf\n", cosToDeg(cosine0), cosToDeg(cosine1), cosToDeg(cosine2));
    printf("\tIn radian: %.2lf, %.2lf and %.2lf\n", cosToRad(cosine0), cosToRad(cosine1), cosToRad(cosine2));
    printf("Square: %.2lf\n", triangleSquare);
    printf("All numbers are rounded to two decimal places.\n");
    return 0;
}
