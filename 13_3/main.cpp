#include <iostream>
#include <vector>

void vecPrint(std::vector<int> vec){
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << (i == vec.size() - 1 ? "\n" : ", ");
}

int main() {
    std::vector<int> nums;
    int num;

    do {
        std::cout << "Enter the humber: ";
        std::cin >> num;
        if (num == -1)
            vecPrint(nums);
        else if (num == -2) break;
        else if (nums.size() < 20) nums.push_back(num);
        else {
            for (int i = 0; i < 19; i++){
                nums[i] = nums[i + 1];
            }
            nums[19] = num;
        }
    } while (num != -2 || num < -2);

    return 0;
}
