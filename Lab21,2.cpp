#include <iostream>
#include <string>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool add(int n);
    bool cancel(int n);

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;

    int maxReserved = capacity * 105 / 100;

    if (reserved < 0) {
        this->reserved = 0;
    } else if (reserved > maxReserved) {
        this->reserved = maxReserved;
    } else {
        this->reserved = reserved;
    }
}

void FlightBooking::printStatus()
{
    int percentage = reserved * 100 / capacity;

    std::cout << "Flight " << id << " : " << reserved << "/" << capacity
              << " (" << percentage << "%) seats reserved" << std::endl;
}

bool FlightBooking::add(int n)
{
    int maxReserved = capacity * 105 / 100;

    if (n < 0 || reserved + n > maxReserved) {
        return false;
    }

    reserved += n;
    return true;
}

bool FlightBooking::cancel(int n)
{
    if (n < 0 || reserved - n < 0) {
        return false;
    }

    reserved -= n;
    return true;
}

int main()
{
    int reserved = 0;
    int capacity = 0;

    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;

    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;

    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();

    std::string command;
    int n;

    while (std::cin >> command) {
        if (command == "quit") {
            break;
        }

        if (!(std::cin >> n)) {
            break;
        }

        if (command == "add") {
            if (!booking.add(n)) {
                std::cout << "Cannot perform this operation" << std::endl;
            }
        } else if (command == "cancel") {
            if (!booking.cancel(n)) {
                std::cout << "Cannot perform this operation" << std::endl;
            }
        } else {
            std::cout << "Cannot perform this operation" << std::endl;
        }

        booking.printStatus();
    }

    return 0;
}
