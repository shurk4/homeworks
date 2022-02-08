#include <iostream>

int main() {
    float numbers[15], result[15];
    float minNum = 0, maxNum = 0;

    std::cout << "Input 15 numbers\n";
    for (int i = 0; i < 15 ; i++) {
        std::cout << "Input number " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    for (int i = 0; i < 15 ; i++) {
        if (numbers[i] > maxNum) maxNum = numbers[i];
    }

    for (int i = 0; i < 15; i++) {
        minNum = maxNum;
        for (int j = 0; j < 15; j++) {
            if (numbers[j] < minNum && (i == 0 || numbers[j] > result[i - 1])) minNum = numbers[j];
        }
        result[i] = minNum;
    }

    for (int i = 0; i < 15; i++) std::cout << result[i] << " ";

    return 0;
}
