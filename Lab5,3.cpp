#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b, h;

    cout << "Введіть початкове значення a: ";
    if (!(cin >> a)) return 1;

    cout << "Введіть кінцеве значення b: ";
    if (!(cin >> b)) return 1;

    cout << "Введіть крок h: ";
    if (!(cin >> h) || h <= 0) {
        cerr << "Помилка введення h. Крок повинен бути додатнім." << endl;
        return 1;
    }

    if (a > b) {
        cout << "Помилка: 'a' має бути меншим або рівним 'b'." << endl;
        return 1;
    }

    cout << "\n-----------------------\n";
    cout << "|   X   |      Y      |\n";
    cout << "-----------------------\n";

    bool dz_violation = false;

    for (double x = a; x <= b; x += h) {
        if (x > 0) {
            dz_violation = true;
            break;
        }

        double y = sin(x) + sqrt(-x); 

        cout << "| " << fixed << setprecision(3) << setw(5) << x 
             << " | " << fixed << setprecision(5) << setw(10) << y << " |\n";
    }

    cout << "-----------------------\n";

    if (dz_violation) {
        cout << "\nОбчислення припинено, оскільки x вийшло за межі ОДЗ (x > 0)." << endl;
    } else if (a <= b && a > 0 && h > 0) {
         cout << "\nУвесь заданий інтервал [" << a << ", " << b << "] знаходиться поза ОДЗ (x > 0). Таблиця порожня." << endl;
    }

    return 0;
}
