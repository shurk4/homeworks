#include <vector>
#include <iostream>
#include <thread>

void hello()
{
    std::cout << "Loading";
    for(int i = 0; i < 5; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds (360));
        std::cout << ".";
    }
    std:: cout << "=)" << std::endl;
}

void input()
{
    std::cout << "Enter the command:";
}

void compure_print(int a)
{
    std::cout << "Result: " << a << std::endl;
}

void eror()
{
    std::cout << "Could not open the file!" << std::endl;
}

void display(std::vector<int>& in)
{
    for(int i = 0; i < in.size();i++)
    {
        std::cout << in[i] << " ";
    }
    std::cout << std::endl;
}

void bye()
{
    std::cout << "Shutting down";
    for(int i = 0; i < 5; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds (360));
        std::cout << ".";
    }
    std:: cout << std::endl;
}