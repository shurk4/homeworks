#include <iostream>
#include <thread>

#include "ram.h"

void hello()
{
    std::cout << "Loading";
    for(int i = 0; i < 5; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds (360));
        std::cout << ".";
    }
    std:: cout << "=)" << std::endl;
}

void in()
{
    std::cout << "Enter the command:";
}

void compute_print(int a)
{
    std::cout << "Result: " << a << std::endl;
}

void eror()
{
    std::cout << "Could not open the file!" << std::endl;
}

void display()
{
    for(int i = 0; i < 8;i++)
    {
        std::cout << read(i) << " ";
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