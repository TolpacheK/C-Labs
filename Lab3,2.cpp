#include <iostream>
#include <string>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8"); 
    
    // Дані для 7 студентів
    const int num_students = 7;
    
    // масиви для зберігання даних
    const int student_numbers[num_students] = {1, 2, 3, 4, 5, 6, 7};
    const std::string student_names[num_students] = {"Іваненко", "Петренко", "Сидоренко", "Ковальчук", "Мельник", "Шевченко", "Лисенко"};
    const double student_grades[num_students] = {4.55, 3.80, 4.90, 4.25, 3.95, 4.70, 4.15};

    int search_number;
    
    std::cout << "Введіть номер студента 1-7: ";
    
    // Перевірка коректності вводу
    if (!(std::cin >> search_number)) {
        std::cerr << "Некоректний номер.\n";
        return 1;
    }

    bool found = false;
    
    // Цикл для пошуку номера студента
    for (int i = 0; i < num_students; ++i) {
        if (student_numbers[i] == search_number) {
            // Знайдено: виводимо ім'я та середній бал
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Студент: " << student_names[i] << std::endl;
            std::cout << "Середній бал: " << student_grades[i] << std::endl;
            found = true;
            break; // Перериваємо цикл після знаходження
        }
    }

    // Якщо цикл завершився, але студента не знайдено
    if (!found) {
        std::cout << "Студента з номером " << search_number << " не знайдено.\n";
    }

    return 0;
}
