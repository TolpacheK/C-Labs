#include <iostream>

struct Date {
    int hours = 0;
    int minutes = 0;
};

int main() {
    Date start, end, duration;

    std::cin >> start.hours >> start.minutes;
    std::cin >> end.hours >> end.minutes;

    int startTotalMinutes = start.hours * 60 + start.minutes;
    int endTotalMinutes = end.hours * 60 + end.minutes;

    int diff = endTotalMinutes - startTotalMinutes;

    if (diff < 0) {
        diff += 24 * 60;
    }

    duration.hours = diff / 60;
    duration.minutes = diff % 60;

    std::cout << duration.hours << ":" << duration.minutes << std::endl;

    return 0;
}
