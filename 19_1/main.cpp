#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main() {
    std::ifstream file;
    std::vector<std::string> text;

    file.open("text.txt");

    while(!file.eof()){
        std::string word;
        file >> word;
        text.push_back(word);
    }

    for(int i = 0; i < text.size(); i++){
        std::cout << text[i] << " ";
    }

    return 0;
}
