#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long product = 1;
    bool found = false;

    while (n > 0) {
        int digit = n % 10;
        if (digit != 7) {
            product *= digit;
            found = true;
        }
        n /= 10;
    }

    if (!found) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << product << std::endl;
    }

    return 0;
}
