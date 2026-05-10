#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));

    int n = 10;
    double* arr = new double[n];

    int positive = 0;
    int negative = 0;

    cout << "Masiv: ";

    for (int i = 0; i < n; i++) {
        arr[i] = -2.0 + (double)rand() / RAND_MAX * 4.0;
        cout << arr[i] << " ";

        if (arr[i] > 0) {
            positive++;
        } else if (arr[i] < 0) {
            negative++;
        }
    }

    cout << endl;
    cout << "Kilkist dodatnih chysel: " << positive << endl;
    cout << "Kilkist vid'emnyh chysel: " << negative << endl;

    delete[] arr;

    return 0;
}
