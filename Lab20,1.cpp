#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    int age;
    string city;
};

void print(Person* person)
{
    cout << person->name << " is " << person->age << " years old, city: " << person->city << endl;
}

int main()
{
    Person person1;
    person1.name = "Harry";
    person1.age = 23;
    person1.city = "London";

    Person person2;
    person2.name = "John";
    person2.age = 30;
    person2.city = "New York";

    Person person3;
    person3.name = "Anna";
    person3.age = 19;
    person3.city = "Kyiv";

    cout << "Meet " << person1.name << endl;
    print(&person1);

    cout << "Meet " << person2.name << endl;
    print(&person2);

    cout << "Meet " << person3.name << endl;
    print(&person3);

    return 0;
}
