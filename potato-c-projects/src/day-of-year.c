#include <stdio.h>
#include <stdbool.h>

const unsigned int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(unsigned short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned int dayOfYear(unsigned short day, unsigned short month, unsigned short year) {
    int days = day;
    for (unsigned short i = 0; i < month - 1; i += 1) {
        days += months[i];
    }

    if (month > 2) {
        return isLeap(year) + days;
    }
    return days;
}

int main() {
    printf("%u", dayOfYear(28, 11, 2019));

    return 0;
}