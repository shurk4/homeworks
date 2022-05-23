/*
    Реализуйте программу простой симуляции работы мобильного телефона.

По мобильному телефону можно звонить и отправлять СМС.
 Также мобильный телефон содержит адресную книгу.
 Телефон и отдельные записи адресной книги должны быть реализованы с помощью классов.
 Все номера телефонов задаются в формате +7 <10 цифр>.

Пользователь взаимодействует с программой с помощью команд:

Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта.
 Оба эти параметра команда получает от пользователя через стандартный ввод.

Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить.
 Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.

Команда sms. Запрашивает у пользователя номер телефона (или имя контакта), на который требуется послать сообщение.
 Само сообщение также вводится через стандартный ввод.

Команда exit — выход из программы.

Советы и рекомендации
        Сам по себе тип номера телефона вы тоже можете реализовать с помощью отдельного класса.*/

#include <iostream>
#include <vector>
#include <fstream>

void fileEror()
{
    std::cout << "Could not open the file!" << std::endl;
}

class Contact
{
    std::string name;
    std::string phone;

    friend class Phone;
};

class Phone
{
    std::vector<Contact> phonebook;

public:
    std::string input;

    void load()
    {
        std::ifstream file("..\\phonebook.txt");
        if(file.is_open())
        {
            int size;
            file >> size;
            phonebook.resize(size);
            for (int i = 0; i < phonebook.size(); i++) {
                file >> phonebook[i].name >> phonebook[i].phone;
            }
            file.close();
            std::cout << "The phonebook is loaded" << std::endl;
        }
        else fileEror();
    }

    void add()
    {
        phonebook.resize(phonebook.size() + 1);

        std::cout << "Enter the name:" << std::endl;
        std::cin >> phonebook[phonebook.size() - 1].name;

        std::cout << "Enter the phone number:" << std::endl;
        std::cout << "+7 ";
        std::cin >> input;
        phonebook[phonebook.size() - 1].phone = "+7" + input;

        std::cout << "Added:" << phonebook[phonebook.size() - 1].name << " " << phonebook[phonebook.size() - 1].phone << std::endl;
    }

    void dialog()
    {
        std::cout << "Enter the name or the phone number:" << std::endl;
        std::cin >> input;
    }

    int find()
    {
        if(input[0] == '+' && input[1] == '7')
        {
            for(int i = 0; i < phonebook.size(); i++)
            {
                if(phonebook[i].phone == input)
                {
                    return i;
                }
            }
        }
        else
        {
            for(int i = 0; i < phonebook.size(); i++)
            {
                if(phonebook[i].name == input)
                {
                    return i;
                }
            }
        }

        std::cout << "Not found!" << std::endl;
        return -1;
    }

    void call()
    {
        dialog();

        if(find() != -1)
        {
            std::cout << "CALL " << phonebook[find()].phone << std::endl;
        }
    }

    void sms()
    {
        std::string massage;
        dialog();

        if(find() != -1)
        {
            std::cout << "Enter a message for the number " << phonebook[find()].phone << std::endl;
            std::cin.ignore(255, '\n');
            std::getline(std::cin, massage);
            std::cout << "The message:\n" << massage << "\n has been sent" << std::endl;
        }
    }

    void list()
    {
        std::cout << "------------ LIST --------------" << std::endl;
        for(int i = 0; i < phonebook.size(); i++)
        {
            std::cout << phonebook[i].name << " " << phonebook[i].phone << std::endl;
        }
        std::cout << "--------------------------------" << std::endl;
    }

    void save()
    {
        std::ofstream file("..\\phonebook.txt");

        if(file.is_open())
        {
            file << phonebook.size() << " ";
            for (int i = 0; i < phonebook.size(); i++) {
                file << phonebook[i].name << " " << phonebook[i].phone << std::endl;
            }
            file.close();
            std::cout << "The phonebook has been saved" << std::endl;
        }
        else fileEror();
    }
};

int main() {
    Phone phone;

    do
    {
        std::cout << "Enter the command:" << std::endl;
        std::cin >> phone.input;

        if(phone.input == "load")
        {
            phone.load();
        }

        if(phone.input == "add")
        {
            phone.add();
        }

        if(phone.input == "call")
        {
            phone.call();
        }

        if(phone.input == "sms")
        {
            phone.sms();
        }

        if(phone.input == "list")
        {
            phone.list();
        }

        if(phone.input == "save")
        {
            phone.save();
        }

    }while(phone.input != "exit");

    return 0;
}
