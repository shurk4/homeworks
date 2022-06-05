/*Реализуйте симуляцию работы компании.
 * В компании существует вертикальное управление с иерархией.
 * Есть основные рабочие, подчинённые, разбитые на команды.
 * У каждой команды есть менеджер среднего звена.
 * Всей компанией руководит глава компании.
 * У всех сотрудников, включая руководителя, есть имена.

Глава компании выполняет стратегическое управление.
 Он определяет основной вектор движения — задачи верхнего уровня.
 Менеджеры среднего звена разбивают эти задачи на подзадачи и раздают их своим подчинённым.
 Подчинённые выполняют работу.

Реализация данной логики должна проходить упрощённым образом.
 Указания главы компании поступают из стандартного ввода и являются не более чем целочисленными идентификаторами.
Данные идентификаторы служат зерном для генератора случайных чисел.
 Каждый из менеджеров, принимая себе эту целочисленную команду,
 добавляет к ней свой порядковый номер и вызывает с результирующей суммой функцию std::srand().
На основе этой суммы вычисляется общее количество задач,
 которое требуется выполнить данной командой, — от 1 до количества работников в группе.
 Всего есть три типа задач для работников: A, B и C. Они тоже выбираются случайно и распределяются между незанятыми рабочими.

При старте программы пользователь указывает в стандартном вводе количество команд и количество работников в каждой из команд.
Далее пользователь вводит целые числа, которые соответствуют указаниям руководителя компании.
 Когда какой-то работник или менеджер получил указания или задачу, об этом сообщается в стандартный вывод,
 включая имя работающего сотрудника. Программа завершается, когда все работники заняты какими-то задачами.

Советы и рекомендации
        Пользуйтесь всем изученным в модуле, включая иерархии классов для представления сотрудников и указатель this, если потребуется.
Чтобы проинициализировать генератор случайных чисел, используйте std::srand(hash);
 где hash — некое случайное и уникальное значение, например, ID вашей группы и команды.
 Для получения количества задач используйте полученный генератор случайных чисел так: int tasksCount = rand() % (team->workers.size() + 1);*/

#include <iostream>

enum tasks
{
    A,
    B,
    C
};

class Unit
{
    tasks task;

public:
    int number;
    std::string name;

    void setTask()
    {
        int rand = std::rand() %3 + 1;
        if(rand == 1)
        {
            task = A;
        }
        if(rand == 2)
        {
            task = B;
        }
        if(rand == 3)
        {
            task = C;
        }
    }
    char getTask()
    {
        if(task == A)
        {
            return 'A';
        }
        if(task == B)
        {
            return 'B';
        }
        if(task == C)
        {
            return 'C';
        }
        return ' ';
    }

};

class Dept:public Unit
{
    Unit **workers = nullptr;
    int workersBusy = 0;

public:

    Dept(int num)
    {
        std::cout << "Enter the number of workers in department " << num + 1 << ":" << std::endl;
        std::cin >> number;

        workers = new Unit*[number];

        for(int i = 0; i < number; i++)
        {
            workers[i] = new Unit;
            workers[i]->name = "Worker" + std::to_string(i + 1);
        }
    }

    int getFreeWorkers()
    {
        return number - workersBusy;
    }

    void setTask(int InTaskNum, int inDeptNum)
    {
        if(getFreeWorkers() > 0)
        {
            std::srand(InTaskNum + inDeptNum + 1);

            int taskNum = workersBusy + (std::rand() % (number - workersBusy) + 1);

            for (int i = workersBusy; i < taskNum; i++) {
                workers[i]->setTask();
                workersBusy++;
                std::cout << "Worker " << workers[i]->name << " from department " << inDeptNum + 1
                          << " received from manager " << name << " the task " << workers[i]->getTask() << std::endl;
            }
        }
    }

    void info(int num)
    {
        std::cout << std::endl;
        std::cout << "\tDept " << num + 1 << " information:" << std::endl;
        std::cout << "\tManager name:\t" << name << std::endl;
        std::cout << "\tWorkers number:\t" << number << std::endl;
        std::cout << "\tBusy workers:\t" << workersBusy << std::endl;
        std::cout << "\tWorkers information:" << std::endl;

        for(int i = 0; i < number; i++)
        {
            std::cout << "\tWorker " << i + 1 << " name:\t" << workers[i]->name << std::endl;
            std::cout << "\tTask:\t" << workers[i]->getTask() << std::endl;
        }
    }
};

class Boss:public Unit
{
    Dept **depts = nullptr;

public:

    Boss()
    {
        name = "Boss";
        std::cout << "Enter the number of departments:" << std::endl;
        std::cin >> number;

        depts = new Dept*[number];

        for(int i = 0; i < number; i++)
        {
            depts[i] = new Dept(i);
            depts[i]->name = "Manager" + std::to_string(i + 1);
        }
    }

    bool allBusy()
    {
        for(int i = 0; i < number; i++)
        {
            if(depts[i]->getFreeWorkers() != 0)
            {
                return false;
            }
        }
        return true;
    }

    void setTask()
    {
        int in;
        std::cout << "Enter the task number:" << std::endl;
        std::cin >> in;

        for(int i = 0; i < number; i++)
        {
            depts[i]->setTask(in, i);
        }
    }

    void info()
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "- Organization information: -" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Boss name:\t" << name << std::endl;
        std::cout << "Number of departaments:\t" << number << std::endl;

        for(int i = 0; i < number; i++)
        {
            depts[i]->info(i);
        }
        std::cout << "-----------------------------" << std::endl;
    }
};

int main() {
    Boss *company = new Boss;

    do
    {
        company->setTask();
        company->info();
        if(company->allBusy())
        {
            std::cout << "All workers is busy!" << std::endl;
        }
    }while(!company->allBusy());

    return 0;
}
