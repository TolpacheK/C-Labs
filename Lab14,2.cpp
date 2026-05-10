#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));

    int n = 3;
    int** arr = new int*[n];

    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    int even = 0;
    int odd = 0;

    cout << "Masiv:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "\t";

            if (arr[i][j] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        cout << endl;
    }

    cout << "Holovna diagonal: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i][i] << " ";
    }

    cout << endl;

    cout << "Pobichna diagonal: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i][n - 1 - i] << " ";
    }

    cout << endl;

    cout << "Kilkist parnyh elementiv: " << even << endl;
    cout << "Kilkist neparnyh elementiv: " << odd << endl;

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
