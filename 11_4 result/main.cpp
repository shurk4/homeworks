#include <iostream>
#include <cmath>

bool check(std::string number) {
    bool check(true);
    int point = 0;
    int digit = 0;
    for(int i = 0; i < number.length(); i++) {
        if (point > 1 || (i == 0 && number[i] != '.' && number[i] != '-'
                          && (number[i] < '0' || number[i] > '9'))) {
            check = false;
            break;
        } else if (i != 0 && ((number[i] < '0' || number[i] > '9') && number[i] != '.')) {
            check = false;
            break;
        } else if (number[i] == '.') {
            point++;
        } else if (number[i] >= '0' && number[i] <= '9') {
            digit++;
        }
    }
    if (digit < 1) check = false;

    return check;
}
// =================================================================
int partSumm(char num, int count){
    return (num - '0') * (int)pow(10, count);
}
// =================================================================
double part(std::string part) {
    double result = 0;
    int count = 0;
    for (int i = part.length() - 1; i >= 0; i--) {
        if (part[i] == '.') {
            result /= partSumm('1', count);
            count = 0;
        } else if (part[i]  == '-'){
            result = -result;
        } else {
            result += partSumm(part[i], count);
            count++;
        }
    }
    return result;
}
// =================================================================
int main() {
    std::string num1, num2;

    do {
        std::cout << "Enter first number: \n";
        std::cin >> num1;
        if(!check(num1)) std::cout << "Wrong input!\n";
    } while (!check(num1));

    do {
        std::cout << "Enter second number: \n";
        std::cin >> num2;
        if(!check(num2)) std::cout << "Wrong input!\n";
    } while (!check(num2));

    if(part(num1) == part(num2)) std::cout << "Equal\n";
    else if(part(num1) > part(num2)) std::cout << "More\n";
    else std::cout << "Less\n";


    std::cout << part(num1) << "   " << part(num2) << "\n";

    return 0;
}
