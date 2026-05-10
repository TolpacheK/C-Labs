#include <iostream>
#include <string>

class FlightBooking {
public:
    FlightBooking();
    FlightBooking(int id, int capacity, int reserved);

    int getId();
    void create(int id, int capacity);
    void remove();
    void printStatus();

    bool add(int n);
    bool cancel(int n);

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking()
{
    id = 0;
    capacity = 0;
    reserved = 0;
}

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

int FlightBooking::getId()
{
    return id;
}

void FlightBooking::create(int id, int capacity)
{
    this->id = id;
    this->capacity = capacity;
    this->reserved = 0;
}

void FlightBooking::remove()
{
    id = 0;
    capacity = 0;
    reserved = 0;
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

int findFlight(FlightBooking flights[], int id)
{
    for (int i = 0; i < 10; i++) {
        if (flights[i].getId() == id) {
            return i;
        }
    }

    return -1;
}

int findEmptyPlace(FlightBooking flights[])
{
    for (int i = 0; i < 10; i++) {
        if (flights[i].getId() == 0) {
            return i;
        }
    }

    return -1;
}

int main()
{
    FlightBooking flights[10];

    std::string command;

    while (std::cin >> command) {
        if (command == "quit") {
            break;
        }

        if (command == "create") {
            int id, cap;
            std::cin >> id >> cap;

            int emptyPlace = findEmptyPlace(flights);

            if (id == 0 || cap <= 0 || findFlight(flights, id) != -1 || emptyPlace == -1) {
                std::cout << "Cannot perform this operation" << std::endl;
            } else {
                flights[emptyPlace].create(id, cap);
                flights[emptyPlace].printStatus();
            }
        } else if (command == "delete") {
            int id;
            std::cin >> id;

            int index = findFlight(flights, id);

            if (index == -1) {
                std::cout << "Cannot perform this operation" << std::endl;
            } else {
                flights[index].remove();
            }
        } else if (command == "add") {
            int id, n;
            std::cin >> id >> n;

            int index = findFlight(flights, id);

            if (index == -1 || !flights[index].add(n)) {
                std::cout << "Cannot perform this operation" << std::endl;
            } else {
                flights[index].printStatus();
            }
        } else if (command == "cancel") {
            int id, n;
            std::cin >> id >> n;

            int index = findFlight(flights, id);

            if (index == -1 || !flights[index].cancel(n)) {
                std::cout << "Cannot perform this operation" << std::endl;
            } else {
                flights[index].printStatus();
            }
        } else {
            std::cout << "Cannot perform this operation" << std::endl;
        }
    }

    return 0;
}
