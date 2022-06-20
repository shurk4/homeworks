/*Реализуйте симуляцию состязаний по заплыву на 100 метров.

Всего шесть дорожек и шесть пловцов.
 Имена пловцов указываются вначале из стандартного ввода.
 Каждый из них плывёт с разной скоростью,
 которая также задаётся пользователем при старте, через стандартный ввод в метрах в секунду.

Каждую секунду в стандартный вывод выдаётся информация о том, сколько проплыл тот или иной пловец.

Как только все пловцы коснулись 100-метровой отметки,
 заплыв заканчивается и выводится таблица с итоговыми результатами,
 отсортированная по возрастанию итогового времени заплыва.

Советы и рекомендации
        Используйте нити для реализации движения каждого пловца в отдельности.*/


#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <iomanip>

std::vector<int> result;
std::mutex resultLock;



class Swimmer
{
    std::string name;
    int number;
    int speed;
    int currentDistance = 0;
    double time = 0;

public:

    std::mutex data;

    Swimmer(int &num):number(num)
    {
        std::cout << "Enter the swimmer name:" << std::endl;
        std::cin >> name;
        std::cout << "Enter " << name << " speed:" << std::endl;
        std::cin >> speed;
    }

    Swimmer(int &num, std::string mode):number(num)
    {
        name = "Name" + std::to_string(num + 1);
        speed = std::rand() % 15 + 10;
    }

    std::string getName()
    {
        return name;
    }

    int getNumber()
    {
        return number;
    }

    int getSpeed()
    {
        return speed;
    }

    int getDistance()
    {
        return currentDistance;
    }

    double getTime()
    {
        return time;
    }

    void swimm()
    {
        int step = 1000;
        do
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(step));
            if(currentDistance < 100)
            {
                currentDistance += speed;
            }
            if(currentDistance >= 100)
            {
                currentDistance = 100;
                resultLock.lock();
                result.push_back(number);
                resultLock.unlock();
            }

            time += step;

            if(currentDistance + speed > 100)
            {
                step = (1000 / speed) * (100 - currentDistance);
            }
        } while (currentDistance < 100);
    }
};



void swimm(Swimmer *swimmer)
{
    swimmer->swimm();
}

void subtotal(Swimmer **swimmers, int size = 6)
{
    while (result.size() < size)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "--------------------------" << std::endl;
        std::cout << "Name\t|\tDistance" << std::endl;
        std::cout << "--------------------------" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << swimmers[i]->getName() << "\t|\t";
            if(swimmers[i]->getDistance() < 100)
            {
                std::cout << swimmers[i]->getDistance();
            }
            else
            {
                std::cout << "finished";
            }
            std::cout << std::endl;
        }
    }
}

void leaderBoardPrint(Swimmer **swimmers, int size = 6)
{
    std::cout << "==========================" << std::endl;
    std::cout << "---=== Leader Board ===---" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Name\t|\tTime" << std::endl;
    std::cout << "--------------------------" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cout << swimmers[result[i]]->getName() << "\t|\t" << std::fixed << std::setprecision(2)
                  << swimmers[result[i]]->getTime() / 1000 << std::endl;
    }
}

int main() {
    std::srand(std::time(nullptr));
    int size = 6;
    Swimmer **pool = new Swimmer*[size];
    std::vector<std::thread> thr;

    for(int i = 0; i < size; i++)
    {
        pool[i] = new Swimmer(i); // Для автоматического заполнения добавить любую строку вторым параметром
        std::cout << "Swimmer " << pool[i]->getName() << " with speed " << pool[i]->getSpeed()
                  << " on line " << i << std::endl;
    }

    std::cout << "--------------------------" << std::endl;
    std:: cout << "--------- START ---------" << std::endl;

    for(int i = 0; i < size; i++)
    {
        thr.push_back(std::thread(swimm, pool[i]));
    }

    subtotal(pool, size);

    for(int i = 0; i < size; i++)
    {
        if(thr[i].joinable())
        {
            thr[i].join();
        }
    }

    leaderBoardPrint(pool, size);

    return 0;
}
