#include <iostream>
#include <vector>

int main() {
    int size, sum;
    do {
        std::cout << "Input size of massive: ";
        std::cin >> size;
        if(size < 1) std::cout << "Wront input!\n";
    } while (size < 1);
    std::vector <int> mas (size);

    std::cout << "Input " << size << " numbers:\n";
    for(int i = 0; i < size; i++)
        std::cin >> mas[i];

    std::cout << "Input sum:\n";
    std::cin >> sum;

    for(int i = 0; i < mas.size(); i++){
        int j = i + 1;
        while(mas[i] + mas[j] != sum && j < mas.size()) j++;
        if (mas[i] + mas[j] == sum) {
            std::cout << mas[i] << " " << mas[j] << "\n";
            break;
        }
    }
    return 0;
}
