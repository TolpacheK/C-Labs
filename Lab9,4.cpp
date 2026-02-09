#include <iostream>
#include <vector>
#include <ctime>

int main() {
    srand(time(0));
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    int index = -1;

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10; 
        if (index == -1 && arr[i] == 0) {
            index = i;
        }
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    if (index != -1) {
        std::cout << index << std::endl;
    } else {
        std::cout << "Масив не містить нульових елементів" << std::endl;
    }

    return 0;
}
