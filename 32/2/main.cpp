#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void createJson ()
{
    json info = {
            {"Back to the Future" ,{
                                           {"Name", "Back to the Future"},
                                           {"Country", "USA"},
                                           {"Year", 1985},
                                           {"Studio", "Universal"},
                                           {"Writer", "Robert Zemeckis, Bob Gale"},
                                           {"Producer", "Robert Zemeckis"},
                                           {"Director", "Robert Zemeckis"},
                                           {"Starring",{
                                                               {"Michael J. Fox", "Marty McFly" },
                                                               {"Christopher Lloyd", "Emmett 'Doc' Brown"}
                                                       }
                                           }
                                   }},

            {"Police Academy" ,{
                                           {"Name", "Police Academy"},
                                           {"Country", "USA"},
                                           {"Year", 1984},
                                           {"Studio", "Warner Bros"},
                                           {"Writer", "Neal Israel, Pat Proft"},
                                           {"Producer", "Paul Maslansky"},
                                           {"Director", "Hugh Wilson"},
                                           {"Starring",{
                                                               {"Steve Guttenberg", "Carey Mahoney"},
                                                               {"Kim Cattrall", "Karen Thompson"},
                                                               {"Bubba Smith", "Moses Hightower"}
                                                       }
                                           }
                                   }},
            {"The Shawshank Redemption" ,{
                                       {"Name", "The Shawshank Redemption"},
                                       {"Country", "USA"},
                                       {"Year", 1994},
                                       {"Studio", "Columbia Pictures"},
                                       {"Writer", "Stephen King"},
                                       {"Producer", "Niki Marvin"},
                                       {"Director", "Frank Darabont"},
                                       {"Starring",{
                                                           {"Tim Robbins", "Andy Dufresne"},
                                                           {"Morgan Freeman", "Ellis Boyd Redding"}
                                                   }
                                       }
                               }},
            {"Now You See Me" ,{
                                        {"Name", "Now You See Me"},
                                        {"Country", "USA"},
                                        {"Year", 2013},
                                        {"Studio", "Summit Ente, Edward Ricourt"},
                                        {"Producer", "Alex Kurtzman, Roberto Orci, Bobby Cohen"},
                                        {"Director", "Louis Leterrier"},
                                        {"Starring",{
                                                            {"Woody Harrelson", "Merritt McKinney"},
                                                            {"Morgan Freeman", "Thaddeus Bradley"}
                                                    }
                                        }
                                }},
            {"Bicentennial Man" ,{
                                       {"Name", "Bicentennial Man"},
                                       {"Country", "USA"},
                                       {"Year", 1999},
                                       {"Studio", "Walt Disney Studios"},
                                       {"Producer", "Wolfgang Petersen, "
                                                    "Gail Katz, "
                                                    "Laurence Mark, "
                                                    "Neal Miller, "
                                                    "Chris Columbus, "
                                                    "Mark Radcliffe, "
                                                    "Michael Barnathan"},
                                       {"Director", "Chris Columbus"},
                                       {"Starring",{
                                                           {"Robin Williams", "Andrew Martin"},
                                                           {"Sam Neill", "Richard 'Sir' Martin"},
                                                   }
                                       }
                               }}
    };

    std::ofstream file ("../info.json");
    if(file.is_open())
    {
        file << info;
    }
    else
    {
        std::cout << "Coud not open the file!" << std::endl;
    }
    file.close();
}

void actorFind(json& _base, std::string& _key)
{
    bool found = false;
    for (auto it = _base.begin(); it != _base.end(); ++it)
    {
        if(it.value()["Starring"].contains(_key))
        {
            found = true;
            std::cout << "Film: " << it.key() << std::endl;
            std::cout << "Role: " << it.value()["Starring"][_key] << std::endl << std::endl;
        }
    }
    if(!found)
    {
        std::cout << "Not found!" << std::endl;
    }
}

int main() {
    createJson();
    std::string input = "Morgan Freeman";

    json base;

    std::ifstream file ("../info.json");

    file >> base;
    file.close();

    actorFind(base, input);

    do {
        std::cout << "Enter the actor's name or \"q\" for exit:" << std::endl;
        std::getline(std::cin, input);
        if(input == "q")
        {
            std::cout << "Bye!" << std::endl;
        }
        else
        {
            actorFind(base, input);
        }
    } while (input != "q");

    return 0;
}
