/*Запишите подробную информацию о киноленте в виде JSON-файла.
 * Выберите понравившуюся вам картину на любимом портале, проанализируйте информацию о ней и составьте JSON-словарь.

В информации должны присутствовать:
 страна и дата создания киноленты,
 студия, которая вела съёмки,
 автор сценария, режиссёр и продюсер киноленты.
 Обязательно добавьте информацию обо всех главных действующих лицах и тех актёрах, которые их сыграли.*/

#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main() {
    json info = {
            {"Name", "Back to the Future"},
            {"Country", "USA"},
            {"Year", 1985},
            {"Studio", "Universal"},
            {"Writer", "Robert Zemeckis, Bob Gale"},
            {"Producer", "Robert Zemeckis"},
            {"Director", "Robert Zemeckis"},
            {"Starring",{
                    {"Marty McFly", "Michael J. Fox"},
                    {"Emmett Doc Brown", "Christopher Lloyd"}
            }}
    };

    std::ofstream file ("../info.json");
    if(file.is_open())
    {
        file << info;
    }
    else
    {
        std::cout << "Coud not open the file" << std::endl;
    }
    file.close();
    return 0;
}
