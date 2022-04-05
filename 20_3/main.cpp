/*Реализуйте простую симуляцию игры в рыбалку.
В исходном текстовом файле реки (river.txt) задаётся список из видов рыб, которые можно в ней поймать.
Рыбок может быть сколько угодно, разных видов. Виды при этом могут повторяться.

В начале программы пользователь указывает, какую именно рыбу он сейчас будет ловить — вид этой рыбы.
После этого из первого файла друг за другом осуществляется чтение его содержимого, вид за видом.
Если на отдельных шагах вид совпал с указанным пользователем, в выходной файл basket.txt (корзинка) записывается этот вид.

В конце программы показывается, сколько было поймано рыб за текущую ловлю.
Программу можно запускать несколько раз, при этом уже пойманные рыбы должны сохраняться в файле-корзинке.*/


#include <iostream>
#include <fstream>

// Ввод
void input(std::string& in){
    std::cout << "Enter the name of the fish or 0 to exit:" << std::endl;
    std::cin >> in;
}

// поиск рыбы и запись в корзину
void fishing(std::string& fish){
    std::cout << "Catching " << fish << "..." << std::endl;

    std::ifstream river("..\\river.txt");
    if (!river.is_open()){
        std::cout << "Could not open the river file";
        fish = "1";
        return;
    } else {
        bool caught = false;
        while(!river.eof()){
            std::string temp;
            river >> temp;
            if(temp == fish) {
                std::ofstream basket("..\\basket.txt", std::ios::app);
                if(!basket.is_open()){
                    std::cout << "Could not open the basket file";
                    fish = "1";
                    return;
                } else {
                    std::cout << "The " << fish << " is caught." << std::endl;
                    caught = true;
                    basket << fish << std::endl;
                    basket.close();
                }
            }
        }
        river.close();
        if(!caught) {
            std::cout << fish << " not caught" << std::endl;
        }
    }
}

// Вывод результатов
void result(){
    std::ifstream basket("..\\basket.txt", std::ios::app);
    if(!basket.is_open()){
        std::cout << "Could not open the basket file";
        return;
    } else {
        std::cout << "-----------------" << std::endl;
        std::cout << "  Total caught:  " << std::endl;
        std::cout << "-----------------" << std::endl;
        while(!basket.eof()){
            std::string temp;
            basket >> temp;
            std::cout << temp << std::endl;
        }
    }
}

int main() {
    std::string fish;

    do {
        input(fish);

        if(fish == "0"){
            result();
        } else {
            fishing(fish);
        }
    } while (fish != "0" && fish != "1");

    return 0;
}
