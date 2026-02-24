#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
    double pi4 = 0.;
    long n;
    cout << "Number of iterations? ";
    cin >> n;

    for (long i = 0; i < n; i++) {
        if (i % 2 == 0) {
            pi4 += 1.0 / (2 * i + 1);
        } else {
            pi4 -= 1.0 / (2 * i + 1);
        }
    }

    cout << fixed << setprecision(20);
    cout << "Pi = " << (pi4 * 4.) << endl;
    return 0;
}
