#include <iostream>
#include <sstream>
#include <string>

int state,
    day = 0,
    currentTime = 0,
    insideTemp = 25,
    outsideTemp = 10,
    lightTempMax = 5000,
    lightTemp = lightTempMax,
    lightStep = (lightTemp - 2700) / 4;

std::string input,
        move,
        light;

enum switches {
    GENERAL = 1,
    OUTLETS = 2,
    INSIDE_LIGHT = 4,
    OUTSIDE_LIGHT = 8,
    HOME_HEATING = 16,
    WATER_SUPPLY_HEATING = 32,
    CONDITIONER = 64
};


bool winter(int temp){
    return (temp <= 0 || ((state & WATER_SUPPLY_HEATING) && temp < 5));
}
bool evening(int currentTime){
    return (currentTime >= 16 && currentTime < 20);
}
bool night(int currentTime){
    return ((currentTime >= 16 && currentTime < 24) || (currentTime >= 0 && currentTime < 5));
}
bool moveSensor(std::string &move){
    return (move == "YES" || move == "Yes" || move == "yes");
}
bool lightOn(std::string &light){
    return (!(state & INSIDE_LIGHT) && (light == "ON" || light == "On" || light == "on"));
}
bool lightOff(std::string &light){
    return ((state & INSIDE_LIGHT) && (light == "OFF" || light == "Off" || light == "off"));
}
bool insideHeating(float temp){
    return (temp < 22 || (state & HOME_HEATING && temp < 25));
}

bool insideCool(float temp){
    return (temp >= 30 || (state & CONDITIONER && temp > 25));
}

void statePrint() {
    std::cout << "==============================================" << std::endl;
    std::cout << "\tGENERAL\t\t\t" << ((state & GENERAL) ? "on\n" : "off\n");
    std::cout << "\tOUTLETS\t\t\t" << ((state & OUTLETS) ? "on\n" : "off\n");
    std::cout << "\tINSIDE LIGHT\t\t" << ((state & INSIDE_LIGHT) ? "on\n" : "off\n");
    if(state & INSIDE_LIGHT) std::cout << "\tINSIDE LIGHT TEMP\t" << lightTemp << std::endl;
    std::cout << "\tOUTSIDE LIGHT\t\t" << ((state & OUTSIDE_LIGHT) ? "on\n" : "off\n");
    std::cout << "\tHOME HEATING\t\t" << ((state & HOME_HEATING) ? "on\n" : "off\n");
    std::cout << "\tWATER SUPPLY HEATING\t" << ((state & WATER_SUPPLY_HEATING) ? "on\n" : "off\n");
    std::cout << "\tCONDITIONER\t\t" << ((state & CONDITIONER) ? "on\n" : "off\n");
}

void triggers(){
    if(evening(currentTime)){
        lightTemp -= lightStep;
    } else if(currentTime == 0){
        lightTemp = lightTempMax;
    }

    if(lightOn(light)){
        state |= INSIDE_LIGHT;
        std::cout << "\tThe inside light is on" << std::endl;
        std::cout << "   The inside lighting temperature is " << lightTemp << "k" << std::endl;
    }
    if(lightOff(light)){
        state &= (~INSIDE_LIGHT);
        std::cout << "\tThe inside light is off" << std::endl;
    }

    if(winter(outsideTemp) && !(state & WATER_SUPPLY_HEATING)){
        state |= WATER_SUPPLY_HEATING;
        std::cout << "\tThe water supply heating is on" << std::endl;
    }
    if(!winter(outsideTemp) && (state & WATER_SUPPLY_HEATING)) {
        state &= (~WATER_SUPPLY_HEATING);
        std::cout << "\tThe water supply heating is off" << std::endl;
    }

    if(night(currentTime) && moveSensor(move) && !(state & OUTSIDE_LIGHT)){
        state |= OUTSIDE_LIGHT;
        std::cout << "\tThe outside light is on" << std::endl;
    }
    if((!night(currentTime) || !moveSensor(move))&& (state & OUTSIDE_LIGHT)) {
        state &= (~OUTSIDE_LIGHT);
        std::cout << "\tThe outside light is off" << std::endl;
    }

    if(insideHeating(insideTemp) && !(state & HOME_HEATING)){
        state |= HOME_HEATING;
        std::cout << "\tThe home heating is on" << std::endl;
    }
    if(!insideHeating(insideTemp) && (state & HOME_HEATING)){
        state &= (~HOME_HEATING);
        std::cout << "\tThe home heating is off" << std::endl;
    }

    if(insideCool(insideTemp) && !(state & CONDITIONER)){
        state |= CONDITIONER;
        std::cout << "\tThe conditioner is on" << std::endl;
    }
    if(!insideCool(insideTemp) && (state & CONDITIONER)){
        state &= (~CONDITIONER);
        std::cout << "\tThe conditioner is off" << std::endl;
    }
}

// ================= MAIN
int main() {

    state |= GENERAL;
    state |= OUTLETS;

    std::cout << "==============================================" << std::endl;
    std::cout << "--------- Welcome to the smart home! ---------" << std::endl;

    //============ WHILE
    while(day < 2){
        std::stringstream inStream;

        std::cout << "==============================================" << std::endl;
        std::cout << "========|\t Time: \t" << currentTime << ":00\t     |========" << std::endl;
        std::cout << "==============================================" << std::endl;

        std::cout << "Enter the incoming data: " << std::endl;
        std::getline(std::cin, input); // outside temp, inside temp, move detect(yes/no), inside light(on/off)

        inStream << input;

        inStream >> outsideTemp >> insideTemp >> move >> light;
        triggers();

        statePrint();
        currentTime++;

        if(currentTime == 24) {
            currentTime = 0;
            day++;
        }
    }

    std::cout << "==================== BYE! =====================" << std::endl;
    return 0;
}