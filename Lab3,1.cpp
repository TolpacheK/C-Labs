#include <iostream>

int count_digits_less_than_seven(int N) {
    int count = 0;

    int digit_units = N % 10;
    if (digit_units < 7) {
        count++;
    }

    N = N / 10; 

    int digit_tens = N % 10;
    if (digit_tens < 7) {
        count++;
    }

    N = N / 10; 

    int digit_hundreds = N;
    if (digit_hundreds < 7) {
        count++;
    }

    return count;
}

int main() {

    const int N_VALUE = 853; 
    
    if (N_VALUE < 100 || N_VALUE > 999) {
      
    }

    int result = count_digits_less_than_seven(N_VALUE);

    std::cout << result << std::endl;

    return 0;
}
