#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums;
    int num;

    do {
        std::cout << "Enter the humber: ";
        std::cin >> num;
        if (num == -1) for (int i = 0; i < nums.size(); i++)
            std::cout << nums[i] << (i == nums.size() - 1 ? "\n" : ", ");
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
