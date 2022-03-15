#include <iostream>
#include <cstdio>

bool itAction(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int main() {
    std::string input, first, second;
    char action = ' ';
    double result;
    std::cout << "Welcome to the calculator!" << std::endl;
    std::cin >> input;

    for(int i = 0; i < input.size(); i++) {
        if(itAction(input[i]) && i > 0 && action == ' ') {
            action = input[i];
        } else if(action == ' ') {
            first += input[i];
        } else {
            second += input[i];
        }
    }

    if(action == '+'){
        result = std::stod(first) + std::stod(second);
    } else if(action == '-'){
        result = std::stod(first) - std::stod(second);
    } else if(action == '/'){
        result = std::stod(first) / std::stod(second);
    } else if(action == '*'){
        result = std::stod(first) * std::stod(second);
    }

    std::cout << first << " " << action << " " << second << " = " << result << std::endl;

    return 0;
}
