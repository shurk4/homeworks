#include <iostream>
#include <vector>

int maxSize = 20;

void vecPrint(std::vector<int> vec, int counter){
        if(vec[counter] == -3) {
            for (int i = 0; i < counter; i++)
                std::cout << vec[i] << " ";
            std::cout << "\n";
        } else {
            for (int i = counter; i < maxSize; i++)
                std::cout << vec[i] << " ";
            for (int i = 0; i < counter; i++)
                std::cout << vec[i] << " ";
            std::cout << "\n";
        }
}

int main() {
    std::vector<int> nums(maxSize, -3);
    int counter = 0;
    int num;

    do {
        std::cout << "Enter the humber: ";
        std::cin >> num;

        if (num == -1)
            vecPrint(nums, counter);
        else if (num == -2) break;
        else {
            std::cout << "\n";
            nums[counter] = num;
            counter++;
            if(counter == maxSize) counter = 0;
        }
    } while (num != -2 || num < -2);

    return 0;
}
