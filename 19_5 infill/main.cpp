#include <iostream>
#include <sstream>
#include <fstream>

int main() {
    for(int i = 0; i < 13; i++){
        std::cout << "===============================" << std::endl;
        std::ofstream file;
        std::stringstream pathIn;
        std::string temp;
        std::string path;

        pathIn << "..\\quest" << i << ".txt";
        pathIn >> temp;
        std::cout << "trying open the file: " << temp << std::endl;
        file.open(temp);
        if(file.is_open()) {
            std::cout << "Quest file: " << temp << std::endl;
            getline(std::cin, temp);

            file << temp;
        } else return 1;
        file.close();
        temp.clear();
        pathIn.clear();


        std::cout << "===============================" << std::endl;
        std::cout << "Temp after clear" << temp << std::endl;
        std::cout << "PatchIN after clear" << temp << std::endl;
        std::cout << "===============================" << std::endl;

        pathIn << "..\\ans" << i << ".txt";
        pathIn >> temp;
        std::cout << "trying open the file: " << temp << std::endl;
        file.open(temp);
        if(file.is_open()) {
            std::cout << "ans file: " << temp << std::endl;
            getline(std::cin, temp);

            file << temp;
        } else return 1;
        file.close();

    }
    std::cout << "The end! =)" << std::endl;
    return 0;
}
