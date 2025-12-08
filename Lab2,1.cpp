#include <iostream>
#include <cmath>
#include <iomanip>

double Y(double x) {
    if (x < 0) {
        return 0.25 * pow(x, 4) + 2 * pow(x, 2);
    } 
    else if (x <= 1) { 
        return 0.5 * cos(x) + 4 * x;
    } 
    else {
        return 0.9 * sqrt(x) - 0.8 * x;
    }
}

int main() {
    const double X = 0.5;
  
    std::cout << std::fixed << std::setprecision(6) << Y(X) << std::endl;

    return 0;
}
