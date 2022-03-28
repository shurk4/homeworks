#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void findMatches(std::string str, std::string substr, int& counter)
{
    std::vector<int> matches;
    std::vector<int> p(substr.size() + 1, -1);

    for (int i = 0, j = -1;i < substr.size();){
        while (j > -1 && substr[i] != substr[j]) j = p[j];
        i++;
        j++;
        p[i] = j;
    }

    for (int i=0, j = 0;i < str.size();)
    {
        while (j > -1 && str[i] != substr[j]) j = p[j];
        i++;
        j++;
        if (j == substr.size()) counter++;
    }
}

bool openFile (std::string& text){
    std::ifstream file;
    file.open("..\\text.txt");

    while(!file.eof()){
        std::string word;
        file >> word;
        text += word + " ";
    }
    file.close();
}

int main() {
    int count = 0;
    std::string text, find = "roads";

    openFile(text);

    findMatches(text, find, count);
    std::cout << count << " matches found" << std::endl;

    return 0;
}
