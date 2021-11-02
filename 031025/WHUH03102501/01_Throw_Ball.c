#include <stdio.h>
#include <math.h>
#define PI acos(-1)
#define G 9.80665
//Task 01: Throw a ball

int main() {
    double body_height, initial_speed, initial_angle, high_time,
    down_time, total_distance, v_speed, h_speed, total_height, up_height;
    printf("Import the body_height of the person, in meters: ");
    while (scanf("%lf", &body_height) != 1 || body_height <= 0){
        printf("Invalid input. Try again.");
    }
    printf("Input the speed of the ball: ");
    while (scanf("%lf", &initial_speed) != 1 || initial_speed <= 0){
        printf("Invalid input. Try again.");
    }
    printf("Input the initial angle, in radian, from 0 to π/2: ");
    while (scanf("%lf", &initial_angle) != 1 || initial_angle < 0 || initial_angle > PI / 2){
        printf("Invalid input. Try again.");
    }
    printf("Input complete. Start calculating...");
    v_speed = initial_speed * sin(initial_angle);
    high_time = v_speed / G;
    up_height = pow(v_speed, 2) / 2 / G;
    total_height = up_height + body_height;
    down_time = sqrt(2 * total_height / G);
    h_speed = initial_speed * cos(initial_angle);
    total_distance = h_speed * (high_time + down_time);
    printf("Maximum height is %.2lf m\nTotal horizontal distance is %.2lf m\n"
           "(All the results are rounded to two digits.)", total_height, total_distance);
    return 0;
}
