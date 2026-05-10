#include <iostream>

using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int monthLengthSwitch(int year, int month) {
    switch (month) {
        case 1: return 31;
        case 2:
            if (isLeap(year)) return 29;
            else return 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

int monthLengthArray(int year, int month) {
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeap(year)) {
        return 29;
    }

    return months[month - 1];
}

int main() {
    int year, month;

    cout << "Vvedit rik: ";
    cin >> year;

    cout << "Vvedit nomer misyatsya: ";
    cin >> month;

    cout << "Switch: " << monthLengthSwitch(year, month) << endl;
    cout << "Masiv: " << monthLengthArray(year, month) << endl;

    return 0;
}
