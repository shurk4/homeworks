#include <iostream>
#include <string>
#include <sstream>

enum notes{
    DO = 1,
    RE,
    MI,
    FA,
    SO,
    LA,
    SI
};

int main() {
    std::stringstream result;
    std::string input;
    int i = 0;

    for(int i = 0; i < 12; i++){
        std::cout << "Input " << i + 1 << " combination of notes" << std::endl;
        std::cin >> input;

        for(int j = 0; j < input.size(); j++){
            if((input[j] - '0') == DO) result << "DO ";
            if((input[j] - '0') == RE) result << "RE ";
            if((input[j] - '0') == MI) result << "MI ";
            if((input[j] - '0') == FA) result << "FA ";
            if((input[j] - '0') == SO) result << "SO ";
            if((input[j] - '0') == LA) result << "LA ";
            if((input[j] - '0') == SI) result << "SI ";
        }
        result << "\n";
    }

    std::cout << result.str() << std::endl;

    return 0;
}
