#include <iostream>
#include <vector>

int main() {
    int pSize, cSize;

    std::vector<float> price {2.5, 4.25, 3.0, 10.0};
    std::vector<int> cart{1, 1, 0, 3};
    float result = 0.f;

    for (int i = 0; i < cart.size(); i++) {
        result += price[cart[i]];
    }

    std::cout << result;

    return 0;
}
