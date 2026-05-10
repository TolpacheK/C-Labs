#include <iostream>

using namespace std;

bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int year;

    cout << "Vvedit rik: ";
    cin >> year;

    cout << year << " -> " << isLeap(year) << endl;

    return 0;
}
