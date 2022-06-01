#include <iostream>
#include <cassert>

int count = 0; // для автоматического присвоения имён

class Branch
{
    int deep;
    int quantity;
    std::string type;
    std::string elfName;
    Branch **branch = nullptr;

    class Branch* parent = nullptr;

    Branch* getTopBranch()
    {
        if (type == "Big")
        {
            return this;
        }

        if (parent->type == "Big")
        {
            return parent;
        }
    }

    int neighborsCount(std::string exclude)
    {
        int result = 0;
        if(elfName != "None" && elfName != exclude)
        {
            result++;
        }

        for(int i = 0; i < quantity; i++)
        {
            if(&branch[i] != nullptr)
            {
                result += branch[i]->neighborsCount(exclude);
            }
        }
        return result;
    }

public:
    Branch(class Branch *inparentPtr, int inDeep)
    {
        class Branch *ptr;
        parent = inparentPtr;
//        assert(inparentPtr != nullptr); // почему не работает ?
        if(inDeep == 3)
        {
            type = "Tree";
            quantity = std::rand() % 3 + 3;
        }
        if(inDeep == 2)
        {
            type = "Big";
            quantity = std::rand() % 2 + 2;
        }
        if(inDeep == 1)
        {
            type = "Middle";
            quantity = 0;
        }
        if(inDeep == 4)
        {
            type = "Forest";
            quantity = 5;
        }
        deep = inDeep - 1;
        branch = new Branch*[quantity];

        if(deep > 0)
        {
            for (int i = 0; i < quantity; i++) {
                branch[i] = new Branch(this, deep);
            }
        }
    }

    void print()
    {
        for(int i = 0; i < quantity; i++)
        {
            std::cout << branch[i]->type << " " << i << " name: " << branch[i]->elfName << std::endl;
            std::cout << std::endl;

            if(branch[i] != nullptr)
            {
                branch[i]->print();
            }
        }
    }

    void setAutoName()
    {
        for(int i = 0; i < quantity; i++)
        {
            if(branch[i] != nullptr)
            {
                if(parent != nullptr)
                {
                    count++;
                    branch[i]->elfName = "Elf" + std::to_string(count);
                }
                std::cout << std::endl;
                branch[i]->setAutoName();
            }
        }
    }

    void setName()
    {
        for(int i = 0; i < quantity; i++)
        {
            if(branch[i] != nullptr)
            {
                if(parent != nullptr)
                {
                    std::cout << "Enter the " << i << " elf name:";
                    std::cin >> branch[i]->elfName;
                }
                std::cout << std::endl;
                branch[i]->setName();
            }
        }
    }

    void find(std::string in)
    {
        for(int i = 0; i < quantity; i++)
        {
            if(branch[i] != nullptr)
            {
                if(branch[i]->elfName == in)
                {
                    std::cout << in << " has " << branch[i]->getTopBranch()->neighborsCount(in) << " neighbors" << std::endl;
                    return;
                }
                branch[i]->find(in);
            }
        }
    }

    void setDeep(int inDeep)
    {
        deep = inDeep;
    }

    void setType(std::string inType)
    {
        type = inType;
    }

    void setElfName(std::string inElfName)
    {
        elfName = inElfName;
    }

    int getDeep()
    {
        return deep;
    }

    std::string getElfName()
    {
        return elfName;
    }
};

int main()
{
    std::srand(time(nullptr));
    Branch *forest = new Branch(nullptr,4);
    std::string input;

    std::cout << "Enter the names of the elves" << std::endl;

    forest->setName();
//    forest->setAutoName(); // автоматическое именовение эльфов
    forest->print(); // вывод информации о эльфах

    std::cout << "Enter a name to search:" << std::endl;
    std::cin >> input;
    forest->find(input);

    return 0;
}