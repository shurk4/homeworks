#include <iostream>
#include <fstream>

// ..\\text.txt

void fileOpen (std::string& path){
    std::ifstream file;

    while(!file.is_open()) {
        std::cout << "Enter the path to the file:";
        getline(std::cin, path);

        file.open(path);
        std::cout << "====================" << std::endl;
        if (!file.is_open()) std::cout << "Could not open the file!" << std::endl;
        else std::cout << "The file os open! " << "Path: " << path <<std::endl;
    }
    file.close();
    std::cout << "====================" << std::endl;
}

void fileCout (std::string& path){
    std::ifstream file(path , std::ios::binary);
    int cursor = 0;

    while(!file.eof()) {
        char buff[20]{0};

//        file.seekg(cursor);
        file.read(buff, sizeof(buff) - 1);

//        cursor = file.tellg();

        std::cout << buff;
    }
    file.close();
}

int main() {
    std::string path;

    fileOpen(path);

    fileCout(path);

    return 0;
}
