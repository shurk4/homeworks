#include <iostream>
bool partCheck (std::string part, std::string checkList) {
    bool check = true;
    for (int i = 0; i < part.length(); i++) {
        if ((part[i] == '.' && part[i - 1] == '.') || part[0] == '.' || part[part.length() - 1] == '.' || !check) {
            check = false;
            break;
        } else if ((part[i] >= 'A' && part[i] <= 'Z') || (part[i] >= 'a' && part[i] <= 'z') || (part[i] >= '0' && part[i] <= '9')) {
            continue;
        } else {
            for (int j = 0 ; j < checkList.length(); j++) {
                check = false;
                if (part[i] == checkList[j]) {
                    check = true;
                    break;
                };
            }
        }
    }
    return check;
}

bool emailCheck (std::string email) {
    std::string part1, part2;
    std::string checkList1 = ".!#$%&'*+-/=?^_`{|}~";
    std::string checkList2 = ".-";
    bool at = false;
    bool check = true;
    //Делим на части и считаем собак
    for (int i = 0; i < email.length(); i++) {
        if ((email[i] == '@' && at) || (i == email.length() - 1 && !at)) {
            check = false;
            break;
        } else if (email[i] == '@') {
            at = true;
            continue;
        }
        if (!at) {
            part1 += email[i];
        } else {
            part2 += email[i];
        }
    }

    if (part1.length() < 1 || part1.length() > 64 || part2.length() < 1 || part2.length() > 63 || !check) check = false;
    else if (partCheck(part1, checkList1)) check = partCheck(part2, checkList2);
    else check = false;
    return check;
}

int main() {
    std::string email;

    std::cout << "Enter you e-mail: ";
    std::getline(std::cin, email);

    std::cout << (emailCheck(email) ? "Yes\n" : "No\n");
    return 0;
}
