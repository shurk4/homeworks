#include <iostream>
#include <string>
#include <vector>

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
    std::vector<Talent*> talents;

public:
    Dog(std::string _name = "Steve") : name(_name)
    {
    }

    void addTalents(Talent *talent)
    {
        talents.push_back(talent);
    }

    void showTalens()
    {
        std::cout << "This is " << name << " and it has some talents:" << std::endl;
        for(int i = 0; i < talents.size(); i++)
        {
            std::cout << "It can \"" << talents[i]->getTalent() << "\"" << std::endl;
        }
    }

    ~Dog()
    {
        for(int i = 0; i < talents.size(); i++)
        {
            delete talents[i];
        }
    }
};

int main() {
    Dog dog("Steve");

    dog.addTalents(new Dancing);
    dog.addTalents(new Swimming);

    dog.showTalens();

    return 0;
}
