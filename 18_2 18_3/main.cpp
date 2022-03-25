#include <iostream>

int jump(int target = 3, int jumpMax = 3)
{
    int tmp = 0;

    if (target == 0) return 1;

    for (int i = 1; i <= jumpMax; ++i) {
        if(target - i < 0) break;
        tmp += jump(target - i, jumpMax);
    }

    return tmp;
}

int main() {
    int target,
        jumpMax;

    std::cout << "Enter the target number of the ladder step or 0 for default(task 18_2): ";
    std::cin >> target;
    if(target != 0) {
        std::cout << "Enter the maximum jump length or 0 for default: ";
        std::cin >> jumpMax;
    }

    if(target == 0) std::cout << jump() << std::endl;
    else if(jumpMax == 0) std::cout << jump(target) << std::endl;
    else std::cout << jump(target, jumpMax) << std::endl;
}