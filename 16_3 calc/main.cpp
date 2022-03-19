#include <iostream>
#include <sstream>

bool itAction(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int main() {
    std::string input;
    char action = ' ';
    double result, first, second;
    std::cout << "Welcome to the calculator!" << std::endl;
    std::cin >> input;

    std::stringstream inStream;
    inStream << input;
    inStream >> first >> action >> second;

    std::cout << first << " " << action << " " << second << std::endl;

    if(action == '+'){
        result = first + second;
    } else if(action == '-'){
        result = first - second;
    } else if(action == '/'){
        result = first / second;
    } else if(action == '*'){
        result = first * second;
    }

    std::cout << first << " " << action << " " << second << " = " << result << std::endl;
    return 0;
}
