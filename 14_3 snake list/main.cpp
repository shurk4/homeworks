#include <iostream>

int main() {
    int arr[5][5]{0};
    int num = -1;
    for(int i = 0; i < 5; i++){
        if(i % 2 == 0) {
            for (int j = 0; j < 5; j++) {
                num++;
                arr[i][j] = num;
            }
        } else {
            for (int j = 4; j >= 0; j--) {
                num++;
                arr[i][j] = num;
            }
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++){
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }
    return 0;
}
