#include <iostream>
#include <cmath>

bool is_point_in_area(double x, double y) {
    
    bool is_in_triangle = (x <= 0 && y >= 0 && y <= x + 1);
    
    bool is_in_quarter_circle = (x <= 0 && y <= 0 && pow(x, 2) + pow(y, 2) <= 1.0);
    
    return is_in_triangle || is_in_quarter_circle;
}

int main() {

    const double X = -0.5;
    const double Y_COORD = -0.5;

    std::cout << is_point_in_area(X, Y_COORD) << std::endl;

    return 0;
}
