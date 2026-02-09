#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));
    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    int min_idx = 0, max_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[min_idx]) min_idx = i;
        if (a[i] > a[max_idx]) max_idx = i;
    }

    int temp = a[min_idx];
    a[min_idx] = a[max_idx];
    a[max_idx] = temp;

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }

    return 0;
}
