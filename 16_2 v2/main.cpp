#include <iostream>
#include <string>

void input (std::string &x){
    do{
        std::cin >> x;
        if (x[0] == '-') std::cout << "Wrong input! Try again:\n";
    } while (x[0] == '-');
}

int main() {
    std::string a,
                b;
    double c;

    std::cout << "Enter the integer part of the number:\n";
    std::cin >> a;
    std::cout << "Enter the fractional part of the number:\n";
    input(b);

    a = a + '.' + b;

    std::cout << std::stod(a);

    return 0;
}
