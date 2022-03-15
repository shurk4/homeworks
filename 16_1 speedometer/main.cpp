#include <iostream>
#include <iomanip>
#include <sstream> // Надо подключать? Работает без неё...


bool stopped(float speed) {
    return (speed <= 0 + 0.01);
}

bool maxSpeed(float speed) {
    return (speed >= 150 - 0.01);
}

int main() {
    float speed = 0.f;

    do {
        std::stringstream speedOut;
        float d = 0.f;

        speedOut << "Speed: " << std::fixed << std::setprecision(1) << speed << " km/h";

        std::cout << speedOut.str() << std::endl;

        std::cout << "Enter the speed difference:";
        std::cin >> d;
        speed += d;

        if (maxSpeed(speed)) {
            speed = 150.f;
            std::cout << "Maximum speed reached!" << std::endl;
        }

        if(stopped(speed)) {
            std::cout << "The car is stopped!" << std::endl;
        }
    } while (!stopped(speed));

    return 0;
}
