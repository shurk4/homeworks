/*Что нужно сделать

В поезде всего 10 вагонов.
В каждом из этих вагонов может находиться до 20-ти пассажиров — это оптимальное их количество.
 Проанализируйте количество людей в каждом из вагонов и сначала сообщите об излишне заполненных вагонах,
 далее о вагонах с пустыми пассажирскими местами. В заключении выведите общее количество пассажиров во всех вагонах.

При старте программы пользователь вводит количество пассажиров в каждом из вагонов.
 Замечания о вагонах должны выводиться в стандартную консоль.

При выполнении задания пользоваться for-циклами напрямую не разрешается, только опосредованно, через макросы.



Советы и рекомендации

С помощью макроса реализуйте модульный способ вызова функции-предиката над элементами массива.
 Сами функции-предикаты реализуйте отдельно, в виде обычных классических функций (не макросов).

Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью “Shift-Shift -> Preprocess current TU”.



Что оценивается

Корректность работы программы. Модульность и элегантность решения с помощью макросов.*/

#include <iostream>
#include <vector>

#define CICLE(size, a) for(int i = 0; i < size; i++){a}

#define INPUT CICLE(10, IN)
#define ANALIZE CICLE(10, CALC_RESULT)
#define RESULT OVER UNFILLED OVERALL

#define IN std::cout << "Enter the number of passengers in wagon " << i + 1 << ": ";\
           std::cin >> wagon[i];

#define CALC_RESULT if(wagon[i] < 20)       \
             {                       \
             empty.push_back(i);     \
             }                       \
             else if(wagon[i] > 20)  \
             {                       \
             full.push_back(i);      \
             }
#define OVER  std::cout << "Overcrowded wagons:" << std::endl;\
              CICLE(full.size(), OVER_OUT)
#define OVER_OUT std::cout << "Wagon " << full[i] << " have " << wagon[full[i]] << " passangers" << std::endl;


#define UNFILLED std::cout << "Unfilled wagons:" << std::endl;\
                 CICLE(full.size(), UNFILLED_OUT)
#define UNFILLED_OUT std::cout << "Wagon " << empty[i] << " have " << wagon[empty[i]] << " passangers" << std::endl;

#define OVERALL int temp = 0;\
                CICLE(10, CALC) \
                std::cout << temp << std::endl;
#define CALC temp += wagon[i];

int main() {
    int wagon[10];
    std::vector<int> full;
    std::vector<int> empty;

    INPUT
    ANALIZE
    RESULT



    return 0;
}
