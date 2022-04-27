/*
Напишите программу «Телефонный справочник».

На вход программе поступают запросы трёх типов:

69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник

69-70-30 — узнать фамилию абонента по номеру телефона

Ivanov — узнать телефон абонента по фамилии

Необходимо выводить в консоль ответ на запросы 2 и 3.
 Обратите внимание, что абоненты по разным номерам могут иметь одинаковые фамилии.
 В таком случае на запрос 3 необходимо выдать все номера через пробелы.

Операции запросов должны работать за O(logn) или O(logn × количество номеров с этой фамилией).

Чек-лист для проверки задачи
Программа корректно выводит фамилии и списки номеров.
Программа использует только заголовочные файлы <iostream>, <string>, <map> и, возможно, вектор.
*/

#include <iostream>
#include <string>
#include <map>

void mapPrint(std::map<std::string, std::string>& book){
    std::cout << "List sorted by phone" << std::endl;
    for(auto it = book.begin(); it != book.end(); it++){
        std::cout << it -> first << " " << it -> second << std::endl;
    }
}

void multimapPrint(std::multimap<std::string, std::string>& book){
    std::cout << "List sorted by name" << std::endl;
    for(auto it = book.begin(); it != book.end(); it++){
        std::cout << it -> first << " " << it -> second << std::endl;
    }
}

// проверка ввода
bool inputCheck(std::string& input){
    bool result = true;

    if(input[0] >= '0' && input[0] <= '9') {
        for (int i = 0; i < input.length(); i++) {
            if (((i == 2 || i == 5) && input[i] != '-') ||
                ((i < 8 && i != 2 && i != 5) && (input[i] < '0' || input[i] > '9')) ||
                (i == 8 && input[i] != ' ')) {
                std::cout << "Wrong input! Try again:" << std::endl;
                result = false;
                break;
            }
        }
    }
    return result;
}

// действия
void add(std::string input, std::map<std::string, std::string>& phoneMap,
         std::multimap<std::string, std::string>& nameMap){
    std::cout << "Adding data" << std::endl;
    std::string phone = "",
                name = "";

    for(int i = 0; i < input.length(); i++){
        if(i < 8){
            phone += input[i];
        }
        if(i > 8){
            name += input[i];
        }
    }
    std::cout << "Phone: " << phone << " name: " << name << std::endl;
    phoneMap.emplace(phone, name);
    nameMap.emplace(name, phone);
}

void phoneFind(std::string input, std::map<std::string, std::string>& phoneMap){
    std::cout << "Find by phone" << std::endl;
    auto it = phoneMap.find(input);
    if(it != phoneMap.end()){
        std::cout << it -> first << " " << it -> second << std::endl;
    }
    else {
        std::cout << input << " not found" << std::endl;
    }
}

void nameFind(std::string input, std::multimap<std::string, std::string>& nameMap){
    std::cout << "Find by name" << std::endl;
    auto itr = nameMap.equal_range(input);

    for(auto i = itr.first; i != itr.second; i++){
        std::cout << i -> first << " " << i -> second << std::endl;
    }

}

// определение действия
void actionSelect(std::string& input, std::map<std::string, std::string>& phoneMap,
                  std::multimap<std::string, std::string>& nameMap){
    if(input == "phone") {
        mapPrint(phoneMap);
    }
    else if (input == "name") {
        multimapPrint(nameMap);
    }
    else if(input.length() > 8 && input[0] >= '0' && input[0] <= '9'){
        add(input, phoneMap, nameMap);
    }
    else if(input[0] >= '0' && input[0] <= '9'){
        phoneFind(input, phoneMap);
    }
    else {
        nameFind(input, nameMap);
    }
}



int main() {
    std::map<std::string, std::string> phoneMap;
    std::multimap<std::string, std::string> nameMap;
    std::string input;

    phoneMap.emplace("12-34-56", "Ivanov");
    phoneMap.emplace("23-45-67", "Petrov");
    phoneMap.emplace("34-56-78", "Sidorov");
    phoneMap.emplace("45-67-89", "Smirnov");
    phoneMap.emplace("56-78-90", "Petrov");
    phoneMap.emplace("67-89-01", "Sidorov");
    phoneMap.emplace("78-90-12", "Ivanov");
    phoneMap.emplace("89-01-23", "Petrov");

    nameMap.emplace("Ivanov", "12-34-56");
    nameMap.emplace("Petrov", "23-45-67");
    nameMap.emplace("Sidorov", "34-56-78");
    nameMap.emplace("Smirnov", "45-67-89");
    nameMap.emplace("Petrov", "56-78-90");
    nameMap.emplace("Sidorov", "67-89-01");
    nameMap.emplace("Ivanov", "78-90-12");
    nameMap.emplace("Petrov", "89-01-23");

    do {
        std::cout << "Please enter data: " << std::endl;
        do {
            std::getline(std::cin, input);
        } while (!inputCheck(input));
        if(input == "q") {
            std::cout << "Bye!" << std::endl;
        }
        else {
            actionSelect(input, phoneMap, nameMap);
        }
    } while (input != "q");
}
