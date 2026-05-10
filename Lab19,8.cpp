#include <string>
#include <iostream>
#include <map>

int main()
{
    std::string values;
    std::getline(std::cin, values);

    std::string text;
    std::getline(std::cin, text);

    std::map<std::string, std::string> pairs;

    int start = 0;
    while (start < values.length()) {
        int comma = values.find(',', start);
        if (comma == std::string::npos) {
            comma = values.length();
        }

        std::string pair = values.substr(start, comma - start);
        int equal = pair.find('=');

        if (equal != std::string::npos) {
            std::string name = pair.substr(0, equal);
            std::string value = pair.substr(equal + 1);
            pairs[name] = value;
        }

        start = comma + 1;
    }

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '[') {
            int close = text.find(']', i);

            if (close != std::string::npos) {
                std::string name = text.substr(i + 1, close - i - 1);

                if (pairs.find(name) != pairs.end()) {
                    std::cout << pairs[name];
                } else {
                    std::cout << text.substr(i, close - i + 1);
                }

                i = close;
            } else {
                std::cout << text[i];
            }
        } else {
            std::cout << text[i];
        }
    }

    std::cout << "\n";

    return 0;
}
