#include <stdio.h>

struct date {
    int year;
    int month;
    int day;
};

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date);

int main(void) {
    struct date today, tomorrow;
    readDate(&today);
    printDate(today);
    tomorrow = advanceDay(today);
    printDate(tomorrow);
    return 0;
}

/* add your function definitions here */
void readDate(struct date *today) {
    scanf("%d %d %d", &today->year, &today->month, &today->day);
}

void printDate(struct date date) {
    printf("%02d/%02d/%04d\n", date.month, date.day, date.year);
}

struct date advanceDay(struct date tomorrow) {
    if (tomorrow.day % 2 != 0 && tomorrow.month == 12) {
        tomorrow.day = 01;
        tomorrow.month = 01;
        tomorrow.year += 1;
    }
    else if (tomorrow.day % 2 == 0 && tomorrow.month != 12) {
        tomorrow.day = 01;
        tomorrow.month += 1;
    }
    else { tomorrow.day += 1; }
    return tomorrow;
}
