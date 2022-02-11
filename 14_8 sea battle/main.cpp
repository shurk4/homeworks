#include <iostream>
char field1[10][10]{' '};
char field2[10][10]{' '};
int x1, x2, y1, y2, hits1 = 0, hits2 = 0;
bool player = true;

//Заполняем оба поля
void fieldStart() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            field1[i][j] = ' ';
            field2[i][j] = ' ';
        }
    }
}

//Вывод поля текущего игрока
void fieldPrint(char field[10][10]){
    std::cout << " --------======= Player " << (player ? "1" : "2") << " =======---------\n";
    std::cout << " -----------------------------------------\n";
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++){
            std::cout << " | " << field[i][j];
        }
        std::cout << " |\n" << " -----------------------------------------\n";
    }
}

//Оптимизация координат
void swapCoords(int swapX, int swapY){
    if(x1 > x2 || swapX) {
        std::swap(x1, x2);
        swapX = !swapX;
    }
    if(y1 > y2 || swapY) {
        std::swap(y1, y2);
        swapY = !swapY;
    }
}

//Проверка ввода
bool checkInput(int x, int y){
    bool check = false;
    if (x < 0 || x > 9 || y < 0 || y > 9) {
        std::cout << "Wrong input!\n";
        check = true;
    }
    return check;
}

//Проверка введёных координат
bool coordsCheck(int shipSize) {
    bool check = false;

    if (x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9) {
        std::cout << "Wrong input!\n";
        check = true;
    } else if (x2 - x1 != shipSize - 1 && y2 - y1 != shipSize - 1) {
        std::cout << "Wrong ship size!\n";
        check = true;
    } else if ((x2 - x1 == shipSize - 1 && y1 != y2) || (y2 - y1 == shipSize - 1 && x1 != x2)) {
        std::cout << "Ship should be one cell wide!\n";
        check = true;
    }

    return check;
}

//Проверка занятости места
bool placeCheck(int shipSize){
    bool check = false;
    if(shipSize == 1 && ((player && field1[x1][y1] != ' ') || (!player && field2[x1][y1] != ' '))){
        check = true;
    }
    else {
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <= y2; j++){
                if(((player && field1[i][j] != ' ') || (!player && field2[i][j] != ' '))){
                    check = true;
                    break;
                }
            }
        }
    }
    if(check) {
        std::cout << "The coordinates are not empty\n";
    }
    return check;
}

//Установка корабля
void shipInstall(int shipSize){
    if(shipSize == 1) player ? field1[x1][y1] = char(178) : field2[x1][y1] = char(178);
    else {
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <= y2; j++){
                player ? field1[i][j] = char(178) : field2[i][j] = char(178);
            }
        }
    }
}

//Ввод координат установки кораблей
void shipSetup(){
    // Корабли [размер корабля][количество кораблей]
    int ships[4][2]{{1, 4}, {2, 3}, {3,2},{4,1}};
    int shipSize; //Размер текущего корабля
    for(int i = 0; i < 4; i++){
        for(int j = ships[i][1]; j > 0; j--){
            shipSize = ships[i][0];
            if(shipSize == 1) {
                do {
                    std::cout << "Enter the x, y coordinates of the ship with " << shipSize <<
                                 " decks No" << ships[i][1] - j + 1 << ":\n";
                    std::cin >> x1 >> y1;
                } while(checkInput(x1, y1) || placeCheck(shipSize));
            } else {
                do {
                    bool swapX = false;
                    bool swapY = false;
                    do {
                        std::cout << "Enter the start x, y coordinates of the ship with " << shipSize <<
                                  " decks No" << ships[i][1] - j + 1 << ":\n";
                        std::cin >> x1 >> y1;
                    } while (checkInput(x1, y1));

                    do {
                        std::cout << "Enter the end x, y coordinates of the ship with " << shipSize <<
                                  " decks No" << ships[i][1] - j + 1 << ":\n";
                        std::cin >> x2 >> y2;
                        swapCoords(swapX,swapY);
                    } while (checkInput(x2, y2));
                } while (coordsCheck(shipSize) || placeCheck(shipSize));
            }
            shipInstall(shipSize);
            fieldPrint((player ? field1 : field2));
        }
    }
    player = !player;
}

void attackCoords(){
    std::cout << " --------======= Player " << (player ? "1" : "2") << " =======---------\n";
    do {
        std::cout << "Enter the attack coordinates:\n";
        std::cin >> x1 >> y1;
    } while(checkInput(x1, y1));
}

void attack(){
    if(player){
        if (field1[x1][y1] == char(178)) {
            field1[x1][y1] = 'X';
            hits1++;
        }
        else field1[x1][y1] = '*';
    } else {
        if (field2[x1][y1] == char(178)) {
            field2[x1][y1] = 'X';
            hits2++;
        }
        else field2[x1][y1] = '*';
    }
}

void winner(){
    if(hits1 == 20) std::cout << "--------===== Player 1 win! =====--------\n";
    if(hits2 == 20) std::cout << "--------===== Player 2 win! =====--------\n";
};

void play(){
    do{
        attackCoords();
        player = !player;
        attack();
        fieldPrint((player ? field1 : field2));
        winner();
    }while(hits1 < 20 && hits2 < 20);
}


int main() {
    fieldStart();
    fieldPrint(field1);
    shipSetup();
    std::cout << "\n\n";
    fieldPrint(field2);
    shipSetup();
    play();
    return 0;
}
