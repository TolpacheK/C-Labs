#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class IPAddress {
public:
    IPAddress(string address) {
        this->address = address;
    }

    IPAddress(const IPAddress& other) {
        this->address = other.address;
    }

    virtual void print() {
        cout << address;
    }

protected:
    string address;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(string address) : IPAddress(address) {
        correct = check(address);
    }

    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other) {
        correct = other.correct;
    }

    void print() {
        IPAddress::print();

        if (correct) {
            cout << " - Correct";
        } else {
            cout << " - Not Correct";
        }
    }

private:
    bool correct;

    bool check(string address) {
        string part;
        stringstream ss(address);
        int count = 0;

        while (getline(ss, part, '.')) {
            if (part.length() == 0) {
                return false;
            }

            for (int i = 0; i < part.length(); i++) {
                if (!isdigit(part[i])) {
                    return false;
                }
            }

            int number = stoi(part);

            if (number < 0 || number > 255) {
                return false;
            }

            count++;
        }

        return count == 4;
    }
};

int main() {
    string ip1, ip2, ip3;

    cin >> ip1;
    cin >> ip2;
    cin >> ip3;

    IPAddress address1(ip1);
    IPAddressChecked address2(ip2);
    IPAddressChecked address3(ip3);

    address1.print();
    cout << endl;

    address2.print();
    cout << endl;

    address3.print();
    cout << endl;

    return 0;
}
