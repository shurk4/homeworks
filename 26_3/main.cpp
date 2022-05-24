#include <iostream>
#include <cassert>

#define NEWLINE std::cout << std::endl;

class Window
{
    int startX = 1,
        startY = 1;

    int sizeX = 10,
        sizeY = 5;

public:

    bool isOpen = false;

    int getStartX()
    {
        return startX;
    }
    int getStartY()
    {
        return startY;
    }
    int getSizeX()
    {
        return sizeX;
    }
    int getSizeY()
    {
        return sizeY;
    }

    void setStartPos(int displayX, int displayY, int x, int y)
    {
        if(x < 0)
        {
            startX = 0;
        }
        else if(x > displayX)
        {
            startX = displayX;
        }
        else
        {
            startX = x - 1;
        }

        if(y < 0)
        {
            startY = 0;
        }
        else if(y > displayY)
        {
            startY = displayY;
        }
        else
        {
            startY = y - 1;
        }

        setSize(displayX, displayY, sizeX, sizeY);
        NEWLINE
    }

    void setSize(int displayX, int displayY, int x, int y)
    {
        assert(x > 0);
        assert(y > 0);
        if(startX + x > displayX)
        {
            sizeX = displayX - startX;
        }
        else
        {
            sizeX = x;
        }

        if(startY + y > displayY)
        {
            sizeY = displayY - startY;
        }
        else
        {
            sizeY = y;
        }
    }
};

class Display
{
    int sizeX = 80,
        sizeY = 50;

    Window window;

public:

    void resolution()
    {
        std::cout << "Enter the resolution" << std::endl;
        std::cout << "X: ";
        std::cin >> sizeX;
        std::cout << "Y: ";
        std::cin >> sizeY;

        window.setSize(sizeX, sizeY, window.getSizeX(), window.getSizeY());
        NEWLINE
    }
    
    void print()
    {
        for(int y = 0; y < sizeY; y++)
        {
            for(int x = 0; x < sizeX; x++)
            {
                if(window.isOpen && y >= window.getStartY() && y <= window.getStartY() + window.getSizeY()
                                 && x >= window.getStartX() && x <= window.getStartX() + window.getSizeX())
                {

                    std::cout << "1";
                }
                else
                {

                    std::cout << "0";
                }
            }
            std::cout << std::endl;
        }
        NEWLINE
    }

    void openWindow()
    {
        window.isOpen = true;
    }

    void resizeWindow()
    {
        int x,
            y;

        std::cout << "Enter size" << std::endl;
        std::cout << "X: ";
        std::cin >> x;
        std::cout << "Y: ";
        std::cin >> y;

        window.setSize(sizeX, sizeY, x, y);
        NEWLINE
    }

    void moveWindow()
    {
        int x,
            y;

        std::cout << "Enter start position" << std::endl;
        std::cout << "X: ";
        std::cin >> x;
        std::cout << "Y: ";
        std::cin >> y;

        window.setStartPos(sizeX, sizeY, x, y);
    }

    void closeWindow()
    {
        window.isOpen = false;
        print();
    }
};

int main() {
    Display display;
    std::string input;

    display.openWindow();
    display.print();
    NEWLINE

    do
    {
        std::cout << "Enter the command:" << std::endl;
        std::cin >> input;
        NEWLINE

        if(input == "resolution")
        {
            display.resolution();
        }
        if(input == "move")
        {
            display.moveWindow();
        }
        if(input == "resize")
        {
            display.resizeWindow();
        }
        if(input == "display")
        {
            display.print();
        }
        if(input == "close")
        {
            display.closeWindow();
        }
    }while(input != "close");

    return 0;
}
