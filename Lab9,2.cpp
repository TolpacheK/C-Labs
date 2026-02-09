#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(0));
    
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int A;
    std::cin >> A;

    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] > A) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
