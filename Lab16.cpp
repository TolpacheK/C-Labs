#include <iostream>
#include <ctime>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int monthLength(int year, int month) {
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeap(year)) {
        return 29;
    }

    return months[month - 1];
}

Date today(void) {
    time_t t = time(NULL);
    tm tl = *localtime(&t);

    Date currentDate;
    currentDate.year = tl.tm_year + 1900;
    currentDate.month = tl.tm_mon + 1;
    currentDate.day = tl.tm_mday;

    return currentDate;
}

int daysFromStart(Date date) {
    int days = 0;

    for (int y = 1; y < date.year; y++) {
        if (isLeap(y)) {
            days += 366;
        } else {
            days += 365;
        }
    }

    for (int m = 1; m < date.month; m++) {
        days += monthLength(date.year, m);
    }

    days += date.day;

    return days;
}

int main() {
    Date birthDate;

    cout << "Vvedit rik narodzhennia: ";
    cin >> birthDate.year;

    cout << "Vvedit misyats narodzhennia: ";
    cin >> birthDate.month;

    cout << "Vvedit den narodzhennia: ";
    cin >> birthDate.day;

    Date currentDate = today();

    int result = daysFromStart(currentDate) - daysFromStart(birthDate);

    cout << "Potochna data: " << currentDate.year << "-" << currentDate.month << "-" << currentDate.day << endl;
    cout << "Kilkist dniv: " << result << endl;

    return 0;
}
