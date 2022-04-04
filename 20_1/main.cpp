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
#include <iomanip>

// Проверка имён на сторонние символы
bool nameValid(std::string& name){
    for(int i = 0; i < name.length(); i++){
        if((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')){
            return true;
        } else {
            return false;
        }
    }
}

// Проверка даты
bool dateValid(std::string& date){
    if (date.length() < 10) {
        return false;
    } else if(std::stoi(date.substr(3, 2)) < 1 || std::stoi(date.substr(3, 2)) > 12) {
        return false;
    } else {
        return true;
    }
}

// Проверка зарплаты
bool salaryValid(std::string& salary){
    bool point = false;
    for(int i = 0; i < salary.length(); i++){
        if((salary[i] >= '0' && salary[i] <= '9') || (salary[i] == '.' && i != '0')){
            if(salary[i] == '.' && point == false){
                point = i;
            } else if(salary[i] == '.' && point == true){
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

//Конвертация з.п. до сотых
void salaryConvert(std::string& salary){
    double salaryTemp;
    std::stringstream stream;

    salaryTemp = std::stod(salary);
    stream << std::fixed << std::setprecision(2) << salaryTemp;
    stream >> salary;
}

std::string input (){
    std::string dataIn,
            firstName,
            lastName,
            date,
            salary;
    bool valid;
    do {
        valid = true;
        std::stringstream temp;

        std::cout << "Enter the data in the format: First name last name date dd.mm.yyyy salary" << std::endl;
        std::getline(std::cin, dataIn);
        temp << dataIn;

        dataIn = "";
        temp >> firstName >> lastName >> date >> salary;
        temp.clear();

        if(!dateValid(date)) {
            std::cout << "Wrong date, try again!" << std::endl;
            valid = false;
        }
        if(!nameValid(firstName)) {
            std::cout << "Wrong first name, try again!" << std::endl;
            valid = false;
        }
        if(!nameValid(lastName)) {
            std::cout << "Wrong last name, try again!" << std::endl;
            valid = false;
        }
        if(!salaryValid(salary)) {
            std::cout << "Wrong salary format, try again!" << std::endl;
            valid = false;
        }
        if(valid) {
            salaryConvert(salary);

            temp << firstName << " " << lastName << " " << date << " " << salary;
            std::getline(temp, dataIn);
        }
    } while (!valid);

    return dataIn;
}

int main() {
    std::ofstream file("..\\payroll.txt", std::ios::app);

    file << input() << std::endl;

    file.close();
    return 0;
}
