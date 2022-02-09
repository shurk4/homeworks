#include <iostream>

int arr[5][5]{0};

void matrixFill(){
    int num = 0;

    for(int i = 0; i < 5; i++){
        if(i % 2 == 0) {
            for (int j = 0; j < 5; j++) {
                arr[i][j] = num;
                num++;
            }
        } else {
            for (int j = 4; j >= 0; j--) {
                arr[i][j] = num;
                num++;
            }
        }
    }
}

void matrixPrint() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) std::cout << arr[i][j] << "\t";
        std::cout << "\n";
    }
}

int main() {
    matrixFill();
    matrixPrint();
    return 0;
}
