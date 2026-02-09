#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <climits>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    int n = 10;
    std::vector<int> arr;

    while (arr.size() < n) {
        int num = dis(gen);
        if (std::find(arr.begin(), arr.end(), num) == arr.end()) {
            arr.push_back(num);
        }
    }

    std::cout << "Array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    int first = INT_MIN;
    int second = INT_MIN;

    for (int x : arr) {
        if (x > first) {
            second = first;
            first = x;
        } else if (x > second) {
            second = x;
        }
    }

    std::cout << "Second largest: " << second << std::endl;

    return 0;
}
