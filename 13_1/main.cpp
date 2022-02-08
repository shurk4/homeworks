#include <iostream>
#include <vector>

std::vector<int> fill(int n) {
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        if (i < nums.size())
            std::cout << "Enter number " << i << ": ";
        std::cin >> nums[i];
    }
    return nums;
}

std::vector<int> result(std::vector<int> nums, int exc) {
    for (int i = 0; i < nums.size(); i++ ) {
        if (nums[i] == exc) {
            for (int j = i; j < nums.size(); j++) {
                if (j == nums.size() - 1) nums.pop_back();
                else {
                    nums[j] = nums[j + 1];
                };
            }
            i--;
        }
    }
    return nums;
}

int main() {
    int n, exc;
    std::vector<int> nums;

    do {
        std::cout << "How many numbers" << std::endl;
        std::cin >> n;
        if (n < 1) std::cout << "Wrong input!\n";
    } while (n < 1);

    nums = fill(n);

    std::cout << "Enter the exception number: ";
    std::cin >> exc;

    nums = result(nums, exc);

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << (i == nums.size() - 1 ? "\n" : ", ");
    }

    return 0;
}
