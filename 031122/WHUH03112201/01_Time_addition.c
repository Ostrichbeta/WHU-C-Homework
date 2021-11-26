#include <stdio.h>
//Task 01: Add up two times using structures.
struct time_str {
    long hours;
    int minutes;
    double seconds;
};

typedef struct time_str time_str;

time_str add (time_str a, time_str b) {
    time_str result;
    result.hours = a.hours + b.hours;
    result.minutes = a.minutes + b.minutes;
    result.seconds = a.seconds + b.seconds;
    while (result.seconds >= 60) {
        result.minutes ++;
        result.seconds -= 60;
    }
    while (result.minutes >= 60) {
        result.hours ++;
        result.minutes -= 60;
    }
    return result;
}

time_str timeTidy (time_str input) {
    time_str result = input;
    while (result.seconds >= 60) {
        result.minutes ++;
        result.seconds -= 60;
    }
    while (result.minutes >= 60) {
        result.hours ++;
        result.minutes -= 60;
    }
    return result;
}

int main() {
    printf("Input the first time, in h:mm:ss.ss format: ");
    time_str timeA;
    while (!(scanf("%ld:%d:%lf", &timeA.hours, &timeA.minutes, &timeA.seconds) == 3
    && timeA.hours >= 0 && timeA.minutes >= 0 && timeA.seconds >= 0)) {
        printf("Invalid input, please try again: ");
    }
    timeA = timeTidy(timeA);
    printf("The first time is %ld:%d:%lf (rounded).\n", timeA.hours, timeA.minutes, timeA.seconds);

    printf("Input the second time, in h:mm:ss.ss format: ");
    time_str timeB;
    while (!(scanf("%ld:%d:%lf", &timeB.hours, &timeB.minutes, &timeB.seconds) == 3
             && timeB.hours >= 0 && timeB.minutes >= 0 && timeB.seconds >= 0)) {
        printf("Invalid input, please try again: ");
    }
    timeB = timeTidy(timeB);
    printf("The second time is %ld:%d:%lf (rounded).\n", timeB.hours, timeB.minutes, timeB.seconds);

    time_str result;
    result = add(timeA, timeB);
    printf("The result time is %ld:%d:%lf (rounded).\n", result.hours, result.minutes, result.seconds);
    return 0;
}
