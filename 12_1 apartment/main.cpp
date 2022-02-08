#include <iostream>

int main() {
    std::string residents[10];
    int apartNum[3];

    for (int i = 0 ; i < 10; i++) {
        std::cout << "Enter the last name of resident from apartment " << i + 1 << ": ";
        std::cin >> residents[i];

    }

    for (int i = 0 ; i < 3 ; i++) {
        std::cout << "Enter " << i + 1 << " number of apartments: ";
        std::cin >> apartNum[i];
        if (apartNum[i] < 1 || apartNum[i] > 10) {
            std::cout << "Wrong input! Try again: \n";
            i--;
        }
    }

    for (int i = 0; i < 3 ; i++) {
        std::cout << "Apartment " << apartNum[i] << " - " << residents[apartNum[i] - 1] << "\n";
    }
    return 0;
}
