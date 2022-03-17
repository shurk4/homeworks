#include <iostream>
void reverce(int *arr, int arrSize){
    for(int i = 0; i < arrSize/2; i++){
        std::swap(arr[i], arr[arrSize - i -1]);
    }
}

void print(int *arr, int arrSize){
    std::cout << "Reversed array: ";
    for(int i = 0; i < arrSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[]{1,2,3,4,5,6,7,8,9,10},
        arrSize = sizeof(arr) / sizeof(int);

    reverce(arr, arrSize);
    print(arr, arrSize);

    return 0;
}
