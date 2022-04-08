/*Требуется реализовать упрощённую симуляцию работы банкомата.
В банкомате могут храниться только бумажные купюры номиналом от 100 до 5000 рублей.
Максимально в банкомате может храниться только 1000 купюр. Все они записываются в отдельный файл.
У банкомата, как у устройства, две основных операции — снятие денег пользователем и наполнение деньгами инкассаторами банка.

Наполнение банкомата происходит, если при старте программы в консоль вводится символ плюс “+”.
Количество купюр рассчитывается так, чтобы банкомат был заполнен полностью. Все купюры при этом выбираются случайным образом.

Если на старте программы в консоль вводится минус (“-”), то симулируется снятие пользователем денег.
Пользователь указывает сумму с точностью до 100 рублей.
Мы будем считать, что каждый клиент обладает неограниченным балансом в системе и теоретически может снять любую сумму.
На практике, если данная сумма не может быть снята из-за отсутствия подходящих денег в машине, показывается сообщение, что эта операция невозможна.

После выполнения любой из операций программа завершает выполнение. Состояние банкомата должно храниться в отдельном бинарном файле, автономно.

Советы и рекомендации

        Вы можете хранить массив купюр целиком, помечая отсутствующие позиции нулями.*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

// чтение последнего состояния -------------------------------------
void stateRead(std::vector<int>& quantity, int& result) {
    std::ifstream file("..\\state.bin", std::ios::binary);
    bool empty = false;
    if(!file.is_open()) {
        std::cout << "Cannot open the file!!!" << std::endl;
        return;
    }

    if (file.peek() == EOF){
        std::cout << "ATM is empty!" << std::endl;
        result = -1;
    } else {
        for (int i = 0; i < quantity.size(); i++) {
            file.read((char*)&quantity[i], sizeof(quantity[i]));
        }
        if ((quantity[0] == 0 && quantity[1] == 0 && quantity[2] == 0 && quantity[3] == 0)){
            std::cout << "ATM is empty!" << std::endl;
            result = -1;
        }
        file.close();
    }
}

// запись состояния ------------------------------------------------
void stateSave(std::vector<int>& quantity) {
    std::ofstream file("..\\state.bin", std::ios::binary);
    if(!file.is_open()){
        std::cout << "Cannot open the file!!!" << std::endl;
        return;
    }
    for(int i = 0; i < quantity.size(); i++){
        file.write((char*)&quantity[i], sizeof(quantity[i]));
    }
    file.close();
}

// подсчёт остатка банкнот ------------------------------------------
void remains (std::vector<int>& value, std::vector<int>& quantity, int& result){
    std::cout << "===================================================" << std::endl;
    if(result == -1){
        return;
    } else {
        result = 0;
        for (int i = 0; i < value.size(); i++) {
            std::cout << value[i] << " RUB " << quantity[i] << " pcs" << std::endl;
            result += quantity[i];
        }
        std::cout << "ATM occupancy " << result << " / 1000" << std::endl;
    }
}

// заполнение --------------------------------------------------------
void infill (std::vector<int>& quantity, int val){
    std::srand(std::time(nullptr));
    int summ = val,
        i = 0;
    while (summ < 1000){
        int temp = std::rand() % ((1000 - val) / 4);
        quantity[i] += temp;
        summ += temp;
        if(summ > 1000) quantity[i] -= (summ - 1000);
        i++;
        if (i == quantity.size()){
            i = 0;
        }
    }
}

// проверка ввода действия -----------------------------------------------
bool actionCheck(std::string& action){
    if (action == "+" || action == "-") {
        return true;
    } else {
        return false;
    }
}

// проверка ввода суммы -----------------------------------------------
bool inputCheck(std::string& action){
    for(int i = 0; i < action.length(); i++) {
        if(action[i] < '0' || action[i] > '9'){
            return false;
        }
    }

    int temp = std::stoi(action);
    if(temp % 100 != 0){
        return false;
    }

    return true;
}

// ввод действия --------------------------------------------------------
void inputAct(std::string& action){
    do {
        std::cout << "Enter \"-\" to withdraw cash or \"+\" to fill the ATM: ";
        std::getline(std::cin, action);

        if(!actionCheck(action)) {
            std::cout << "Wrong input! Try again:" << std::endl;
        }
    } while (!actionCheck(action));
}
// ввод суммы ------------------------------------------------------------
void inputMoney(std::string& action){
    do {
        std::cout << "enter the amount a multiple of 100: " << std::endl;
        std::getline(std::cin, action);

        if(!inputCheck(action)) {
            std::cout << "Wrong input! Try again:" << std::endl;
        }
    } while (!inputCheck(action));
}

// Выдача наличных -------------------------------------------------------
void cash(std::string& action, std::vector<int>& value, std::vector<int>& quantity){
    std::stringstream result;
    std::vector<int> tempQuantity(4,0);
    int sum = std::stoi(action);
    for(int i = 0; i < quantity.size(); i++){
        int temp;
        if(sum > value[i] && quantity[i] != 0) {
            temp = sum / value[i];
            if(temp < quantity[i]){
                result << value[i] << " RUB " << temp << " pcs" << std::endl;
                sum %= value[i];
                tempQuantity[i] += temp;
            } else {
                result << value[i] << " RUB " << quantity[i] << " pcs" << std::endl;
                sum -= value[i] * quantity[i];
                tempQuantity[i] = quantity[i];
            }
        }
    }
    if (sum == 0) {
        std::cout << "ATM issued:" << std::endl;
        std::cout << result.str() << std::endl;
        for (int j = 0; j < quantity.size(); j++){
            quantity[j] -= tempQuantity[j];
        }
    } else {
        std::cout << "Not enough money in the ATM" << std::endl;
    }
}

// main -------------------------------------------------------------------
int main() {
    std::vector<int> faceValue{5000, 1000, 500, 100};
    std::vector<int> quantity(4, 0);
    std::string action = "";
    int fullnes = 0;
    stateRead(quantity, fullnes);
    remains(faceValue, quantity, fullnes);

    inputAct(action);

    if (action == "+"){
        infill(quantity, fullnes);
        remains(faceValue, quantity, fullnes);
    } else if (action == "-" && fullnes > 0){
        inputMoney(action);
        cash(action, faceValue, quantity);
    } else if (fullnes == -1){
        std::cout << "Not enough money in the ATM" << std::endl;
        return 1;
    }

    stateSave(quantity);
    return 0;
}
