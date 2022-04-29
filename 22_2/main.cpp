/*Напишите программу «Регистратура».

На вход программе приходят строки с фамилиями или строка Next.
 Пришедшие люди становятся в очередь, а по запросу Next необходимо вызвать в регистратуру человека с фамилией,
 идущей первой в лексикографическом порядке (по алфавиту), и вывести его фамилию на экран. Фамилии пациентов могут повторяться.

Каждый запрос (на добавление и вывод) должен работать за O(logn).



Пример:

← Sidorov

← Ivanov

← Ivanov

← Petrov

← Next

→ Ivanov

← Next

→ Ivanov

← Next

→ Petrov
*/

#include <iostream>
#include <map>

void qeue (std::map<std::string, int>& registry){
    for(auto i = registry.begin(); i != registry.end(); i++){
        std::cout << i->first << " " << i->second << std::endl;
    }
}

void add (std::map<std::string, int>& registry, std::string& input){
    registry[input]++;
}

void next (std::map<std::string, int>& registry){
    if(!registry.empty()) {
        std::cout << registry.begin()->first << std::endl;
        registry.begin()->second --;

        if(registry.begin()->second == 0) {
            registry.erase(registry.begin());
        }
    }
    else {
        std::cout << "Qeue is empty!" << std::endl;
    }
}

int main() {
    std::map<std::string, int > registry;
    std::string input;

    do {
        std::cout << "Enter data:" << std::endl;
        std::cin >> input;

        if(input == "next"){
            next(registry);
        }
        else if (input == "qeue"){
            qeue(registry);
        }
        else if (input == "q"){
            std::cout << "Bye!" << std::endl;
        }
        else {
            add(registry, input);
        }

    } while(input != "q");
    return 0;
}
