#include <iostream>

struct Date {
    int hours = 0;
    int minutes = 0;
};

int main() {
    Date current;
    int duration;

    // Введення даних
    if (!(std::cin >> current.hours >> current.minutes >> duration)) {
        return 0;
    }

    // Обчислення загальної кількості хвилин
    int total_minutes = current.hours * 60 + current.minutes + duration;

    // Розрахунок нових значень (з урахуванням переходу через добу)
    int final_hours = (total_minutes / 60) % 24;
    int final_minutes = total_minutes % 60;

    // Виведення результату у форматі ГГ:ХХ
    std::cout << final_hours << ":" << (final_minutes < 10 ? "0" : "") << final_minutes << std::endl;

    return 0;
}
