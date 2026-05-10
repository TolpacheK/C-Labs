#include <iostream>

using namespace std;

int main(void) {
    int a = 0, b = 0, c = 0;

    cin >> b;
    cin >> a;

    try {
        if (a == 0) {
            throw "Your input is not valid, you can't divide by zero.";
        }

        c = b / a;
        cout << c << endl;
    }
    catch (const char* message) {
        cout << message << endl;
    }

    return 0;
}
