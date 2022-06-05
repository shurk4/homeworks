#include <iostream>
#include <cmath>

enum colors
{
    RED = 1,
    BLUE = 2,
    GREEN = 4,
    NONE = 6
};

class Circle
{
public:

    double r;

    void setCircleParam()
    {
        std::cout << "Enter the circle radius:";
        std::cin >> r;
    }

    void getCircleArea()
    {
        std::cout << "The circle area: " << atan(1) * r * r << std::endl;
    }

    void circleRectangularField()
    {
        std::cout << "Rectangular field size" << std::endl;
        std::cout << "X: " << r * 2 << std::endl;
        std::cout << "Y: " << r * 2 << std::endl;
    }
};

class Square
{
public:

    double edgeSize;

    void setSquareParam()
    {
        std::cout << "Enter the length of the the square edge:";
        std::cin >> edgeSize;
    }

    void getSquareArea()
    {
        std::cout << "The square area: " << edgeSize * edgeSize << std::endl;
    }

    void squareRectangularField()
    {
        std::cout << "Rectangular field size" << std::endl;
        std::cout << "X: " << edgeSize << std::endl;
        std::cout << "Y: " << edgeSize << std::endl;
    }
};

class Triangle
{
public:

    double edgeSize;
    double fieldX;
    double fieldY;

    void setTriangleParam()
    {
        std::cout << "Enter the length of the triangle edge :";
        std::cin >> edgeSize;
        fieldX = edgeSize / 2;
        fieldY = (edgeSize * std::sqrt(3)) / 2;
    }

    void getTriangleArea()
    {
        std::cout << "The triangle area: " << edgeSize * edgeSize * std::sqrt(3) / 4 << std::endl;
    }

    void triangleRectangularField()
    {
        std::cout << "Rectangular field size" << std::endl;
        std::cout << "X: " << fieldX << std::endl;
        std::cout << "Y: " << fieldY << std::endl;
    }
};

class Rectangle
{
public:

    double sizeX;
    double sizeY;

    void setRectangleParam()
    {
        std::cout << "Enter the size of the rectangle:" << std::endl;
        std::cout << "X: ";
        std::cin >> sizeX;
        std::cout << "Y: ";
        std::cin >> sizeY;
    }

    double getRectangleArea()
    {
        std::cout << "The rectangle area: " << sizeX * sizeY << std::endl;
    }

    void rectangleRectangularField()
    {
        std::cout << "Rectangular field size" << std::endl;
        std::cout << "X: " << sizeX << std::endl;
        std::cout << "Y: " << sizeY << std::endl;
    }
};

class Figure:public Circle, public Square, public Triangle, public Rectangle
{
    std::string type;

public:

    Figure(std::string &input)
    {
        type = input;
        setGeneralParam();

        if(type == "circle")
        {
            setCircleParam();
        }
        if(type == "square")
        {
            setSquareParam();
        }
        if(type == "triangle")
        {
            setTriangleParam();
        }
        if(type == "rectangle")
        {
            setRectangleParam();
        }
    }

    std::string input;
    double centerX;
    double centerY;
    colors color;

    void setColor()
    {
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

    void setCenter()
    {
        std::cout << "Enter the coordinates of the center" << std::endl;
        std::cout << "X: ";
        std::cin >> centerX;
        std::cout << "Y: ";
        std::cin >> centerY;
    }

    void setGeneralParam()
    {
        setColor();
        setCenter();
    }

    void getColor()
    {
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
    }

    void getStartPos(double x, double y)
    {
        std::cout << "Starting coordinates of rectangular field" << std::endl;
        std::cout << "X: " <<  centerX - (x / 2) << " Y: " << centerY - (y / 2) << std::endl;
    }

    void result()
    {
        std::cout << "----------------------" << std::endl;
        std::cout << "Figure type:\t" << type << std::endl;

        getColor();

        if(type == "circle")
        {
            getCircleArea();
            circleRectangularField();
            getStartPos(r * 2, r * 2);
        }
        if(type == "square")
        {
            getSquareArea();
            squareRectangularField();
            getStartPos(Square::edgeSize, Square::edgeSize);
        }
        if(type == "triangle")
        {
            getTriangleArea();
            triangleRectangularField();
            getStartPos(fieldX, fieldY);
        }
        if(type == "rectangle")
        {
            getRectangleArea();
            rectangleRectangularField();
            getStartPos(Rectangle::sizeX, Rectangle::sizeY);
        }
        std::cout << "----------------------" << std::endl;
    }
};

int main() {
    std::string input;

    std::cout << "Enter the figure type:" << std::endl;
    std::cin >> input;

    Figure *figure = new Figure(input);

    figure->result();

    delete figure;

    return 0;
}
