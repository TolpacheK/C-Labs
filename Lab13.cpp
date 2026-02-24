#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));
    const int N = 4;
    int matrix[N][N];
    int* ptr = (int*)matrix;

    for (int i = 0; i < N * N; i++) {
        *(ptr + i) = rand() % 100;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << *(ptr + i * N + j) << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\nMain diagonal: ";
    for (int i = 0; i < N; i++) {
        std::cout << *(ptr + i * N + i) << " ";
    }

    std::cout << "\nSide diagonal: ";
    for (int i = 0; i < N; i++) {
        std::cout << *(ptr + i * N + (N - 1 - i)) << " ";
    }

    int even = 0, odd = 0;
    for (int i = 0; i < N * N; i++) {
        if (*(ptr + i) % 2 == 0) even++;
        else odd++;
    }

    std::cout << "\nEven count: " << even;
    std::cout << "\nOdd count: " << odd << std::endl;

    return 0;
}
