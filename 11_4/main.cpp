#include <iostream>

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
std::string separate(std::string num, bool partInt){
    std::string integer, fractional;
    bool point = false;
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '.') {
            point = true;
        } else if (point) {
            fractional += num[i];
        } else {
            integer += num[i];
        }
    }
    return partInt ? integer : fractional;
}
// =================================================================
std::string zeros(int a) {
    std::string result;
    for(int i = 0; i < a; i++){
        result += '0';
    }
    return result;
}
// =================================================================
std::string comparing(std::string num1, std::string num2) {
    std::string result;
    for(int i = 0; i < num1.length(); i++) {
        if (num1[i] < num2[i]) {
            result = "Less";
            break;
        } else if (num2[i] < num1[i]) {
            result = "More";
            break;
        } else {
            result = "Equal";
        }
    }
    return result;
}
// =================================================================
int main() {
    std::string num1, num2;
    std::string int1, int2, fract1, fract2, result;
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

    if(num1[0] == '-' && num2[0] != '-') {
        result = "Less";
    } else if (num2[0] == '-' && num1[0] != '-') {
        result = "More";
    } else {
        int1 = separate(num1, true);
        fract1 = separate(num1, false);
        int2 = separate(num2, true);
        fract2 = separate(num2, false);

        if(int1.length() < int2.length()) {
            int1 = zeros(int2.length() - int1.length()) + int1;
        } else if(int2.length() < int1.length()) {
            int2 = zeros(int1.length() - int2.length()) + int2;
        }
        if(fract1.length() < fract2.length()) {
            fract1 += zeros(fract2.length() - fract1.length());
        } else if(fract2.length() < fract1.length()) {
            fract2 += zeros(fract1.length() - fract2.length());
        }

        result = comparing(int1, int2);
        if(result == "Equal" && fract1.length() != 0) result = comparing(fract1, fract2);
    }

    std::cout << "Result = " << result << "\n";

    return 0;
}