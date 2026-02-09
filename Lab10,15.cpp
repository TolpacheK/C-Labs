#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));
    const int m = 3, n = 3;
    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    int mainSum = 0;
    int sideSum = 0;

    for (int i = 0; i < m; i++) {
        mainSum += matrix[i][i];
        sideSum += matrix[i][n - 1 - i];
    }

    std::cout << "Main diagonal sum: " << mainSum << std::endl;
    std::cout << "Side diagonal sum: " << sideSum << std::endl;

    return 0;
}
