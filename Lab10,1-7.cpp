#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// Функція для заповнення та виводу масиву
void setupArray(vector<vector<int>>& arr, int m, int n) {
    cout << "Масив " << m << "x" << n << ":" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 100;
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    int choice;

    cout << "Виберіть завдання (1-7): ";
    cin >> choice;
    cout << "---" << endl;

    switch (choice) {
        case 1: {
            int m = 4, n = 3;
            vector<vector<int>> arr(m, vector<int>(n));
            setupArray(arr, m, n);
            for (int i = 0; i < m; i++) {
                int count = 0;
                for (int j = 0; j < n; j++) if (arr[i][j] % 2 == 0) count++;
                cout << "Рядок " << i + 1 << ": парних чисел = " << count << endl;
            }
            break;
        }
        case 2: {
            int m = 6, n = 4;
            vector<vector<int>> arr(m, vector<int>(n));
            setupArray(arr, m, n);
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int i = 0; i < m; i++) if (arr[i][j] % 2 == 0) count++;
                cout << "Стовпчик " << j + 1 << ": парних чисел = " << count << endl;
            }
            break;
        }
        case 3: {
            int m = 5, n = 7;
            vector<vector<int>> arr(m, vector<int>(n));
            setupArray(arr, m, n);
            for (int i = 0; i < m; i++) {
                int sum = 0;
                for (int j = 0; j < n; j++) sum += arr[i][j];
                cout << "Рядок " << i + 1 << ": сума = " << sum << endl;
            }
            break;
        }
        case 4: {
            int m = 4, n = 6;
            vector<vector<int>> arr(m, vector<int>(n));
            setupArray(arr, m, n);
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (int i = 0; i < m; i++) sum += arr[i][j];
                cout << "Стовпчик " << j + 1 << ": сума = " << sum << endl;
            }
            break;
        }
        case 5: {
            int m = 3, n = 4;
            vector<vector<int>> arr(m, vector<int>(n));
            setupArray(arr, m, n);
            int maxVal = arr[0][0], r = 0, c = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (arr[i][j] > maxVal) { maxVal = arr[i][j]; r = i; c = j; }
                }
            }
            cout << "Максимум: " << maxVal << " (рядок " << r + 1 << ", стовпчик " << c + 1 << ")" << endl;
            break;
        }
        case 6: {
            int m = 4, n = 7;
            vector<vector<int>> arr(m, vector<int>(n));
            setupArray(arr, m, n);
            int minVal = arr[0][0], r = 0, c = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (arr[i][j] < minVal) { minVal = arr[i][j]; r = i; c = j; }
                }
            }
            cout << "Мінімум: " << minVal << " (рядок " << r + 1 << ", стовпчик " << c + 1 << ")" << endl;
            break;
        }
        case 7: {
            int m = 5, n = 4;
            vector<vector<int>> arr(m, vector<int>(n));
            setupArray(arr, m, n);
            for (int i = 0; i < m; i++) {
                int minRow = arr[i][0];
                for (int j = 1; j < n; j++) if (arr[i][j] < minRow) minRow = arr[i][j];
                cout << "Рядок " << i + 1 << ": мінімум = " << minRow << endl;
            }
            break;
        }
        default:
            cout << "Невірний вибір." << endl;
    }

    return 0;
}
