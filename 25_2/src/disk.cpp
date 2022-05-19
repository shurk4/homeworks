#include <fstream>
#include <vector>

#include "..\include\gpu.h"



void save(std::vector<int>& in)
{
    std::ofstream file ("..\\save.txt");
    if(file.is_open())
    {
        for(int i = 0; i < in.size(); i++)
        {
            file << in[i] << " ";
        }
    }
    else
    {
        eror();
    }
    file.close();
}

void load(std::vector<int>& in)
{
    std::ifstream file ("..\\save.txt");
    if(file.is_open())
    {
        for(int i = 0; i < in.size(); i++)
        {
            file >> in[i];
        }
    }
    else
    {
        eror();
    }
    file.close();
}

