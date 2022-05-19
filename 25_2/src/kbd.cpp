#include <vector>
#include <iostream>

void command(std::string& com)
{
    std::cin >> com;
}

void input(std::vector<int>& in)
{
    std::cout << "Input 8 numbers" << std::endl;
    for(int i = 0; i < in.size(); i++)
    {
        std::cout << "num " << i + 1 << ": ";
        std::cin >> in[i];
    }
}