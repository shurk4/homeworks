#include <iostream>

std::string encrypt_caesar(std::string text, int crypt) {
    std::string result;
    char a, z;

    crypt %= 26;
    if (crypt < 0) crypt += 26;

    for (int i = 0; i < text.length(); i++) {
        bool symbol = false;

        if (text[i] >= 'A' && text[i] <= 'Z') {
            a = 'A';
            z = 'Z';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            a = 'a';
            z = 'z';
        } else {symbol = true;}

        if (symbol) result += text[i];
        else if (text[i] + crypt > z) result += crypt - (z - text[i]) + a - 1;
        else result += text[i] + crypt;
    }

    return result;
}

std::string decrypt_caesar(std::string text, int crypt){
    return encrypt_caesar(text, -crypt);
}


int main() {
    int crypt;
    bool action;
    std::string text;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);

    std::cout << "Select encrypt[0] or decrypt[1]:\n";
    std::cin >> action;

    std::cout << "Enter encryption number: ";
    std::cin >> crypt;

    std::cout << (action ? decrypt_caesar(text, crypt) : encrypt_caesar(text, crypt)) << "\n";

    return 0;
}