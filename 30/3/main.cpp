#include <iostream>
#include <cpr/cpr.h>
#include <vector>
#include <string>
#include <map>

bool isRequest(std::string &in)
{
    return in == "get" || in == "post";
}

void get(std::map<std::string, std::string> &map)
{
    std::string request = "?";

    for(std::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); ++it)
    {
        request += it->first + "=" + it->second + "&";
    }

    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get" + request));
    std::cout << r.text << std::endl;
}

void post(std::map<std::string, std::string> &map)
{
    std::vector<cpr::Pair> pairs;

    for(std::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); ++it)
    {
        cpr::Pair pair(it->first, it->second);
        pairs.push_back(pair);
    }

    cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                              cpr::Payload(pairs.begin(), pairs.end()));

    std::cout << r.text << std::endl;
}

void input(std::map<std::string, std::string> &map)
{
    std::string parameter;
    std::string value;
    do
    {
        std::cout << "Enter a parameter or get/post to run the request:" << std::endl;
        std::cin >> parameter;
        if(isRequest(parameter))
        {
            if(parameter == "get")
            {
                get(map);
            }
            if(parameter == "post")
            {
                post(map);
            }
        }
        else
        {
            std::cout << "Enter the value" << std::endl;
            std::cin >> value;

            map.emplace(parameter, value);
        }
    } while (!isRequest(parameter));
}

int main() {
    std::map<std::string, std::string> map;

    input(map);

    return 0;
}
