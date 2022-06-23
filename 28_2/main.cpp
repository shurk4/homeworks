/*С помощью многопоточности реализуйте простую модель железнодорожного вокзала.

С трёх точек отправления в разное время отбывают три разных поезда с условными обозначениями A, B, C.
 Все они идут на один и тот же вокзал и могут дойти до него в разное время.

На этом целевом вокзале единовременно может находиться только один поезд.
 Остальные поезда должны ждать, пока уже занятое место освободится.

В начале программы пользователь последовательно вводит для каждого поезда время в пути до вокзала (в секундах).
 После этого поезда начинают своё движение за заданное количество времени.
 Как только поезд прибыл на вокзал, он ожидает от пользователя команды depart,
 которая сигнализирует о его отбытии с вокзала.

По всем событиям (прибытие на вокзал, ожидание свободного места, отбытие с вокзала)
 вместе с условным обозначением поезда выводятся сообщения в консоль.

Программа завершается, когда на вокзале побывают все три поезда.*/

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex station;

class Train
{
    char label;
    int travelTime;

public:

    Train(int &num):label('A' + num)
    {
        std::cout << "Enter the travel time of the train " << label << ": " << std::endl;
        std::cin >> travelTime;
    }

    char getLabel()
    {
        return label;
    }

    int getTravelTime()
    {
        return travelTime;
    }
};

void move(Train *train)
{
    std::string command;
    std::this_thread::sleep_for(std::chrono::seconds(train->getTravelTime()));
    station.lock();
    std::cout << "The train " << train->getLabel() << " has arrived at the station!" <<std::endl;
    do
    {
        std::cout << "Enter the depart command: ";
        std::cin >> command;
        if(command != "depart")
        {
            std::cout << "Wrong input! Try again." << std::endl;
        }
    } while (command != "depart");
    station.unlock();
}

int main() {
    Train **trains = new Train*[3];
    std::vector<std::thread> threads;

    for(int i = 0; i < 3; i++)
    {
        trains[i] = new Train(i);
    }

    for(int i = 0; i < 3; i++)
    {
        threads.push_back(std::thread (move, std::cref(trains[i])));
    }

    for(int i = 0; i < 3; i++)
    {
        if(threads[i].joinable())
        {
            threads[i].join();
        }
    }

    return 0;
}
