// A really advanced script to print the days of a month in a calendar like format

#include <stdio.h>
#define MIN_YEAR 1700
#define MAX_YEAR 2099

int months[12] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getCenturyShift(int century) { // technically it's not called a century, but I don't know what to call it
    switch (century) {
        case 17:
            return 4;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 6;
    }
    return century / 40;
}

_Bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0)
        || (year % 4 == 0 && year % 400 == 0);
}

int getDayOfWeek(int day, int month, int year) {
    // reference : https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
    int century = year / 100;

    int last2digits = year % 100; // aka step1
    int step2 = last2digits / 4;
    int step3 = step2 + day;
    int step4 = step3 + months[month - 1];
    int step5 = isLeap(year) ? step4 - 1 : step4;
    int step6 = step5 + getCenturyShift(century);
    // step7 is for julian dates
    int step8 = step6 + last2digits;
    int step9 = step8 % 7;
    return step9 < 1 ? 7 - step9 : step9; 
}


int getDaysOfMonth(int month, int year) {
    if (month != 2) {
        return monthDays[month - 1];
    }
    if (isLeap(year)) {
        return 29;
    }
    return 28;
}

int main() {
    printf("Please enter your desired month (mm/yyyy) : ");
    int month, year;
    scanf("%d/%d", &month, &year);
    // validation
    if (month < 1 || month > 12) {
        printf("The month value must be between 1-12");
        return 0;
    }
    if (year < MIN_YEAR || year > MAX_YEAR) {
        printf("Only years between 1900 & 2099 are supported");
        return 0;
    }

    
    int startOfWeek = getDayOfWeek(1, month, year);
    int monthDays = getDaysOfMonth(month, year);
    printf("\033[0;33m");
    printf("Su\tMo\tTu\tWe\tTh\tFr\tSa\n");
    printf("\033[0m");
    for (int i = 0; i < startOfWeek - 1; i+= 1) {
        printf("\t");
    }
    for (int i = 1; i <= monthDays; i += 1, startOfWeek += 1) {
        printf("%d\t", i);
        if (startOfWeek % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}
