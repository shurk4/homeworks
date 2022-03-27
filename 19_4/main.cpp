#include <iostream>
#include <fstream>

//  ..\\file.png

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

bool checkPNG (std::string& path){
    std::ifstream file(path);
    std::string ext;
    char buffer[4];

    file.read(buffer, 4);
    file.close();

    int num = buffer[0];

    ext += buffer[1];
    ext += buffer[2];
    ext += buffer[3];

    if(num != -119 || ext != "PNG") return false;
    else return true;
}

int main() {
    std::string path;

    fileOpen(path);

    if(checkPNG(path)) std::cout << "This file has a PNG extension" << std::endl;
    else std::cout << "This file is not PNG" << std::endl;

    return 0;
}
