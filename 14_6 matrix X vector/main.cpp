#include <iostream>
int matrix[4][4];
int v[4], r[4];

void matrixFill(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) std::cin >> matrix[i][j];
    }
}

void vectorFill() {
    for(int i = 0; i < 4; i++){
        std::cin >> v[i];
    }
}

void matrixPrint(){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
}

void vectorPrint(int vector[4]){
    for(int i = 0; i < 4; i++) std::cout << vector[i] << "\t";
    std::cout << "\n";
}

void mult(){
        for(int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                r[i] += matrix[i][j] * v[j];
            }
        }
}

int main() {
    std::cout << "Fill in the matrix:\n";
    matrixFill();

    std::cout << "Fill in the vector:\n";
    vectorFill();

    std::cout << "==============================\n";
    matrixPrint();

    std::cout << "==============================\n";
    vectorPrint(v);

    mult();
    std::cout << "==============================\n";
    vectorPrint(r);
    return 0;
}
