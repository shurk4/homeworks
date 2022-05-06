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

#define OUT(a) std::cout << "You entered: " << a << std::endl;

int main() {
    int day;
    std::cout << "Enter the day number: ";
    std::cin >> day;

    if(day == MONDAY)
    {
        OUT("Monday");
    }

    if(day == TUESDAY)
    {
        OUT("Tuesday");
    }

    if(day == WEDNESDAY)
    {
        OUT("Wedbesday");
    }

    if(day == THURSDAY)
    {
        OUT("Thursday");
    }

    if(day == FRIDAY)
    {
        OUT("Friday");
    }

    if(day == SATURDAY)
    {
        OUT("Saturday");
    }

    if(day == SUNDAY)
    {
        OUT("Sunday");
    }

    return 0;
}
