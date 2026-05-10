#include <string>
#include <iostream>
#include <cctype>

int main()
{
    std::string password;
    std::getline(std::cin, password);

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (int i = 0; i < password.length(); i++) {
        if (std::isupper(password[i])) {
            hasUpper = true;
        } else if (std::islower(password[i])) {
            hasLower = true;
        } else if (std::isdigit(password[i])) {
            hasDigit = true;
        } else {
            hasSpecial = true;
        }
    }

    bool valid = true;

    if (password.length() < 8) {
        std::cout << "The password must be 8 characters long" << std::endl;
        valid = false;
    }

    if (!hasUpper) {
        std::cout << "The password must have at least one upper case letter" << std::endl;
        valid = false;
    }

    if (!hasLower) {
        std::cout << "The password must have at least one lower case letter" << std::endl;
        valid = false;
    }

    if (!hasDigit) {
        std::cout << "The password must have at least one digit" << std::endl;
        valid = false;
    }

    if (!hasSpecial) {
        std::cout << "The password must have at least one special character" << std::endl;
        valid = false;
    }

    if (valid) {
        std::cout << "The password is valid" << std::endl;
    }

    return 0;
}
