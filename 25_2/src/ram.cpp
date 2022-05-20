#include <vector>

std::vector<int> buf(8);

void write(int i, int a)
{
    buf[i] = a;
}

int read(int i)
{
    return buf[i];
}