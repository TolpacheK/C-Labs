#include <iostream>

int main() {
    long long product = 1; 

    std::cout << "Добуток чисел, кратних 3 і не більших за 100." << std::endl;
    std::cout << "Числа для множення: ";
    
    for (int i = 3; i <= 100; i += 3) {
        product *= i; 
        
        std::cout << i << (i < 99 ? " * " : "");
    }
    
    std::cout << "\n\nРезультат: " << product << std::endl;

    return 0;
}
