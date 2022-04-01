#include <iostream>
#include <fstream>
#include <string>

//  ..\\file.png  ..\\jpg.png

void fileOpen (std::string& path){
    std::ifstream file;
    std::string pathExt;

    while(!file.is_open()) {
        std::cout << "Enter the path to the file:";
        getline(std::cin, path);

        pathExt = path.substr(path.length() - 3, 3);
        if (pathExt != "png" && pathExt != "PNG"){
            std::cout << "This file has a non-PNG extension, try again." << std::endl;
            continue;
        }

        file.open(path);

        std::cout << "====================" << std::endl;
        if (!file.is_open()) std::cout << "Could not open the file!" << std::endl;
        else std::cout << "The file os open! " << "Path: " << path <<std::endl;
    }
    file.close();
    std::cout << "====================" << std::endl;
}

bool checkPNG (std::string& path){
    char ext[4];

    std::ifstream file(path, std::ios::binary);
    file.read(ext, sizeof(ext));
    file.close();

    if(ext[0] != -119 || ext[1] != 'P' || ext[2] != 'N' || ext[3] != 'G') {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    std::string path;

    fileOpen(path);

    if(checkPNG(path)) std::cout << "This file has a PNG extension" << std::endl;
    else std::cout << "This file is not PNG" << std::endl;

    return 0;
}
