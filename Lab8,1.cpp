#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_array(const vector<int>& arr, const string& title) {
    cout << title << endl;
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl << endl;
}

int main() {
    const int SIZE = 12;
    srand(time(0));
    vector<int> arr(SIZE);
    
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100;
    }
    
    print_array(arr, "--- Початковий масив ---");

    vector<int> ascending_arr = arr; 
    sort(ascending_arr.begin(), ascending_arr.end());
    print_array(ascending_arr, "--- Зростання ---");
    
    sort(arr.begin(), arr.end(), greater<int>());
    print_array(arr, "--- Спадання ---");

    return 0;
}
