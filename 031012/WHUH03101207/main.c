#include <stdio.h>
#include "math.h"
//Task 07: Define a sphere, and define a dot, check if the dot in the sphere

int main() {
    double x1, y1, z1, r;
    double x2, y2, z2;
    printf("Define a sphere in this format x, y, z, r: ");
    scanf("%lf, %lf, %lf, %lf", &x1, &y1, &z1, &r);
    printf("Define a dot in this format x, y, z: ");
    scanf("%lf, %lf, %lf", &x2, &y2, &z2);
    printf("The sphere's center is located at (%.2lf,%.2lf,%.2lf) (rounded) with a radius of %.2lf (rounded).\n",
           x1, y1, z1, r);
    printf("The dot is located at (%.2lf,%.2lf,%.2lf) (rounded).\n", x2, y2, z2);
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    printf("Distance between the dot and the center is %.2lf (rounded).\n", distance);
    if (distance == r){
        printf("The dot is on the surface of the sphere.\n");
    } else if (distance >= r) {
        printf("The dot is outside the sphere.\n");
    } else {
        printf("This dot is inside the sphere.\n");
    }

    return 0;
}
