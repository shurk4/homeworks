#include <iostream>
#include <cpr/cpr.h>

std::string titleFind(std::string &_in)
{
    std::string findKey1 = "<h1>";
    std::string findKey2 = "</h1>";
    std::string result = "";

    if(_in.find(findKey1) == std::string::npos || _in.find(findKey2) == std::string::npos)
    {
        std::cout << "Unable to find the title!" << std::endl;
    }
    else
    {
        for(int i = _in.find(findKey1) + findKey1.length(); i < _in.find(findKey2); i++)
        {
            result += _in[i];
        }
        return result;
    }
}

int main() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"));

    std::cout << "Header: \"" << titleFind(r.text) << "\"" << std::endl;

    return 0;
}
