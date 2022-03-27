#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

void dataPrint(std::vector<std::string>& firstName,
              std::vector<std::string>& lastName,
              std::vector<std::string>& date,
              std::vector<double>& salary){
    for(int i = 0; i < firstName.size(); i++){
        std::cout << firstName[i] << "\t" << lastName[i] << "   \t" << salary[i] << "\t" << date[i] << std::endl;
    }
}

void parce (std::vector<std::string>& firstName,
            std::vector<std::string>& lastName,
            std::vector<std::string>& date,
            std::vector<double>& salary) {

    std::ifstream file("..\\payroll.txt");
    int cursor = 0;

    while(!file.eof()) {
        std::stringstream temp;
        std::string fromFile,
                    fnTemp,
                    lnTemp,
                    dateTemp;
        double salTemp;

        getline(file, fromFile);
        temp << fromFile;

        temp >> fnTemp >> lnTemp >> salTemp >> dateTemp;

        firstName.push_back(fnTemp);
        lastName.push_back(lnTemp);
        salary.push_back(salTemp);
        date.push_back(dateTemp);
    }
    file.close();
}

double salaryExpense (std::vector<double>& salary){
    double salaryEx = 0;
    for(int i = 0; i < salary.size(); i++){
        salaryEx += salary[i];
    }
    return salaryEx;
}

double salaryMax (std::vector<double>& salary){
    double salaryMax = salary[0];
    for(int i = 0; i < salary.size(); i++){
        if(salary[i] > salaryMax) salaryMax = salary[i];
    }
    return salaryMax;
}

int main() {
    std::vector<std::string> firstName,
                             lastName,
                             date;
    std::vector<double> salary;

    std::ifstream file("..\\payroll.txt");
    if(!file.is_open()) {
        std::cout << "File not found!" << std::endl;
        return 1;
    }
    file.close();

    parce(firstName, lastName, date, salary);

    dataPrint(firstName, lastName, date, salary);
    std::cout << "==========================================" << std::endl;

    std::cout << "Salary expence: \t" << salaryExpense(salary) << std::endl;
    std::cout << "The highest salary: \t" << salaryMax(salary) << std::endl;

    return 0;
}
