#include <iostream>
int arr1[4][4], arr2[4][4];

void matrixFill(int arr[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) std::cin >> arr[i][j];
    }
}

void arrCompare(int arr1[4][4], int arr2[4][4]) {
    bool equal = true;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(arr1[i][j] != arr2[i][j]){
                equal = false;
                break;
            }
        }
        if(!equal) break;
    }
    std::cout << (equal ? "Equal" : "Not equal");
}

int main() {
    std::cout << "Equality of matrices\n";

    std::cout << "Fill in the matrix 1\n";
    matrixFill(arr1);

    std::cout << "Fill in the matrix 2\n";
    matrixFill(arr2);

    arrCompare(arr1, arr2);
    return 0;
}
