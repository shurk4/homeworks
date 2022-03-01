#include <iostream>
#include <vector>
int maxSize = 20;

void vecPrint(std::vector<int> vec){
    for (int i = 0; i < maxSize; i++)
    {
        if (vec.size() <= maxSize && i < vec.size())
        {
            std::cout << vec[i] << (i == vec.size() - 1 ? "\n" : ", ");
        }
        else if (vec.size() > maxSize)
        {
            std::cout << vec[vec.size() - maxSize + i] << (vec.size() - maxSize + i == vec.size() - 1 ? "\n" : ", ");
        }
        else break;
    }
}

int main() {
    std::vector<int> nums(0);
    int num;

    do {
        std::cout << "Enter the humber: ";
        std::cin >> num;

        if (num == -1)
            vecPrint(nums);
        else if (num == -2) break;
        else {
            nums.push_back(num);
        }
    } while (num != -2 || num < -2);

    return 0;
}
