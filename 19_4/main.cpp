#include <iostream>
#include <fstream>

//  ..\\file.png  ..\\test.jpg

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
    std::string ext;

    std::ifstream file(path);
    std::getline(file, ext);
    file.close();

    if(ext.substr(1,3) != "PNG") return false;
    else return true;
}

int main() {
    std::string path;

    fileOpen(path);

    if(checkPNG(path)) std::cout << "This file has a PNG extension" << std::endl;
    else std::cout << "This file is not PNG" << std::endl;

    return 0;
}
