#include <iostream>
#include <vector>

int maxSize = 20;

void vecPrint(std::vector<int> vec, int counter){
    if (counter <= maxSize)
    {
        for(int i = 0; i < counter; i++)
            std::cout << vec[i] << " ";
        std::cout << "\n";
    }
    else if (counter > maxSize)
    {
        for (int i = counter % maxSize; i < maxSize; i++)
            std::cout << vec[i] <<" ";

        for (int i = 0; i < counter % maxSize; i++)
            std::cout << vec[i] << " ";

        std::cout << "\n";
    }
}

int main() {
    std::vector<int> nums(maxSize);
    int counter = 0;
    int num;

    do {
        std::cout << "Enter the humber: ";
        std::cin >> num;

        if (num == -1)
            vecPrint(nums, counter);
        else if (num == -2) break;
        else {
            nums[counter % maxSize] = num;
            counter++;
        }
    } while (num != -2 || num < -2);

    return 0;
}
