/*Реализуйте структуру двумерного математического вектора и основные операции над ним.
 * Обе координаты вектора (x и y) должны быть вещественными числами.

Вначале программы пользователь вводит команду, которая соответствует требуемой операции.
 Далее, в зависимости от операции, пользователь вводит её аргументы.
 Это могут быть как вектора, так и обычные, скалярные значения.
 В результате в стандартный вывод помещается результат. Это тоже может быть или вектор, или скаляр.

Реализуйте следующие операции в виде отдельных функций:

Сложение двух векторов — команда add.
Вычитание двух векторов — команда subtract.
Умножение вектора на скаляр — команда scale.
Нахождение длины вектора — команда length.
Нормализация вектора — команда normalize.*/


#include <iostream>
#include <vector>
#include <string>
#include <cmath>

bool operationCheck(std::string& input){
    if(input == "add" || input == "subtract" || input == "scale" || input == "length" || input == "normalize"){
        return true;
    }
    else {
        return false;
    }
}

void operationEror(){
    std::cout << "Wrong operation! Available operations: add, subtract, scale, length, normalize." << std::endl;
    std::cout << "Please try again:" << std::endl;
}

void vectorInput(std::vector<float>& vec){
    for(int i = 0; i < vec.size(); i++){
        std::cin >> vec[i];
    }
}

void result(std::vector<float>& vec, std::string& operation, float& result){
    std::cout << "Result of operation " << operation << ": (";
    if(operation != "length") {
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i];
            if (i != vec.size() - 1) {
                std::cout << ", ";
            }
        }
    }
    else {
        std::cout << result;
    }
    std::cout << ")" << std::endl;
}

void add(std::vector<float>& vec1, std::vector<float>& vec2){
    for(int i = 0; i < vec1.size(); i++){
        vec1[i] += vec2[i];
    }
}

void subtract(std::vector<float>& vec1, std::vector<float>& vec2){
    for(int i = 0; i < vec1.size(); i++){
        vec1[i] -= vec2[i];
    }
}

void length(std::vector<float>& vec, float& result){
    result = sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
}

void normalize(std::vector<float>& vec){
    float temp;
    length(vec, temp);
    temp *= temp;
    vec[0] = (vec[0] * vec[0] / temp) + (vec[1] * vec[1] / temp);
    vec.pop_back();
}

void scale(std::vector<float>& vec1, float& x){
    for(int i = 0; i < vec1.size(); i++){
        vec1[i] *= x;
    }
}

int main() {
    std::vector<float> vec1(2);
    std::vector<float> vec2(2);
    std::string operation;
    float scalar;

    do {
        std::cout << "Enter the operation: " << std::endl;
        std::cin >> operation;
        if (!operationCheck(operation)) {
            operationEror();
        }
    }while (!operationCheck(operation));

    std::cout << "Enter the vector 1: " << std::endl;
    vectorInput(vec1);

    if(operation != "length" && operation != "normalize") {
        if (operation != "scale") {
            std::cout << "Enter the vector 2: " << std::endl;
            vectorInput(vec2);
        } else {
            std::cout << "Enter the scalar: " << std::endl;
            std::cin >> scalar;
        }
    }

    if(operation == "add"){
        add(vec1, vec2);
    }
    if(operation == "subtract"){
        subtract(vec1, vec2);
    }
    if(operation == "scale"){
        scale(vec1, scalar);
    }
    if(operation == "length"){
        length(vec1, scalar);
    }
    if(operation == "normalize"){
        normalize(vec1);
    }


    result(vec1, operation, scalar);


    return 0;
}
