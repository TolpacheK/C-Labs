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

    Fraction plus(Fraction that);
    Fraction minus(Fraction that);
    Fraction times(Fraction that);
    Fraction by(Fraction that);

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
    reduce();
}

void Fraction::reduce()
{
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

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

Fraction Fraction::plus(Fraction that)
{
    int num = numerator * that.denominator + that.numerator * denominator;
    int den = denominator * that.denominator;

    return Fraction(num, den);
}

Fraction Fraction::minus(Fraction that)
{
    int num = numerator * that.denominator - that.numerator * denominator;
    int den = denominator * that.denominator;

    return Fraction(num, den);
}

Fraction Fraction::times(Fraction that)
{
    int num = numerator * that.numerator;
    int den = denominator * that.denominator;

    return Fraction(num, den);
}

Fraction Fraction::by(Fraction that)
{
    int num = numerator * that.denominator;
    int den = denominator * that.numerator;

    return Fraction(num, den);
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

    cout << first.toString() << " + " << second.toString() << " = "
         << first.plus(second).toString() << endl;

    cout << first.toString() << " - " << second.toString() << " = "
         << first.minus(second).toString() << endl;

    cout << first.toString() << " * " << second.toString() << " = "
         << first.times(second).toString() << endl;

    cout << first.toString() << " / " << second.toString() << " = "
         << first.by(second).toString() << endl;

    return 0;
}
