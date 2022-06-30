#include <iostream>
#include <cpr/cpr.h>

void requests(std::string &in, cpr::Response &r)
{
    if(in == "get")
    {
        r = cpr::Get(cpr::Url("http://httpbin.org/get"));
        std::cout << r.text << std::endl << std::endl;
    }

    if(in == "post")
    {
        r = cpr::Post(cpr::Url("http://httpbin.org/post"));
        std::cout << r.text << std::endl << std::endl;
    }

    if(in == "put")
    {
        r = cpr::Put(cpr::Url("http://httpbin.org/put"));
        std::cout << r.text << std::endl << std::endl;
    }

    if(in == "delete")
    {
        r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        std::cout << r.text << std::endl << std::endl;
    }

    if(in == "patch")
    {
        r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
        std::cout << r.text << std::endl << std::endl;
    }
}

bool inputCheck(std::string &in)
{
    return (in == "get" || in == "post" || in == "put" || in == "delete" || in == "patch");
}

int main() {
    std::string input;
    cpr::Response response;

    do
    {
        std::cout << "Enter the command:" << std::endl;
        do
        {
            std::cin >> input;
            if (!inputCheck(input))
            {
                std::cout << "Wrong command! Try again:" << std::endl;
            }
        } while (!inputCheck(input));

        requests(input, response);

    } while (input != "exit");


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
