#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::cout << "Обчислення y = sin^5(x) + |5x - 1.5| для 5 значень x." << std::endl;

    for (int i = 1; i <= 5; ++i) {
        double x, y;
        std::cout << "x №" << i << "= ";
        if (!(std::cin >> x)) {
            std::cerr << "Помилка введення." << std::endl;
            return 1;
        }

        y = std::pow(std::sin(x), 5.0) + std::fabs(5.0 * x - 1.5);

        std::cout << "y(" << x << ") = " << y << std::endl;
    }

    return 0;
}
