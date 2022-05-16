/*Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.

Пользователь взаимодействует с программой с помощью команд:

Команда begin начинает отслеживание новой задачи.
 После ввода этой команды пользователь должен ввести название задачи,
 над которой он планирует сейчас работать. Если уже была начата какая-то другая задача,
 предыдущая должна быть автоматически завершена и начата новая.

Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего не делает.

Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них потрачено.
 Также выводится название текущей выполняемой задачи, если таковая имеется.

Команда exit выходит из программы.

Советы и рекомендации
        Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, которое было затрачено.*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

#define TIME(a) std::put_time(a, "%Y %B %d %H:%M:%S")

#define STOP(a) \
std::cout << "Task \"" << log[inProgress].name << "\" is stopped " << TIME(a) << std::endl; \
log[inProgress].stop = t;

struct task{
    std::string name;
    std::time_t start;
    std::time_t stop;
};

void taskTime(std::time_t& start, std::time_t& stop){
    int time = std::difftime(start, stop);
    int h = time / 3600;
    int m = (time % 3600) / 60;
    int s = (time % 3600) % 60;
    std::cout << "Task time:" << h << " hrs " << m << " min " << s << " sec" << std::endl;
    std::cout << std::endl;
}

void logprint(std::vector<task>& vec){
    std::cout << "-----------------------" << std::endl;
    std::cout << "Task log:" << std::endl;
    std::cout << "-----------------------" << std::endl;

    for (int i = 0; i < vec.size(); i++) {
        if(vec[i].stop >= vec[i].start)
        {
            std::cout << "Name:\t" << vec[i].name << std::endl;
            std::tm *start = std::localtime(&vec[i].start);
            std::cout << "Start:\t" << TIME(start) << std::endl;
            std::tm *stop = std::localtime(&vec[i].stop);
            std::cout << "Stop:\t" << TIME(stop) << std::endl;
            taskTime(vec[i].stop, vec[i].start);
        }
    }
    std::cout << "-----------------------" << std::endl;
}

int main() {
    std::vector<task> log;
    std::string input;
    int inProgress = -1;

    do {
        std::cout << "Enter the command: " << std::endl;
        std::cin >> input;

        if (input == "begin") {
            std::time_t t = std::time(nullptr);
            std::tm* start = std::localtime(&t);
            if(inProgress != -1){
                STOP(start)
            }
            std::cout << "New task is started " << TIME(start) << std::endl;
            log.resize(log.size() + 1);
            inProgress = log.size() - 1;
            log[inProgress].start = t;
            std::cout << "Enter the name of the task:" << std::endl;
            std::cin >> log[inProgress].name;
        }
        else if (input == "status")
        {
            logprint(log);
        }
        else if ((input == "end" || input == "exit") && inProgress != -1)
        {
            std::time_t t = std::time(nullptr);
            std::tm* stop = std::localtime(&t);
            STOP(stop);
            inProgress = -1;
        }
    } while (input != "exit");

    return 0;
}
