#include <vector>

int compute (std::vector<int>& in)
{
    int result = 0;
    for(int i = 0; i < in.size(); i++)
    {
        result += in[i];
    }
    return result;
}
