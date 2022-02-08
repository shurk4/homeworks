#include <iostream>

bool partCheck(int part) {
    if (part >= 0 && part <= 255) return true;
    else return false;
}

int partSumm(char num, int count){
    if(count == 1) return num - '0';
    else if(count == 2) return (num - '0') * 10;
    else return (num - '0') * 100;
}

int main() {
    std::string ip;
    bool check = true;
    int count = 1;
    int part = 0;

    std::cout << "Enter IP: ";
    std::getline(std::cin, ip);

    for (int i = ip.length() - 1; i >= 0; i--) {
        int point = 0;
        if (!check || point > 3 || ip.length() < 7 || ip.length() > 15 || ip[i] > '9' || (ip[i] < '0' && ip[i] != '.')
            || (count == 1 && ip[i] == '.') || (i == 0 && ip[i] == '.')
            || (ip[i] == '0' && count > 1 && ip[i - 1] < '1')) {
            check = false;
            break;
        } else if (ip[i] == '.'){
            check = partCheck(part);
            count = 1;
            part = 0;
        } else if (i == 0){
            part += partSumm(ip[i], count);
            check = partCheck(part);
        } else {
            part += partSumm(ip[i], count);
            count++;
        }
    }

    std::cout << (check ? "Yes" : "No") << "\n";
    return 0;
}
