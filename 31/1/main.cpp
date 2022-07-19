/*Что нужно сделать:
Реализуйте умный указатель shared_ptr_toy с распределённым доступом и механикой подсчёта ссылок для класса Toy,
 реализованного в задании. Указатель должен иметь все стандартные методы класса
 и быть функциональной заменой использованию shared_ptr<Toy>.
Реализуйте свободную функцию make_shared_toy, которая принимает набор аргументов
 и конструирует игрушку или от названия, или при помощи копии другой игрушки.

Рекомендации
        Не забудьте в деструкторе умного указателя уменьшить число ссылок на единицу,
        а когда на счётчике появится значение ноль, удалить объект.
Можно использовать перегрузки под разные типы, благо их ограниченное количество.

Чек-лист для проверки задачи
Класс называется shared_ptr_toy.
Реализованы конструктор, конструктор копий, оператор присваивания копированием, деструктор и функция make_shared.

Что оценивается
Соответствие разработанного типа указателя стандартному типу shared_ptr при использовании с классом Toy.
Корректность логики работы функции создания экземпляра класса.*/

#include <iostream>
#include <string>

class Toy
{
    std::string name;

public:
    Toy() : name("SomeToy") {}
    Toy(std::string _name) : name(_name) {}

    std::string getName()
    {
        return name;
    }
};


class shared_ptr_toy
{
public:
    Toy* ptr = nullptr;
    int* counter = nullptr;

    shared_ptr_toy()
    {
    }

    shared_ptr_toy(Toy* _ptr) : ptr(_ptr), counter(new int)
    {
        *counter = 1;
        std::cout << "Created new pointer " << ptr->getName() << " with adress " << ptr << std::endl;
    }

    shared_ptr_toy(const shared_ptr_toy& other)
    {
        counter = other.counter;
        (*counter)++;
        ptr = other.ptr;
    }

    shared_ptr_toy& operator = (const shared_ptr_toy& other)
    {
        if (ptr != nullptr)
        {
            if(ptr != other.ptr)
            {
                (*counter)--;
                counter = other.counter;
                (*counter)++;
                ptr = other.ptr;
            }
        }
        else
        {
            counter = other.counter;
            (*counter)++;
            ptr = other.ptr;
        }
        return *this;
    }

    ~shared_ptr_toy()
    {
        std::cout << "Deleted pointer " << ptr->getName() << " #" << *counter << " with adress " << ptr << std::endl;
        (*counter)--;

        if(*counter == 0)
        {
            std::cout << "Pointer  " << ptr->getName() << " fully deleted" << std::endl;
            delete counter;
            delete ptr;
        }
    }
};

shared_ptr_toy make_shared_toy (std::string name)
{
    shared_ptr_toy ptr (new Toy(name));
    return ptr;
}

shared_ptr_toy make_shared_toy (shared_ptr_toy &_ptr)
{
    shared_ptr_toy ptr (_ptr);
    return ptr;
}

int main() {

    Toy* ptr1 = new Toy;
    Toy* ptr2 = new Toy("Bone");

    shared_ptr_toy toy1(ptr1);
    shared_ptr_toy toy2(ptr2);

    shared_ptr_toy toy3 (toy2);

    shared_ptr_toy toy4;
    toy4 = toy1;
    toy1 = toy2;

    shared_ptr_toy toy5 = make_shared_toy("Ball");

    shared_ptr_toy toy6 = make_shared_toy(toy5);



    return 0;
}
