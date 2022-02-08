#include <iostream>

int main() {
    int numbers[15] = {114,111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};

    for (int i = 0; i < 15; i++) {
        for (int j = i + 1; j < 15 ; j++) {
            if (numbers[i] == numbers[j]) {
                std::cout << numbers[j] << "\n";
                break;
            }
        }
    }


    return 0;
}
