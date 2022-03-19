#include <iostream>
#include <string>
#include <sstream>

enum notes{
    DO = 1 << 1,
    RE = 1 << 2,
    MI = 1 << 3,
    FA = 1 << 4,
    SO = 1 << 5,
    LA = 1 << 6,
    SI = 1 << 7
};

int main() {
    std::stringstream result;
    std::string input;
    int i = 0;

    for(int i = 0; i < 12; i++){
        std::cout << "Input " << i + 1 << " combination of notes" << std::endl;
        std::cin >> input;

        for(int j = 0; j < input.size(); j++){
            if((1 << (input[j] - '0')) == DO) result << "DO ";
            if((1 << (input[j] - '0')) == RE) result << "RE ";
            if((1 << (input[j] - '0')) == MI) result << "MI ";
            if((1 << (input[j] - '0')) == FA) result << "FA ";
            if((1 << (input[j] - '0')) == SO) result << "SO ";
            if((1 << (input[j] - '0')) == LA) result << "LA ";
            if((1 << (input[j] - '0')) == SI) result << "SI ";
        }
        result << "\n";
    }

    std::cout << result.str() << std::endl;

    return 0;
}
