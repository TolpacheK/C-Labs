#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();

private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

string Fraction::toString()
{
    int sign = 1;

    if (numerator < 0) {
        sign *= -1;
    }

    if (denominator < 0) {
        sign *= -1;
    }

    int num = abs(numerator);
    int den = abs(denominator);

    int whole = num / den;
    int rest = num % den;

    string result = "";

    if (sign < 0) {
        result += "-";
    }

    if (rest == 0) {
        result += to_string(whole);
    } else if (whole > 0) {
        result += to_string(whole) + " " + to_string(rest) + "/" + to_string(den);
    } else {
        result += to_string(rest) + "/" + to_string(den);
    }

    return result;
}

double Fraction::toDouble()
{
    return (double)numerator / denominator;
}

int main(void)
{
    int num, den;
    char slash;
    string input;

    getline(cin, input);

    stringstream ss(input);
    ss >> num >> slash >> den;

    Fraction fraction(num, den);

    double value = fraction.toDouble();

    cout << fraction.toString() << " is ";

    if (value == (int)value) {
        cout << fixed << setprecision(1) << value;
    } else {
        cout << value;
    }

    cout << " in decimal" << endl;

    return 0;
}
