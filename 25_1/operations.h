
#pragma once

struct input
{
    std::string command;
    bool operated = false;
    int x1,
            y1,
            x2,
            y2;
};

input operatedPlace;

bool placeCheck(input& buf)
{
    return (operatedPlace.x1 == buf.x1 && operatedPlace.y1 == buf.y1 && operatedPlace.x2 == buf.x2 && operatedPlace.y2 == buf.y2);

}

bool commandCheck(input& buf)
{
    if(buf.command == "scalpel" || buf.command == "hemostat" || buf.command == "tweezers" || buf.command == "suture")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void intro(input& buf)
{
    do
    {
        std::cout << "Input the command: " << std::endl;
        std::cin >> buf.command;

        if (!commandCheck(buf)) {
            std::cout << "Wrong command! Try again:" << std::endl;
        }
    } while (!commandCheck(buf));

    if(buf.command != "scalpel" && !operatedPlace.operated)
    {
        std::cout << "You haven't started the operation yet!" << std::endl;
        buf.command = "x";
    }
    else if(buf.command == "scalpel" && operatedPlace.operated)
    {
        std::cout << "You have already made an incision!" << std::endl;
        buf.command = "x";
    }
    else
    {
        if (buf.command == "scalpel" || buf.command == "suture") {
            std::cout << "Enter the start coords" << std::endl;
            std::cout << "X:";
            std::cin >> buf.x1;
            std::cout << "Y:";
            std::cin >> buf.y1;

            std::cout << "Enter the end coords" << std::endl;
            std::cout << "X:";
            std::cin >> buf.x2;
            std::cout << "Y:";
            std::cin >> buf.y2;

            if (buf.command == "scalpel" && !operatedPlace.operated) {
                operatedPlace.x1 = buf.x1;
                operatedPlace.y1 = buf.y1;
                operatedPlace.x2 = buf.x2;
                operatedPlace.y2 = buf.y2;
                operatedPlace.operated = true;
            }

            if (buf.command == "suture" && !placeCheck(buf))
            {
                std::cout << "The coordinates of the seams must match the coordinates of the incision!" << std::endl;
                buf.command = "x";
            }
        } else {
            std::cout << "Enter the coords" << std::endl;
            std::cout << "X:";
            std::cin >> buf.x1;
            std::cout << "Y:";
            std::cin >> buf.y1;
        }
    }
}

void scalpel(input& buf)
{
    std::cout << "A cut was made according to the coordinates: (" << buf.x1 << ";" << buf.y1 << "), ("
                                                                  << buf.x2 << ";" << buf.y2 << ")" << std::endl;
}
void hemostat(input& buf)
{
    std::cout << "The hemostatic clamp is used according to the coordinates: (" << buf.x1 << ";" << buf.y1 << ")" << std::endl;
}

void tweezers(input& buf)
{
    std::cout << "The tweezers is used according to the coordinates: (" << buf.x1 << ";" << buf.y1 << ")" << std::endl;
}

void suture(input& buf)
{
    std::cout << "The suture is applied at the coordinates: (" << buf.x1 << ";" << buf.y1 << "), ("
                                                               << buf.x2 << ";" << buf.y2 << ")" << std::endl;
}

void operation(input& buf)
{
    if(buf.command == "scalpel")
    {
        scalpel(buf);
    }
    else if(buf.command == "hemostat")
    {
        hemostat(buf);
    }
    else if(buf.command == "tweezers")
    {
        tweezers(buf);
    }
    else if(buf.command == "suture")
    {
        suture(buf);
    }
}