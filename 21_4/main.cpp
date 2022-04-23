/*Реализуйте сильно упрощённую версию ролевой пошаговой игры:

Игра происходит на карте размером 40 на 40 клеток. По клеткам перемещаются враги и персонаж игрока.

После каждого хода игрока карта показывается вновь со всеми врагами на ней. Игрок помечается буквой P. Враги буквой E. Пустые места — точкой.

Каждый персонаж игры представлен в виде структуры с полями: имя, жизни, броня, урон.

Вначале игры создаются 5 случайных врагов в случайных клетках карты. Имена врагам задаются в формате “Enemy #N”,
 где N — это порядковый номер врага. Уровень жизней врагам задаётся случайно, от 50 до 150.
 Уровень брони варьируется от 0 до 50. Урон тоже выбирается случайно от 15 до 30 единиц.

Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры, включая имя.

Все персонажи появляются в случайных местах карты.

Игрок осуществляет ход с помощью команд: left, right, top, bottom.
 В зависимости от команды и выбирается направление перемещения персонажа: влево, вправо, вверх, вниз.

Враги перемещаются в случайном направлении.

Если персонаж (враг или игрок) перемещается в сторону, где уже находится какой-то персонаж,
 то он бьёт этого персонажа с помощью своего урона. Враги при этом никогда не бьют врагов,
 а просто пропускают ход и остаются на своём месте. За пределы карты (40 на 40 клеток) ходить нельзя никому.
 Если кто-то выбрал направление за гранью дозволенного, ход пропускается.

Формула для расчёта урона совпадает с той, что была в самом уроке. Жизни уменьшаются на оставшийся после брони урон.
 При этом сама броня тоже сокращается на приведённый урон.

Игра заканчивается тогда, когда либо умирают все враги, либо персонаж игрока.
 В первом случае на экран выводится сообщение о поражении, во втором — победа.

Если в начале хода игрок вводит команду save или load вместо направления перемещения,
 то игра либо делает сохранение своего состояния в файл, либо загружает это состояние из файла соответственно.



Советы и рекомендации

        Для определения команды персонажа можно завести специальный флаг внутри структуры данных персонажа.

Для отображения координат персонажей можете использовать структуру вектора из другой задачи, но заменить типы координат.*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>

char defaultSymbol = '.';

struct charBlank{
    std::string name,
            action = "random";
    int health = 0,
            shield = 0,
            damage = 0,
            xPos = 0,
            yPos = 0,
            xPosNew = 0,
            yPosNew = 0;
    bool enemy = true;
};

struct fieldCell{
    char cell = defaultSymbol;
    int id;
};

// проверка на число
bool digitCheck(std::string& input){
    bool point = false;
    for(int i = 0; i < input.length(); i++){
        if((input[i] >= '0' && input[i] <= '9') || input[i] == defaultSymbol){
            if(input[i] == defaultSymbol && point == false){
                point = i;
            } else if(input[i] == defaultSymbol && point == true){
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

//проверка действия
bool actionCheck(std::string& action){
    if(action == "up" || action == "down" || action == "left" ||
       action == "right" || action == "save" || action == "load") {
        return true;
    }
    else {
        return false;
    }
}

//проверка координат
bool coordsCheck(int& x, int& y){
    if(x >= 0 && x < 40 && y >= 0 && y < 40){
        return true;
    }
    else {
        return false;
    }
}

//вывод персонажей
void characterPrint(std::vector<charBlank> character){
    for (int i = 0; i < character.size(); i++) {
        std::cout << "Character id # " << i << ":" << std::endl;
        std::cout << "Name:\t" << character[i].name << std::endl;
        std::cout << "Health:\t" << character[i].health << std::endl;
        std::cout << "Shield:\t" << character[i].shield << std::endl;
        std::cout << "Damage:\t" << character[i].damage << std::endl;
        std::cout << "Coords:\t" << character[i].xPos << ", " << character[i].yPos << std::endl;
        std::cout << "Command:" << (character[i].enemy ? "Enemy" : "Player") << std::endl;
        std::cout << std::endl << std::endl;
    }
}

// вывод поля
void fieldPrint(std::vector<std::vector<fieldCell>>& field) {
    std::cout << "\n________________________________________________________________________________________." << std::endl;
    for (int i = 0; i < field.size(); i++) {
        std::cout << i << "\t";
        for(int j = 0; j < field[i].size(); j++){
            if(j == 0){
                std::cout << "|";
            }
            std::cout << field[i][j].cell << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
}

void number(int& param){
    std::string input;
    do {
        std::cin >> input;
        if(digitCheck(input)){
            param = std::stoi(input);
        }
        else {
            std::cout << "Wrong input! Try again:";
        }

    } while (!digitCheck(input));
}

// размещение персонажей
void characterPos(std::vector<std::vector<fieldCell>>& field, charBlank& ch, int& id){
    do {
        ch.yPos = std::rand() % 40;
        ch.xPos = std::rand() % 40;
    } while (field[ch.yPos][ch.xPos].cell != defaultSymbol);
    field[ch.yPos][ch.xPos].cell = ch.enemy ? 'E' : 'P';
    field[ch.yPos][ch.xPos].id = id;
}

// создание персонажей
void charCreate(std::vector<std::vector<fieldCell>>& field, std::vector<charBlank>& character){
    for(int i = 0; i < character.size(); i++){
        if(i == 0){
            std::cout << "Create your character:" << std::endl;
            std::cout << "name:   ";
//            character[i].name = "SuperPereZ";
            std::cin >> character[i].name;
            std::cout << "Health:   ";
//            character[i].health = 50;
            number(character[i].health);
            std::cout << "Shield:   ";
//            character[i].shield = 50;
            number(character[i].shield);
            std::cout << "Damage:   ";
//            character[i].damage = 100;
            number(character[i].damage);
            character[i].enemy = false;
            std::cout << std::endl;
        }
        else {
            std::stringstream tempName;
            tempName << "Enemy #" << i;
            std::getline(tempName, character[i].name);
            character[i].health = 50 + std::rand() % 100;
            character[i].shield = std::rand() % 50;
            character[i].damage = 15 + std::rand() %15;
        }
        characterPos(field, character[i], i);
    }
    characterPrint(character);
}

// АТАКА
void attack(charBlank& attacker, charBlank& defender){
    std::cout << "ATTACK!!!" << std::endl;
    std::cout << "   defender name: " << defender.name << std::endl << "   attacker name: " << attacker.name << std::endl;
    std::cout << defender.name << " took " << attacker.damage <<" damage from " << attacker.name << std::endl;
    defender.shield -= attacker.damage;

    if (defender.shield < 0) {
        defender.health += defender.shield;
        defender.shield = 0;
    }
    std::cout << defender.name << ": health: " << defender.health << " shild: " << defender.shield << std::endl;
}

// действия персонажей
void move(std::vector<std::vector<fieldCell>>& field, std::vector<charBlank>& character){
    for(int i = 0; i < character.size(); i++) {
        if (character[i].action == "random") {
            do {
                character[i].xPosNew = character[i].xPos;
                character[i].yPosNew = character[i].yPos;
                int action = std::rand() % 4;
                if (action == 0) {
                    character[i].yPosNew += 1;
                } else if (action == 1) {
                    character[i].yPosNew -= 1;
                } else if (action == 2) {
                    character[i].xPosNew += 1;
                } else if (action == 3) {
                    character[i].xPosNew -= 1;
                }
                if (!coordsCheck(character[i].xPosNew, character[i].yPosNew)) {
                    continue;
                }
            } while ((!coordsCheck(character[i].xPosNew, character[i].yPosNew)) || (field[character[i].yPosNew][character[i].xPosNew].cell != defaultSymbol
                        && field[character[i].yPosNew][character[i].xPosNew].cell != 'P'));
        } else {
            character[i].xPosNew = character[i].xPos;
            character[i].yPosNew = character[i].yPos;
            if (character[i].action == "up") {
                character[i].yPosNew -= 1;
            } else if (character[i].action == "down") {
                character[i].yPosNew += 1;
            } else if (character[i].action == "right") {
                character[i].xPosNew += 1;
            } else if (character[i].action == "left") {
                character[i].xPosNew -= 1;
            }
            if (!coordsCheck(character[i].xPosNew, character[i].yPosNew)) {
                continue;
            }
        }

        if (field[character[i].yPosNew][character[i].xPosNew].cell == defaultSymbol) {
            field[character[i].yPos][character[i].xPos].cell = defaultSymbol;
            field[character[i].yPosNew][character[i].xPosNew].cell = character[i].enemy ? 'E' : 'P';
            field[character[i].yPosNew][character[i].xPosNew].id = i;
            character[i].xPos = character[i].xPosNew;
            character[i].yPos = character[i].yPosNew;
        } else {
            if(i > 0 && field[character[i].yPosNew][character[i].xPosNew].cell == 'P'){
                attack(character[i], character[0]);
                if(character[0].health <= 0) {
                    std::cout << "Your character is destroyed!" << std::endl;
                    field[character[0].yPos][character[0].xPos].cell = 'X';
                }
            }
            else if(i == 0 && field[character[i].yPosNew][character[i].xPosNew].cell == 'E'){
                attack(character[0], character[field[character[i].yPosNew][character[i].xPosNew].id]);
                if(character[field[character[i].yPosNew][character[i].xPosNew].id].health <= 0) {
                    std::cout << character[field[character[i].yPosNew][character[i].xPosNew].id].name << " is destroyed!" << std::endl << std::endl;
                    field[character[0].yPosNew][character[0].xPosNew].cell = defaultSymbol;
                    character.erase(character.begin() + field[character[i].yPosNew][character[i].xPosNew].id);
                    characterPrint(character); //--------------------------------------------------------------------------------
                }
            }
        }
    }
}

// сохранение
void save(std::vector<std::vector<fieldCell>>& field, std::vector<charBlank>& character){
    std::ofstream file("..\\save.bin", std::ios::binary);

    if(file.is_open()) {
        for (int i = 0; i < character.size(); i++) {
            int charNum = character.size();
            int len = character[i].name.length();
            file.write((char *) &charNum, sizeof(charNum));
            file.write((char *) &len, sizeof(len));
            file.write(character[i].name.c_str(), len);
            file.write((char *) &character[i].health, sizeof(character[i].health));
            file.write((char *) &character[i].shield, sizeof(character[i].shield));
            file.write((char *) &character[i].damage, sizeof(character[i].damage));
            file.write((char *) &character[i].xPos, sizeof(character[i].xPos));
            file.write((char *) &character[i].yPos, sizeof(character[i].yPos));
            file.write((char *) &character[i].enemy, sizeof(character[i].enemy));
        }
    }
    else {
        std::cout << "Could not open save.bin file" << std::endl;
    }
    file.close();
    std::cout << "The game is saved!" << std::endl;
}

// загрузка
void load(std::vector<std::vector<fieldCell>>& field, std::vector<charBlank>& character){
    for(int i = 0; i < field.size(); i++){
        for(int j = 0; j < field[i].size(); j++){
            field[i][j].cell = defaultSymbol;
            field[i][j].id = 0;
        }
    }

    std::ifstream file("..\\save.bin", std::ios::binary);
    if(file.is_open()) {
        for (int i = 0; i < character.size(); i++) {
            int charNum,
                len;
            file.read((char *) &charNum, sizeof(charNum));
            character.resize(charNum);
            file.read((char *) &len, sizeof(len));
            character[i].name.resize(len);
            file.read((char *) character[i].name.c_str(),len);
            file.read((char *) &character[i].health, sizeof(character[i].health));
            file.read((char *) &character[i].shield, sizeof(character[i].shield));
            file.read((char *) &character[i].damage, sizeof(character[i].damage));
            file.read((char *) &character[i].xPos, sizeof(character[i].xPos));
            file.read((char *) &character[i].yPos, sizeof(character[i].yPos));
            file.read((char *) &character[i].enemy, sizeof(character[i].enemy));
            field[character[i].yPos][character[i].xPos].cell = character[i].enemy ? 'E' : 'P';
            field[character[i].yPos][character[i].xPos].id = i;
        }
    }
    else {
        std::cout << "Could not open save.bin file" << std::endl;
    }
    file.close();
    std::cout << "The game is loaded!" << std::endl;
    characterPrint(character);
}

// ходы
void turn(std::vector<std::vector<fieldCell>>& field, std::vector<charBlank>& character){
    std::cout << "Enter the command:" << std::endl;
    do {
        std::cin >> character[0].action;
        if (!actionCheck(character[0].action)) {
            std::cout << "Wrong input! Try again:";
        }
    } while (!actionCheck(character[0].action));

    if(character[0].action == "save"){
        save(field, character);
    }
    else if(character[0].action == "load"){
        load(field, character);
    }
    else {
        move(field, character);
    }
}

// начало игры
void start(std::vector<std::vector<fieldCell>>& field, std::vector<charBlank>& character){
    std::string input;
    std::cout << "------====== Welcome to the turn-based RPG ======------ " << std::endl;
    std::cout << "------------------------------------------------------- " << std::endl;
    std::cout << "Enter \"start\" to start a new game or \"load\" to load saved game: ";
    do{
        std::cin >> input;
        if(input != "start" && input != "load"){
            std::cout << "Wrong input! Try again:";
        }
    } while(input != "start" && input != "load");
    if(input == "load"){
        load(field, character);
    }
    else {
        charCreate(field,character);
    }
}


int main() {
    int size = 40;
    int enemysNum = 5;
    std::vector<std::vector<fieldCell>> field (size, std::vector<fieldCell>(size));
    std::vector<charBlank> character (1 + enemysNum);
    std::srand(std::time(nullptr));

    start(field,character);

    fieldPrint(field);
    std::cout << character[0].name << " health: " << character[0].health << " shild: " << character[0].shield << std::endl;

    do{
        turn(field, character);

        fieldPrint(field);

        std::cout << character[0].name << " health: " << character[0].health << " shild: " << character[0].shield << std::endl;
        if(character.size() == 1){
            std::cout << "------ =============== You win!  ================------" << std::endl;
        }
        if(character[0].health <= 0){
            std::cout << "------================ You lose! ================------" << std::endl;
        }
    } while (character[0].health > 0 && character.size() > 1);

    std::cout << "------================ Game ower ================------" << std::endl;
    return 0;
}
