#include <iostream>
#include <cmath>
#include <iomanip>

int input (int x){
    do{
        std::cin >> x;
        if(x < 0) std::cout << "Wrong input! Try again:\n";
    } while(x < 0);
    return x;
}

int setFract(int x){
    int fract = 0;
    while (x != 0) {
        fract++;
        x /= 10;
    }
    return fract;
}

int main() {
    int a, b;
    double c;

    std::cout << "Enter the integer part of the number:\n";
    std::cin >> a;
    std::cout << "Enter the fractional part of the number:\n";
    b = input(b);

    int fract = setFract(b);

    if(a < 0) b *= -1;

    c = (double) a + (double) b / pow(10, fract);
    std::cout << std::fixed << std::setprecision(fract) << c << std::endl;

    return 0;
}
