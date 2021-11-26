#include <stdio.h>
#include <stdbool.h>
//Task 13: Check if a year is leap year, and check how many days in ths month.

struct CTimeData {
    unsigned long year;
    unsigned int month;
    unsigned int day;
};

unsigned int large_month[] = {1, 3, 5, 7, 8, 10, 12};

_Bool isIn (const unsigned int array[], unsigned int num, size_t n) {
    for (int i = 0; i < n; ++i) {
        if (array[i] == num) return true;
    }
    return false;
}

_Bool isLeapYear (struct CTimeData time) {
    return (time.year % 400 == 0 || (time.year % 4 == 0 && time.year % 400 != 0 && time.year % 100 != 0)) ? true : false;
}

unsigned int getDayCount (struct CTimeData time) {
    return time.month == 2 ? (isLeapYear(time) ? 29 : 28) : (isIn(large_month, time.month, 7) ? 31 : 30);
}

int main() {
    struct CTimeData date;
    do {
        printf("Input a date, in YYYY-MM-DD format: ");
    } while (scanf("%ld-%u-%u", &date.year, &date.month, &date.day) != 3);
    printf("%ld", date.year);
    printf(isLeapYear(date) ? " is ": " is not ");
    printf("a leap year.\n");
    printf("%ld-%u has %u days.\n", date.year, date.month, getDayCount(date));
    return 0;
}

