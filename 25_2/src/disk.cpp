#include <fstream>

#include "ram.h"
#include "gpu.h"



void save()
{
    std::ofstream file ("..\\save.txt");
    if(file.is_open())
    {
        for(int i = 0; i < 8; i++)
        {
            file << read(i) << " ";
        }
    }
    else
    {
        eror();
    }
    file.close();
}

void load()
{
    std::ifstream file ("..\\save.txt");
    int temp;
    if(file.is_open())
    {
        for(int i = 0; i < 8; i++)
        {
            file >> temp;
            write(i, temp);
        }
    }
    else
    {
        eror();
    }
    file.close();
}

