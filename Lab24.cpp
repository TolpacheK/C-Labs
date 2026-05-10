#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();

    bool isGreaterThan(Fraction that);
    bool isLessThan(Fraction that);
    bool isEqual(Fraction that);

private:
    int numerator;
    int denominator;
    void reduce();
};

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;

    if (this->denominator < 0) {
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }
}

void Fraction::reduce()
{
    int d = gcd(numerator, denominator);

    numerator /= d;
    denominator /= d;
}

string Fraction::toString()
{
    int num = abs(numerator);
    int den = denominator;

    int whole = num / den;
    int rest = num % den;

    string result = "";

    if (numerator < 0) {
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

bool Fraction::isGreaterThan(Fraction that)
{
    return numerator * that.denominator > that.numerator * denominator;
}

bool Fraction::isLessThan(Fraction that)
{
    return numerator * that.denominator < that.numerator * denominator;
}

bool Fraction::isEqual(Fraction that)
{
    return numerator * that.denominator == that.numerator * denominator;
}

int main()
{
    int num1, den1, num2, den2;
    char slash;
    string input;

    getline(cin, input);
    stringstream ss1(input);
    ss1 >> num1 >> slash >> den1;

    getline(cin, input);
    stringstream ss2(input);
    ss2 >> num2 >> slash >> den2;

    Fraction first(num1, den1);
    Fraction second(num2, den2);

    if (first.isGreaterThan(second)) {
        cout << first.toString() << " > " << second.toString() << endl;
    } else if (first.isLessThan(second)) {
        cout << first.toString() << " < " << second.toString() << endl;
    } else if (first.isEqual(second)) {
        cout << first.toString() << " = " << second.toString() << endl;
    }

    return 0;
}
