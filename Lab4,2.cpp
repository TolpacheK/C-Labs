#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {

    double v1, v2, v3, v4, v5; 

    v1 = 2.3;
    v2 = 2.3;
    v3 = 2.123456;
    v4 = 2.123456;
    v5 = 2.123456;

    cout << v1 << endl;

    cout << fixed << setprecision(2) << v2 << endl; 

    cout << fixed << setprecision(6) << v3 << endl;

    cout << fixed << setprecision(2) << v4 << endl;

    cout << fixed << setprecision(0) << v5 << endl;

    return 0;
}
