#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void reelTurn(int& sector, std::vector<int>& usedSectors){
    int turn;

    std::cout << "How many sectors to rotate the reel?" << std::endl;
    do {
        std::cin >> turn;
        if (turn < 1) std::cout << "Wrong input! Try again." << std::endl;
    } while (turn < 1);

    sector = (sector + turn) % 13;

    int i = 0;
    do {
        if(sector == 0) sector = 13;
        if(usedSectors.size() != 0 && usedSectors[i] == sector) {
            std::cout << "Sector " << sector << " has already been used, checking the next sector..." << std::endl;
            sector++;
            i = 0;
        }
        if(sector == 0) sector = 13;
        if(sector > 13) sector %= 13;
        i++;
    } while(i < usedSectors.size());

    usedSectors.push_back(sector);
}

int main() {
    std::vector<int> usedSectors;
    int player = 0,
        comp = 0,
        sector = 1;

    while(player < 6 && comp < 6){
        std::ifstream file;
        std::string path,
                    temp,
                    ans;

        reelTurn(sector, usedSectors);

        std::cout << "Sector " << sector << " on the reel! Question: " << std::endl;
        path += "..\\quest" + std::to_string(sector - 1) + ".txt";

        file.open(path);
        if(file.is_open()) {
            std::getline(file, temp);
            file >> temp;
            file.close();
            std::cout << temp << std::endl;
        } else {
            std::cout << "Could not open the quest file";
            return 1;
        }

        path.clear();
        path += "..\\ans" + std::to_string(sector - 1) + ".txt";

        file.open(path);
        if(file.is_open()) {
            std::getline(file, temp);
            file >> temp;
            file.close();

            std::cout << "Enter the answer:" << std::endl;
            std::cin >> ans;

            if(temp == ans) {
                std::cout << "The answer is correct!" << std::endl;
                player++;
            }
            else {
                std::cout << "The answer is not correct!" << std::endl;
                comp++;
            }

        } else {
            std::cout << "Could not open the answer file";
            return 1;
        }

        std::cout << "-------------------------------------------------" << std::endl;

        if(player == 6) std::cout << "Player win!" << std::endl;
        if(comp == 6) std::cout << "Computer win!" << std::endl;
    }


    return 0;
}
