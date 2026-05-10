#include <iostream>

using namespace std;

class Square
{
private:
    double side;
    double area;

public:
    Square(double s)
    {
        set_side(s);
    }

    void set_side(double s)
    {
        if (s >= 0)
        {
            side = s;
            area = side * side;
        }
    }

    void print()
    {
        cout << "Side: " << side << endl;
        cout << "Area: " << area << endl;
    }
};

int main()
{
    Square square(5);
    square.print();

    square.set_side(7);
    square.print();

    square.set_side(-3);
    square.print();

    return 0;
}
