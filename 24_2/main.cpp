/*Реализуйте простую программу по вычислению ближайшего дня рождения.

В начале программы пользователь последовательно вводит данные о днях рождения своих друзей:
 вводит имя друга и саму дату рождения полностью, включая месяц и год, в формате год/месяц/день.
 Сигналом окончания ввода дней рождения является “end” введённое в качестве имени.

После этого программа вычисляет ближайший день рождения по отношению к текущему времени
 и выводит его на экран вместе с именем в удобном, локальном формате - месяц/день.
 Если день рождения уже был в этом году, данные о пользователе пропускаются.
 Если у кого-то из друзей день рождения сегодня, то в консоль выводится специальное сообщение об этом.

 Учтите, что таких сообщений может быть несколько, ведь сразу несколько людей могут иметь дни рождения в один день.

Советы и рекомендации

        Для подсчёта ближайшего дня используйте данные из структуры даты std::tm.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

#define AUTO

struct person{
    std::string name;
    std::tm date;
};

void print(std::vector<person>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i].name << " " << std::put_time(&vec[i].date, "%m/%d") << std::endl;
    }
}

void nearPrint(std::vector<person>& vec, std::vector<int>& temp, std::tm* today)
{
    std::cout << "--------------------------------------------" << std::endl;

    int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int month,
        day;

    if(vec[temp[0]].date.tm_mday < today->tm_mday)
    {
        month = vec[temp[0]].date.tm_mon - today->tm_mon - 1;
        day = monthDays[vec[temp[0]].date.tm_mon] - today->tm_mday + vec[temp[0]].date.tm_mday + 1;
    }
    else
    {
        month = vec[temp[0]].date.tm_mon - today->tm_mon;
        day = vec[temp[0]].date.tm_mday - today->tm_mday;
    }

    if(month == 0 && day == 0) {
        for(int i = 0; i < temp.size();i++)
        {
            std::cout << "Today is " << vec[temp[i]].name << "'s birthday" << std::endl;
        }
    }
    else
    {
        std::cout << "Nearest birthday" << (temp.size() < 2 ? "" : "s");
        std::cout << " is in " << month << " months " << day << " days" << std::endl;

        for (int i = 0; i < temp.size(); i++) {
            std::cout << vec[temp[i]].name << " " << std::put_time(&vec[temp[i]].date, "%m/%d") << std::endl;
        }
    }
}

void nearest(std::vector<person>& vec)
{
    std::vector<int> temp;
    std::time_t t = std::time(nullptr);
    std::tm* today = std::localtime(&t);

    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i].date.tm_mon > today->tm_mon || (vec[i].date.tm_mon == today->tm_mon && vec[i].date.tm_mday >= today->tm_mday))
        {
            if(temp.size() == 0 || (vec[i].date.tm_mon == vec[temp[0]].date.tm_mon && vec[i].date.tm_mday == vec[temp[0]].date.tm_mday))
            {
                    temp.push_back(i);
            }
            else if(vec[i].date.tm_mon < vec[temp[0]].date.tm_mon || (vec[i].date.tm_mon == vec[temp[0]].date.tm_mon && vec[i].date.tm_mday < vec[temp[0]].date.tm_mday))
            {
                temp.clear();
                temp.push_back(i);
            }
        }
    }
    nearPrint(vec, temp, today);
}

void infill(std::vector<person>& vec)
{
    srand(std::time(nullptr));
    vec.resize(10);
    for(int i = 0; i < vec.size(); i++)
    {
        std::string temp = "Name";
        std::stringstream stream;
        vec[i].name = temp + std::to_string(i);

        stream << rand()%(2000-1980+1) + 1970 << "/" <<
                    std::setw(2) << std::setfill('0') << rand()%12+1 << "/" <<
                    std::setw(2) << std::setfill('0') << rand()%30+1 << "\n";
        stream >> std::get_time(&vec[i].date, "%Y/%m/%d");
    }
}

int main() {
    std::string input;
    std::vector<person> birthdays;

#ifdef AUTO
    infill(birthdays);
    print(birthdays);
    nearest(birthdays);
#endif

    do{
        std::cout << "Enter the name:" << std::endl;
        std::cin >> input;
        if (input == "fill")
        {
            infill(birthdays);
        }
        else if(input != "end")
        {
            birthdays.resize(birthdays.size() + 1);
            birthdays[birthdays.size() - 1].name = input;
            std::cout << "Enter the date of birth in format YYYY/MM/DD:" << std::endl;
            std::cin >> std::get_time(&birthdays[birthdays.size() - 1].date, "%Y/%m/%d");
        }
        else
        {
            nearest(birthdays);
        }
    } while (input != "end");


    return 0;
}
