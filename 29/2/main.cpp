#include <iostream>
#include <cmath>

struct BoundingBoxDimensions
{
    double width = 0;
    double height = 0;
};

class Shape
{
public:
    BoundingBoxDimensions bbd;

    virtual double square() = 0; // — возвращает площадь конкретной фигуры;

    BoundingBoxDimensions dimensions() //  — размеры описывающего прямоугольника;
    {
        return bbd;
    }
    virtual std::string type() = 0; // — название конкретного типа, например, вернуть строку Triangle для класса Triangle;
};

class Circle : virtual public Shape
{
    double r;

public:

    Circle(double radius)
    {
        if(radius > 0)
        {
            r = radius;
            bbd.width = r * 2;
            bbd.height = r * 2;
        }
        else
        {
            std::cout << "Wrong radius!" << std::endl;
        }
    }

    virtual double square()
    {
        return (atan(1) * 4) * (r * r);
    }

    virtual std::string type()
    {
        return "Circle";
    }
};

class Rectangle : virtual public Shape
{
    double x;
    double y;

public:

    Rectangle(double sizeX, double sizeY)
    {
        if(sizeX > 0 && sizeY > 0)
        {
            x = sizeX;
            y = sizeY;
            bbd.width = sizeX;
            bbd.height = sizeY;
        }
        else
        {
            std::cout << "Invalid size parameters!" << std::endl;
        }
    }

    virtual double square()
    {
        return x * y;
    }

    virtual std::string type()
    {
        return "Rectangle";
    }
};

class Triangle : virtual public Shape
{
    double a;
    double b;
    double c;
    double p;

public:

    Triangle(double sizeA, double sizeB, double sizeC)
    {
        if(sizeA > 0 && sizeB > 0 && sizeC > 0)
        {
            a = sizeA;
            b = sizeB;
            c = sizeC;
            p = (a + b + c) / 2;
            bbd.height = (a * b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c)))) * 2;
            bbd.width = bbd.height;
        }
        else
        {
            std::cout << "Invalid size parameters!" << std::endl;
        }
    }

    virtual double square()
    {
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    virtual std::string type()
    {
        return "Triangle";
    }
};

void printParams(Shape *shape)
{
    std::cout << "Type:\t" << shape->type() << std::endl;
    std::cout << "Square:\t" << shape->square() << std::endl;
    std::cout << "Width:\t" << shape->dimensions().width << std::endl;
    std::cout << "Height:\t" << shape->dimensions().height << std::endl;
}

int main() {
    Triangle triangle(3, 4,5);
    Shape *circle = new Circle(5);

    printParams(&triangle);
    std::cout << std::endl;
    printParams(circle);

    return 0;
}
