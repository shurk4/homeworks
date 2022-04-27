/*Напишите функцию, которая принимает две строки и возвращает true,
если первая строка является анаграммой второй (то есть можно получить первую строку из второй путём перестановки букв местами),
и false иначе. Для достижения хорошей асимптотики решения рекомендуется использовать std::map.

Пример анаграммы: лекарство — стекловар

        Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения — bool.
Функция не использует библиотек, кроме <iostream>, <map>, <string>.
Функция корректно определяет, являются ли строки анаграммами.


Как отправить задание на проверку

        Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.*/

#include <iostream>
#include <string>
#include <map>

std::map<char, int> dictionary (std::string& input){
    std::map<char, int> result;
    for(int i = 0; i < input.length(); i++){
        result[input[i]]++;
    }
    return result;
}

bool check(std::string& input1, std::string input2){
    if(input1.length() != input2.length()) {
        return false;
    }
    else {
        if(dictionary(input1) == dictionary(input2)){
            return true;
        }
        else {
            return false;
        }

    }

}

int main() {
    std::string input1,
                input2;
    std::cout << "Enter the first word:" << std::endl;
    std::cin >> input1;
    std::cout << "Enter the second word:" << std::endl;
    std::cin >> input2;

    if(check(input1, input2)) {
        std::cout << "anagram" << std::endl;
    }
    else {
        std::cout << "not anagram" << std::endl;
    }
    return 0;
}
