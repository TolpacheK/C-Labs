#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, y;
    // варіант 9
    cout<<"Варіант 9\n";
    a = 3;
    b = 0.521;

    y = std::cbrt(std::pow((0.127 * std::exp(b / a)) / (1.0 - std::cbrt(std::cos((b / a) * M_PI))), 2.0));

    cout << "a=" << a << " b=" << b <<"\n";
    cout << "y=" << y <<"\n";

    // варіант 14
    cout<<"Варіант 14\n";
    a = 2;
    b = 19.03;
    
    y = (4.3 * std::sin((a / b + 1.0) * M_PI)) / ((b / a) * (1.0 - std::cos((a / b - 1.0) * M_PI)) + std::log(b));
    cout << "a=" << a << " b=" << b <<"\n";
    cout << "y=" << y;

}
