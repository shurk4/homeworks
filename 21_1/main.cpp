/*
Что нужно сделать

Вы уже создавали программу чтения и записи ведомости. Теперь её надо будет обобщить и дополнить использованием структур.

Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее — дата выдачи в формате ДД.ММ.ГГГГ.,
затем — сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой записи должен быть перевод строки.

Структура данных записи должна соответствовать указанному формату.

При старте программы пользователь указывает команду, которую следует осуществить: list или add.
Команда read осуществляет чтение из файла ведомости как и прежде, только уже в структуры данных и отображает их на экране.

Команда add добавляет новую запись в конец ведомости.

Советы и рекомендации

Чтобы определить конец файла, используйте функцию file.eof() как и прежде. Из-за завершающего переноса строки, также стоит проверить и имя.
Если оно было считает пустым, то можно считать, что файл закончился.
*/

//!!!!!!!!!!!!!!!!!!!! Спросить почему происходит глюк с ADD !!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

struct payroll{
    std::string firstName,
                lastName,
                date,
                salary;
};

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
        if((salary[i] >= '0' && salary[i] <= '9') || salary[i] == '.'){
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

// добавление записи в ведомость
void add (){
    std::string dataIn;
    payroll tempIn;
    bool valid;
    do {
        valid = true;
        std::stringstream temp;

        std::cout << "Enter the data in the format: First name last name date dd.mm.yyyy salary" << std::endl;

        std::getline(std::cin, dataIn);
        temp << dataIn;

        temp >> tempIn.firstName >> tempIn.lastName >> tempIn.date >> tempIn.salary;
        temp.clear();

        if(!dateValid(tempIn.date)) {
            std::cout << "Wrong date, try again!" << std::endl;
            valid = false;
        }
        if(!nameValid(tempIn.firstName)) {
            std::cout << "Wrong first name, try again!" << std::endl;
            valid = false;
        }
        if(!nameValid(tempIn.lastName)) {
            std::cout << "Wrong last name, try again!" << std::endl;
            valid = false;
        }
        if(!salaryValid(tempIn.salary)) {
            std::cout << "Wrong salary format, try again!" << std::endl;
            valid = false;
        }
        if(valid) {
            salaryConvert(tempIn.salary);

            temp << tempIn.firstName << " " << tempIn.lastName << " " << tempIn.date << " " << tempIn.salary;
            std::getline(temp, dataIn);
        }
    } while (!valid);

    std::ofstream file("..\\payroll.txt", std::ios::app);
    if(file.is_open()) {
        file << dataIn << std::endl;
        file.close();
    } else {
        std::cout << "Cannot opet the file payroll.txt!" << std::endl;
    }
}

// Загрузка данных из ведомости
void load(std::vector<payroll>& workers){
    workers.clear();
    int i = 0;
    std::ifstream file ("..\\payroll.txt");
    if(file.is_open()){
        if (file.peek() == EOF){
            std::cout << "File is empty!" << std::endl;
            return;
        }

        while(!file.eof()){
            std::stringstream tempStream;
            std::string tempString;
            payroll temp;

            getline(file, tempString);
            if(tempString.size() == 0) {
                continue;
            }

            tempStream << tempString;
            tempStream >> temp.firstName >> temp.lastName >> temp.date >> temp.salary;

            workers.push_back(temp);
        }

        file.close();
    } else {
        std::cout << "Cannot opet the file payroll.txt!" << std::endl;
    }
}

// Вывод данных на экран
void print(std::vector<payroll>& workers){
    std::cout << "======================================" << std::endl;
    for(int i = 0; i < workers.size(); i++){
        std::cout << workers[i].firstName << " " << workers[i].lastName << " \t" <<
                     workers[i].date << " " << workers[i].salary << std::endl;
    }
    std::cout << "======================================" << std::endl;
}

int main() {
    std::vector<payroll> workers;
    std::string input;

    load(workers);

    do {
        do {
            std::cout
                    << "Enter \"add\" to add an entry to the payroll, \"list\" to view the payroll or \"q\" for end the programm." << std::endl;
            std::cin >> input;
        } while (input != "add" && input != "list" && input != "q");

        if (input == "add") {
            add();
        }
        if (input == "list") {
            print(workers);
        }
    } while (input != "q");

    return 0;
}