#include <iostream>

#include "ram.h"

void command(std::string& com)
{
    std::cin >> com;
}

void input()
{
    int temp;
    std::cout << "Input 8 numbers" << std::endl;
    for(int i = 0; i < 8; i++)
    {
        std::cout << "num " << i + 1 << ": ";
        std::cin >> temp;
        write(i, temp);
    }
}