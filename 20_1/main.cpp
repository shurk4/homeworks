/*В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат.
Теперь требуется создать простую программу записи в эту ведомость.

Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств,
далее располагается дата выдачи в формате ДД.ММ.ГГГГ.
Завершает запись сумма выплаты в рублях. Данные разделяются между собой пробелами.
В конце каждой записи должен быть расположен перевод строки.

При старте программы пользователь последовательно вводит данные для новой записи,
которые записываются затем в файл в текстовом режиме.
Программа должна добавлять новые записи в конец файла, не удаляя его текущее содержимое.

Советы и рекомендации
Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.

Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr
с корректно указанным диапазоном символов в дате.
К примеру, вызов std::stoi(date.substr(3, 2)) вычленит из строковой даты целочисленный месяц для последующего анализа.*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool dateValid(std::string& date){
    if (date.length() < 10) {
        return false;
    } else if(std::stoi(date.substr(3, 2)) < 1 || std::stoi(date.substr(3, 2)) > 12) {
        return false;
    } else {
        return true;
    }
}

std::string input (){
    std::string dataIn,
            dummy,
            date;

    do {
        std::stringstream temp;
        std::cout << "Enter the data in the format: First name last name date dd.mm.yyyy salary" << std::endl;
        std::getline(std::cin, dataIn);
        temp << dataIn;
        temp >> dummy >> dummy >> date;
        if(!dateValid(date)) {
            std::cout << "Wrong date, try again!" << std::endl;
        }
    } while (!dateValid(date));

    return dataIn;
}

int main() {
    std::ofstream file("..\\payroll.txt", std::ios::app);

    file << input() << std::endl;

    file.close();
    return 0;
}
