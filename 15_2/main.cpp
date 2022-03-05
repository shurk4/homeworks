#include <iostream>
#include <vector>

void masInput(std::vector<int> &mas, int &size){
    int num;
    do {
        std::cout << "Input size of array: ";
        std::cin >> size;
        if(size < 1) std::cout << "Wront input!\n";
    } while (size < 1);

    std::cout << "Input " << size << " numbers:\n";
    for(int i = 0; i < size; i++) {
        std::cin >> num;
        mas.push_back(num);
    }
}

void result(std::vector<int> mas, int sum){
    for(int i = 0; i < mas.size(); i++){
        int j = i + 1;
        while(mas[i] + mas[j] != sum && j < mas.size()) j++;
        if (mas[i] + mas[j] == sum) {
            std::cout << mas[i] << " " << mas[j] << "\n";
            break;
        }
    }
}

int main() {
    int size, sum;
    std::vector <int> mas;

    masInput(mas, size);

    std::cout << "Input sum:\n";
    std::cin >> sum;

    result(mas, sum);

    return 0;
}
