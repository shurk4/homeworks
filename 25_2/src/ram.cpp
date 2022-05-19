#include <vector>

std::vector<int> buf(8);

void write(std::vector<int>& in)
{
    for(int i = 0; i < in.size(); i++)
    {
        buf[i] = in[i];
    }
}

void read(std::vector<int>& in)
{
    for(int i = 0; i < in.size(); i++)
    {
        in[i] = buf[i];
    }
}