/*Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу этого дня недели в текстовом виде в консоль.

В начале программы пользователь вводит день недели в виде его порядкового номера.
 В результате в консоли появляется буквенное отображение этого дня недели.

В этом упражнении запрещается использовать классические переменные, кроме как для хранения ввода пользователя.
 Использовать строковые литералы напрямую тоже нельзя. Всё должно быть реализовано исключительно на макросах.

Советы и рекомендации

        Конкатенация двух фрагментов может породить токен, который в свою очередь является именем макроса,
        и этот макрос тоже раскроется. Используйте данное свойство для перевода константы дня недели в строковый литерал.

Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью “Shift-Shift -> Preprocess current TU”.*/

#include <iostream>

#define MONDAY (1)
#define TUESDAY (2)
#define WEDNESDAY (3)
#define THURSDAY (4)
#define FRIDAY (5)
#define SATURDAY (6)
#define SUNDAY (7)

#define PREF "You entered: "

int main() {
    int day;
    std::cin >> day;

    if(day == MONDAY)
    {
        std::cout << PREF "Monday" << std::endl;
    }

    if(day == TUESDAY)
    {
        std::cout << PREF "Tuesday" << std::endl;
    }

    if(day == WEDNESDAY)
    {
        std::cout << PREF "Wedbesday" << std::endl;
    }

    if(day == THURSDAY)
    {
        std::cout << PREF "Thursday" << std::endl;
    }

    if(day == FRIDAY)
    {
        std::cout << PREF "Friday" << std::endl;
    }

    if(day == SATURDAY)
    {
        std::cout << PREF "Saturday" << std::endl;
    }

    if(day == SUNDAY)
    {
        std::cout << PREF "Sunday" << std::endl;
    }

    return 0;
}
