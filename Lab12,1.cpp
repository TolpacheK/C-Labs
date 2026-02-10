#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void) {
    srand(time(0));
    int vector[10];
    int n = sizeof(vector) / sizeof(vector[0]);

    for (int *p = vector; p < vector + n; p++) {
        *p = rand() % 100 - 50;
        cout << *p << " ";
    }
    cout << endl;

    int *min = vector;
    for (int *p = vector + 1; p < vector + n; p++) {
        if (*p < *min) {
            min = p;
        }
    }

    cout << *min << endl;

    return 0;
}
