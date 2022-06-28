#include <iostream>
#include <cmath>

enum colors
{
    RED,
    BLUE,
    GREEN,
    NONE
};

class Figure
{
public:

    std::string type;
    double centerX;
    double centerY;
    double sizeX;
    double sizeY;
    double area;
    colors color;

    void setBasic(std::string figureType)
    {
        type = figureType;
        std::string input;
        std::cout << "Enter the coordinates of the " << type << " center" << std::endl;
        std::cout << "X: ";
        std::cin >> centerX;
        std::cout << "Y: ";
        std::cin >> centerY;

        std::cout << "Enter the color of figure(red, blue, green, none):" << std::endl;
        std::cin >> input;
        if(input == "red")
        {
            color = RED;
        }
        if(input == "blue")
        {
            color = BLUE;
        }
        if(input == "green")
        {
            color = GREEN;
        }
        if(input == "none")
        {
            color = NONE;
        }
    }

    void print(double inFieldX, double inFieldY)
    {
        std::cout << "-------------------------" << std::endl;
        std::cout << "The " << type << " area: " << area << std::endl;
        std::cout << "Color:\t\t";
        if(color == RED)
        {
            std::cout << "red";
        }
        if(color == BLUE)
        {
            std::cout << "blue";
        }
        if(color == GREEN)
        {
            std::cout << "green";
        }
        if(color == NONE)
        {
            std::cout << "none";
        }
        std::cout << std::endl;
        std::cout << "Rectangular field size:" << std::endl;
        std::cout << "X:\t\t" << inFieldX << std::endl;
        std::cout << "Y:\t\t" << inFieldY << std::endl;
        std::cout << "Starting coordinates of rectangular field" << std::endl;
        std::cout << "X:  " <<  centerX - (inFieldX / 2) << " Y:  " << centerY - (inFieldY / 2) << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
};

class Circle:Figure
{
public:

    Circle()
    {
        setBasic("circle");
        std::cout << "Enter the circle radius:";
        std::cin >> sizeX;
//        area = atan(1) * sizeX * sizeX;  ошибка
        area = (atan(1) * 4) * (sizeX * sizeX);
    }

    void getResult()
    {
        print(sizeX * 2, sizeX * 2);
    }
};

class Square:Figure
{
public:

    Square()
    {
        setBasic("square");
        std::cout << "Enter the length of the square edge:";
        std::cin >> sizeX;
        area = sizeX * sizeX;
    }

    void getResult()
    {
        print(sizeX, sizeX);
    }
};

class Triangle:Figure
{
    double fieldX;
    double fieldY;

public:

    Triangle()
    {
        setBasic("triangle");
        std::cout << "Enter the length of the triangle edge :";
        std::cin >> sizeX;
        fieldX = sizeX;
        fieldY = (sizeX * std::sqrt(3)) / 2;
//        fieldY = sqrt((sizeX * sizeX) - (pow(sizeX/2,2)));
        area = sizeX * sizeX * std::sqrt(3) / 4;
    }

    void getResult()
    {
        print(fieldX, fieldY);
    }

};

class Rectangle:Figure
{
public:
    Rectangle()
    {
        setBasic("rectangle");
        std::cout << "Enter the size of the rectangle:" << std::endl;
        std::cout << "X: ";
        std::cin >> sizeX;
        std::cout << "Y: ";
        std::cin >> sizeY;
        area = sizeX * sizeY;
    }

    void getResult()
    {
        print(sizeX, sizeY);
    }
};

int main() {
    std::string input;

    std::cout << "Enter the figure type:" << std::endl;
    std::cin >> input;
    if(input == "circle")
    {
        Circle *circle = new Circle;
        circle->getResult();
    }
    if(input == "square")
    {
        Square *square = new Square;
        square->getResult();
    }
    if(input == "triangle")
    {
        Triangle *triangle = new Triangle;
        triangle->getResult();
    }
    if(input == "rectangle")
    {
        Rectangle *rectangle = new Rectangle;
        rectangle->getResult();
    }



    return 0;
}
