#include <stdio.h>
#include <math.h>
//Task 03: Define two dots, calculate the distance, and get the radius of sphere which is decided by the two dots.

struct threeDDot {
    long double x;
    long double y;
    long double z;
};

typedef struct threeDDot threeDDot;

long double getDistance(threeDDot a, threeDDot b){
    return sqrtl(powl(a.x - b.x, 2) + powl(a.y - b.y, 2) + powl(a.z - b.z, 2));
}

threeDDot getMidPoint(threeDDot a, threeDDot b){
    threeDDot result;
    result.x = (a.x + b.x) / 2;
    result.y = (a.y + b.y) / 2;
    result.z = (a.z + b.z) / 2;
    return result;
}

int main() {
    threeDDot dotList[2];
    for (int i = 0; i < 2; ++i) {
        printf("Input the location of point No. %d:", i + 1);
        while (scanf("%Lf, %Lf, %Lf", &dotList[i].x, &dotList[i].y, &dotList[i].z) != 3) {
            printf("Invalid input, please try again: ");
        }
    }
    threeDDot midPoint = getMidPoint(dotList[0], dotList[1]);
    long double distance = getDistance(dotList[0], dotList[1]);
    printf("The distance between two dots is %.2Lf (rounded to two digits).\n", distance);
    if (distance > 0) {
        printf("The center of sphere is (%.2Lf,%.2Lf,%.2Lf).\n", midPoint.x, midPoint.y, midPoint.z);
        printf("The radius of sphere is %.2Lf (rounded to two digits).\n", distance / 2);
    }
    return 0;
}
