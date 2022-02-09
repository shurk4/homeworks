#include <iostream>

bool popit[12][12];
int x1, x2, y1, y2;

void start(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            popit[i][j] = true;
        }
    }
}

void print(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            std::cout << (popit[i][j] ? "O" : "X") << " ";
        }
        std::cout << "\n";
    }
}


void input(){
    do{
        std::cout << "Enter beginning coordinates x, y:\n";
        std::cin >> x1 >> y1;
        if(x1 < 1 || x1 > 12 || y1 < 1 || y1 > 12) std::cout << "Wrong input!\n";
    }while(x1 < 1 || x1 > 12 || y1 < 1 || y1 > 12);

    do{
        std::cout << "Enter end coordinates x, y:\n";
        std::cin >> x2 >> y2;
        if(x2 < 1 || x2 > 12 || y2 < 1 || y2 > 12) std::cout << "Wrong input!\n";
    }while(x2 < 1 || x2 > 12 || y2 < 1 || y2 > 12);

    if(x1 > x2) std::swap(x1, x2);
    if(y1 > y2) std::swap(y1, y2);
}

void pop(){
    for(int i = x1 - 1; i < x2; i++){
        for(int j = y1 - 1; j < y2; j++){
            if(popit[i][j]) {
                popit[i][j] = false;
                std::cout << "Pop! ";
            } else std::cout << "     ";
        }
        std::cout << "\n";
    }
}

bool popitCheck(){
    bool check = false;
    for(int i = 0 - 1; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(popit[i][j]){
                check = true;
                break;
            }
        }
    }
    return check;
}

int main() {
    std::cout << "======= Pop it! =======\n";
    start();
    print();
    while(popitCheck()){
        input();
        pop();
        print();
    }
    return 0;
}
