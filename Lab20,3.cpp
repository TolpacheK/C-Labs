#include <iostream>

using namespace std;

class AdHocSquare
{
public:
    AdHocSquare(double side)
    {
        this->side = side;
    }

    void set_side(double side)
    {
        if (side >= 0)
        {
            this->side = side;
        }
    }

    double get_area()
    {
        return side * side;
    }

private:
    double side;
};

class LazySquare
{
public:
    LazySquare(double side)
    {
        this->side = side;
        area = side * side;
        side_changed = false;
    }

    void set_side(double side)
    {
        if (side >= 0)
        {
            this->side = side;
            side_changed = true;
        }
    }

    double get_area()
    {
        if (side_changed)
        {
            area = side * side;
            side_changed = false;
        }

        return area;
    }

    bool changet()
    {
        return side_changed;
    }

private:
    double side;
    double area;
    bool side_changed;
};

int main()
{
    AdHocSquare square1(4);
    cout << square1.get_area() << endl;

    square1.set_side(6);
    cout << square1.get_area() << endl;

    LazySquare square2(5);
    cout << square2.get_area() << endl;

    square2.set_side(8);
    cout << square2.changet() << endl;
    cout << square2.get_area() << endl;
    cout << square2.changet() << endl;

    return 0;
}
