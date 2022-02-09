#include <iostream>
int matrix[4][4];

void matrixFill(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) std::cin >> matrix[i][j];
    }
}

void matrixTransf(){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i != j) matrix[i][j] = 0;
        }
        std::cout << "\n";
    }
}
void matrixPrint(){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
}

int main() {
    std::cout << "Fill in the matrix:\n";
    matrixFill();
    matrixPrint();
    matrixTransf();
    matrixPrint();
    return 0;
}
