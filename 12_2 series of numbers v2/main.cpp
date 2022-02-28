#include <iostream>

int main() {
    int numbers[15] = {114,111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};
    int summBase = 0, summNum = 0;
    int x = 105;

    for(int i = 0; i < 14; i++){
        summBase += x + i;
    }

    for(int i = 0; i < 15; i++){
        summNum += numbers[i];
    }

    std::cout << summNum - summBase << std::endl;
    return 0;
}