#include <iostream>
int loc[5][5][10]{0};
int x, y, z;

void pillarsHeigth(int i, int j){
        do {
            std::cout << "Enter the pillar heigth for sector: " << i << " . " << j << "\n";
            std::cin >> z;
            if (z < 0 || z > 10) std::cout << "Wrong input!\n";
        } while (z < 0 || z > 10);
}

void pillarsInstall(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            pillarsHeigth(i, j);
            if(z != 0) {
                for (int h = 0; h < z; h++) loc[i][j][h] = 1;
            }
        }
    }
}

void sectionPrint(){
    do {
        do {
            std::cout << "enter the section height or -1 to exit: \n";
            std::cin >> z;
            if (z < -1 || z > 10) std::cout << "Wrong input!\n";
        } while (z < -1 || z > 10);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                std::cout << loc[i][j][z - 1] << " ";
            }
            std::cout << "\n";
        }
    } while(z != -1);
}


int main() {
    pillarsInstall();
    sectionPrint();
    return 0;
}
