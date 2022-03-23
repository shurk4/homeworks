#include <iostream>
#include <vector>

void swapvec (std::vector <int>& vec, int arr[], int size){
    for (int i = 0; i < size; i++) {
        std::swap(vec[i], arr[i]);
    }
}

void printVec (std::vector <int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void printArr (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};
    int size = sizeof(b) / sizeof(b[0]);

    swapvec(a, b, size);

    printVec(a);
    printArr(b, size);

    return 0;
}
