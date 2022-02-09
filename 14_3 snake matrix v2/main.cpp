#include <iostream>

int arr[5][5];

void matrixFill(){
    int reverse = 1, col = 0, num = 0;

    for(int i = 0; i < 5; i++){
        int j = 0;
        while(j < 5 && j > -5) {
            arr[i][col] = num;
            num++;
            j += reverse;
            col += reverse;
        }
        reverse = -reverse;
        col += reverse;
    }
}

void matrixPrint(){
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
