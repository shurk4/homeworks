/*Реализуйте работу точного таймера с визуальной отдачей.

В начале программы пользователь вводит количество минут и секунд, которые требуется засечь на таймере, и нажимает «Ввод».

После этого начинается обратный отсчёт времени, о чём незамедлительно и последовательно сообщается пользователю.
 Формат вывода такой же, как и при вводе интервала: минуты и секунды.

Как только отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль специального сообщения.
 Сообщение вместо аудиосигнала может выглядеть так: DING! DING! DING!

Советы и рекомендации
Для ввода значения для засекания времени используйте std::get_time, но в качестве формата запросите только минуты и секунды.
 Целевое время для остановки таймера вычислите сами с помощью манипуляции над текущим std::time.
 Количество оставшегося времени выводите в цикле и вычислите его самостоятельно с помощью обращения с типом std::time_t как с секундами.*/

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip>

int main() {
    std::tm timer;

    std::cout << "Enter the timer time in format MM:SS" << std::endl;
    std::cin >> std::get_time(&timer, "%M:%S");

    std::time_t current_t = std::time(nullptr);
    std::time_t target_t = current_t + (timer.tm_min * 60 + timer.tm_sec);

    while (target_t - current_t > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds (1));
        current_t = std::time(nullptr);
        int temp = target_t - current_t;
        std::cout << std::setw(2) << std::setfill('0') << temp / 60 << ":" <<
                     std::setw(2) << std::setfill('0') << temp%60 << std::endl;
        if (target_t - current_t == 0)
        {
            std::cout << "DING! DING! DING!" << std::endl;
        }
    }
    return 0;
}
