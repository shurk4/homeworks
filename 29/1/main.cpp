#include <iostream>
#include <string>

class Talent
{
public:
    virtual std::string getTalent() = 0;
};

class Swimming : virtual public Talent
{
public:
    virtual std::string getTalent()
    {
        return "Swim";
    }
};

class Dancing : virtual public Talent
{
public:
    virtual std::string getTalent()
    {
        return "Dance";
    }
};

class Counting : virtual public Talent
{
public:
    virtual std::string getTalent()
    {
        return "Count";
    }
};

class Dog
{
    std::string name = "Steve";
    Talent *talent[2];

public:
    Dog(std::string _name = "Steve") : name(_name)
    {
        talent[0] = new Dancing;
        talent[1] = new Swimming;
    }

    void showTalens()
    {
        std::cout << "This is " << name << " and it has some talents:" << std::endl;
        for(int i = 0; i < 2; i++)
        {
            std::cout << "It can \"" << talent[i]->getTalent() << "\"" << std::endl;
        }
    }
};

int main() {
    Dog dog("Steve");

    dog.showTalens();

    return 0;
}
