#include <iostream>
#include <vector>
#include <algorithm>

void replaceNegativeBeforeFirstMax(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    auto max_it = std::max_element(arr.begin(), arr.end());
    int first_max_index = std::distance(arr.begin(), max_it);

    for (int i = 0; i < first_max_index; ++i) {
        if (arr[i] < 0) {
            arr[i] = 0;
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {5, -10, 8, -3, 15, 2, -7, 15, 4};
    std::cout << "Initial: ";
    printArray(data);

    replaceNegativeBeforeFirstMax(data);

    std::cout << "Result:  ";
    printArray(data);

    return 0;
}
