#include <iostream>
#include <iomanip>

void table (std::string guests [2][6], std::string chairs[2][6], std::string tableware[2][6], std::string plates[2][6]) {
    for(int i = 0; i < 6; i++) {
        std::cout << plates[0][i] << std::setw(44 - plates[0][i].size()) << " | " << std::setw(9) << guests[0][i] << " | "
                  << guests[1][i] << std::setw(12 - guests[1][i].size()) << " | " << plates[1][i] << "\n"
                  << tableware[0][i] << ", " << chairs[0][i] << std::setw(42 - tableware[0][i].size() - chairs[0][i].size()) << " | " << std::setw(12) << " | "
                  << std::setw(12) <<  " | " << chairs[1][i] << ", " << tableware[1][i] << "\n"
                  << "------------------------------------------------------------------------------------------------------------\n";
    }
}
void later () {
    std::cout << "-------------------------------------------- Some time later... --------------------------------------------\n"
              << "------------------------------------------------------------------------------------------------------------\n";
}

int main() {
    std::string guests [2][6]{{"VIP Guest", "Guest" , "Guest", "Guest", "Guest","Guest"},
                              {"VIP Guest", "Guest" , "Guest", "Guest", "Guest","Guest"}};

    std::string chairs[2][6]{{"chair", "chair","chair","chair","chair","chair"},
                             {"chair","chair","chair","chair","chair","chair"}};

    std::string tableware[2][6]{{"fork, spoon, knife, dessert spoon","fork, spoon, knife","fork, spoon, knife",
                                 "fork, spoon, knife","fork, spoon, knife","fork, spoon, knife",},
                                {"fork, spoon, knife, dessert spoon","fork, spoon, knife","fork, spoon, knife",
                                 "fork, spoon, knife","fork, spoon, knife","fork, spoon, knife",}};

    std::string plates[2][6]{{"soup plate, second plate, dessert plate","soup plate, second plate","soup plate, second plate",
                              "soup plate, second plate","soup plate, second plate","soup plate, second plate"},
                             {"soup plate, second plate, dessert plate","soup plate, second plate","soup plate, second plate",
                                     "soup plate, second plate","soup plate, second plate","soup plate, second plate"}};

    std::cout << "A banquet of the successful passage of two-dimensional arrays! Planned seating of guests:\n"
                << "------------------------------------------------------------------------------------------------------------\n";

    table(guests, chairs, tableware, plates);

    later();
    chairs[0][4] = "chair, chair"; // Пришедшая на 5-ое место первого ряда дама пришла вместе с ребёнком и поэтому на данное место был приставлен ещё один стул
    table(guests, chairs, tableware, plates);

    later();
    tableware[1][2] = "fork, knife"; //  С третьего места во втором ряду в неизвестном направлении была украдена ложка.
    table(guests, chairs, tableware, plates);

    later();
    tableware[0][0] = "fork, knife, dessert spoon"; //После этого одна из VIP персон (любая) поделилась своей ложкой с тем у кого она пропала, а сам стал есть суп десертной.
    tableware[1][2] = "fork, spoon, knife";
    table(guests, chairs, tableware, plates);

    later();
    plates[0][0] = "soup plate, second plate"; // За ненадобностью официант забрал у него одну десертную тарелку, ибо есть десерт ложкой, которая побывала уже в супе - не комильфо.
    table(guests, chairs, tableware, plates);


    return 0;
}
