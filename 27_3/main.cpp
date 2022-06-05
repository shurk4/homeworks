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
