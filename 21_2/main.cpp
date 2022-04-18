/*С помощью структур данных создайте подробную модель посёлка.

В посёлке есть множество участков. Каждый из них имеет свой уникальный номер.
На каждом из участков должен быть расположен как минимум один жилой дом, но возможны и другие сооружения,
такие как гараж, сарай (бытовка) и баня. Для каждого здания предусмотрена информация о площади, которую он занимает на участке.

В жилом доме может быть 1–3 этажа. На каждом из этажей может быть 2–4 комнаты.
Каждая комната при этом может быть разных типов: спальня, кухня, ванная, детская, гостиная.
Для каждой комнаты предусмотрены данные о её площади. Для каждого этажа также есть данные о высоте потолка.
В жилом доме и бане может быть печь с трубой, информация об этом также должна быть предусмотрена в данных.

Для всех упомянутых сущностей надо объявить соответствующие структуры данных.

Вначале работы программы пользователь заполняет данные о посёлке: вводит общее количество участков и далее начинает детализировать каждый из участков.

Для каждого участка сначала заполняется общее количество построек, а затем детализируется каждая постройка, этажи, комнаты на этажах.

По итогам введённых данных вы можете рассчитать некий суммарный параметр, например, процент земли, занимаемой постройками,
к общей площади всего посёлка. Главное в этой задаче не сама операция подсчёта, а структуры данных.



Советы и рекомендации

Используйте все имеющиеся у вас знания о типах данных в C++.
Можно  использовать уже изученные перечисления и массивы, создавать структуры внутри структур и так далее.*/

#include <iostream>
#include <vector>

struct room{
    std::string name;
    float area;
};

struct floor{
    std::vector<room> rooms;
    float heigth;
};

struct build{
    std::string name;
    float area;
    bool furnace = false;
    std::vector<floor> floors;
};

struct ploat{
    int number;
    float area;
    std::vector<build> buildings;
};

//вывод данных
void printData(std::vector<ploat>& vec){
    for(int i = 0; i < vec.size(); i++) {
        std::cout << "Ploat # " << i + 1 << std::endl;
        std::cout << "Ploat # " << i + 1 << " area:" << vec[i].area << std::endl;
        std::cout << "\tBuildings: " << vec[i].buildings.size() << std::endl;
        for(int j = 0; j < vec[i].buildings.size(); j++) {
            std::cout << "\t\tBiuld " << j + 1 << ": " << vec[i].buildings[j].name << std::endl;
            std::cout << "\t\t\tArea: " << vec[i].buildings[j].area << std::endl;
            if(j == 0 || vec[i].buildings[j].name == "bathhouse") {
                if (vec[i].buildings[j].furnace) {
                    std::cout << "\t\t\tFurnace installed" << std::endl;
                }
            }
            if(j == 0){
                std::cout << "\t\t\tFloors: " << vec[i].buildings[j].floors.size() << std::endl;
                for(int k = 0; k < vec[i].buildings[j].floors.size(); k++){
                    std::cout << "\t\t\tFloor " << k + 1 << " height: " << vec[i].buildings[j].floors[k].heigth << std::endl;
                    std::cout << "\t\t\t\tRooms " << vec[i].buildings[j].floors[k].rooms.size() << std::endl;
                    for(int l = 0; l < vec[i].buildings[j].floors[k].rooms.size(); l++){
                        std::cout << "\t\t\t\t Room " << l + 1 << " name: " << vec[i].buildings[j].floors[k].rooms[l].name << std::endl;
                        std::cout << "\t\t\t\t\tSize: " << vec[i].buildings[j].floors[k].rooms[l].area << std::endl;
                    }
                }
            }
        }
    }
}

// проверка введёных данных на число
bool digitCheck(std::string& input){
    bool point = false;
    for(int i = 0; i < input.length(); i++){
        if((input[i] >= '0' && input[i] <= '9') || input[i] == '.'){
            if(input[i] == '.' && point == false){
                point = i;
            } else if(input[i] == '.' && point == true){
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

// проверка да / нет
bool yesOrNoCheck(std::string & input){
    if(input == "YES" || input == "yes"|| input == "Yes" || input == "Y" || input == "y" ||
       input == "NO" || input == "no" || input == "No" || input == "N" || input == "n"){
        return true;
    } else {
        return false;
    }
}

//Не правильный ввод!
void wrongInput(){
    std::cout << "Wrong input! Try again:" << std::endl;
}

//Процент площади построек ===========================================================================================
void buildingsPercent(std::vector<ploat>& vec){
    float villageArea = 0,
          buildingsArea = 0;
    for(int i = 0; i < vec.size(); i++){
        villageArea += vec[i].area;
        for(int j = 0; j < vec[i].buildings.size(); j++){
            buildingsArea += vec[i].buildings[j].area;
        }
    }

    std::cout << "The area of all plots: " << villageArea << std::endl;
    std::cout << "The area of all buildings: " << buildingsArea << std::endl;
    std::cout << "Buildings occupy " << buildingsArea / (villageArea / 100) << "% of the area of the village" << std::endl;

}

int main() {
    std::string tempString;
    std::vector<ploat> village;

    // ввод количества участков
    do {
        std::cout << "Enter the number of plots" << std::endl;
        std::cin >> tempString;
        if (!digitCheck(tempString)) {
            wrongInput();
        }
    } while (!digitCheck(tempString));
    village.resize(std::stoi(tempString));

    // детализация участков =========================================================================
    for(int i = 0; i < village.size(); i++){
        // ввод площади участков
        do {
            std::cout << "Enter the size of the plot No.  " << i + 1 << ":" << std::endl;
            std::cin >> tempString;
            if (!digitCheck(tempString)) {
                wrongInput();
            }
        } while (!digitCheck(tempString));
        village[i].area = (std::stoi(tempString));

        //ввод количества построек на участке
        do {
            std::cout << "Enter the number of buildings on the plot " << i + 1 << ":" << std::endl;
            std::cin >> tempString;
            if (!digitCheck(tempString)) {
                wrongInput();
            }
        } while (!digitCheck(tempString));
        village[i].buildings.resize(std::stoi(tempString));

        // детализация построек =====================================================================
        // название пострйки
        for(int j = 0; j < village[i].buildings.size(); j++){
            if (j == 0) {
                std::cout << "The first building is a house." << std::endl;
                village[i].buildings[0].name = "House";
            }
            else {
                std::cout << "Enter the name of building " << j + 1 << " on the plot " << i + 1 << ":" << std::endl;
                std::cin >> village[i].buildings[j].name;
            }

            // площадь постройки
            do {
                std::cout << "Enter the area of the building:" << std::endl;
                std::cin >> tempString;
                if (!digitCheck(tempString)) {
                    wrongInput();
                }
            } while (!digitCheck(tempString));
            village[i].buildings[j].area = std::stoi(tempString);

            // если дом или баня наличие печи
            if(j == 0 || village[i].buildings[j].name == "bathhouse"){
                do {
                    std::cout << "Is the furnace installed? Yes/No:" << std::endl;
                    std::cin >> tempString;
                    if (!yesOrNoCheck(tempString)) {
                        wrongInput();
                    }
                } while(!yesOrNoCheck(tempString));
                if(tempString == "YES" || tempString == "yes"|| tempString == "Yes" || tempString == "Y" || tempString == "y"){
                    village[i].buildings[j].furnace = true;
                }
            }

            if(j == 0){
                // количество этажей в доме
                do {
                    std::cout << "Enter the number of floors in the house" << std::endl;
                    std::cin >> tempString;
                    if (!digitCheck(tempString)) {
                        wrongInput();
                    }
                } while (!digitCheck(tempString));
                village[i].buildings[0].floors.resize(std::stoi(tempString));

                //детализация этажей в доме ------------------------------------------------------------
                //высота потолков, название комнат и их площадь для каждого этажа
                for(int k = 0; k < village[i].buildings[j].floors.size(); k++){
                    // высота потолков
                    std::cout << "Enter the floor information" << std::endl;
                    do {
                        std::cout << "enter the ceiling height of the floor " << k + 1 << ":" << std::endl;
                        std::cin >> tempString;
                        if (!digitCheck(tempString)) {
                            wrongInput();
                        }
                    } while (!digitCheck(tempString));
                    village[i].buildings[j].floors[k].heigth = std::stod(tempString);

                    // количество комнат
                    do {
                        std::cout << "Enter the number of rooms on the floor " << k + 1 << " :" << std::endl;
                        std::cin >> tempString;
                        if (!digitCheck(tempString)) {
                            wrongInput();
                        }
                    } while (!digitCheck(tempString));
                    village[i].buildings[j].floors[k].rooms.resize(std::stoi(tempString));

                    // детализация комнат ---------------------------------------------------------------
                    for(int l = 0; l < village[i].buildings[j].floors[k].rooms.size(); l++){
                        std::cout << "Enter the name of the room " << l + 1 << ":" << std::endl;
                        std::cin >> village[i].buildings[j].floors[k].rooms[l].name;

                        do{
                            std::cout << "Enter the area of the room " << l + 1 << ":" << std::endl;
                            std::cin >> tempString;
                            if (!digitCheck(tempString)) {
                                wrongInput();
                            }
                        } while (!digitCheck(tempString));
                        village[i].buildings[j].floors[k].rooms[l].area = std::stod(tempString);
                    }
                }
                // конец детализации этажей ----------------------------------------------------------
            }
        }
    }
    printData(village);

    buildingsPercent(village);
}