/*Требуется реализовать упрощённую модель работы кухни ресторана, работающего в режиме онлайн-доставки.

Онлайн-заказ поступает каждые 5–10 секунд.
 Это случайное блюдо из пяти: пицца, суп, стейк, салат, суши.
 Официант, принявший заказ онлайн, оставляет его у кухни.
 Если кухня свободна, она принимает заказ и спустя 5–15 секунд возвращает уже готовое блюдо на выдачу.
 Время определяется случайным образом с помощью функции std::rand() в указанных диапазонах.

Курьер приезжает каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по заказчикам.

Программа завершается после 10 успешных доставок.
 На каждом из этапов, будь то заказ, или готовка, или доставка заказа, выводятся соответствующие сообщения в консоль.

Советы и рекомендации
        Для симуляции готовки, используйте отдельный мьютекс и запускайте отдельную нить ожидания с вызовом detach для неё.*/

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex console;
std::mutex ordersLock;
std::mutex readyOrdersLock;

enum Dish
{
    PIZZA,
    SOUP,
    STEAK,
    SALAD,
    SUSHI
};

class Order
{
    int number;
    Dish dish;

public:

    Order(int &num) : number(num)
    {
        int dishNum = std::rand() %5;

        if(dishNum == 0)
        {
            dish = PIZZA;
        }
        if(dishNum == 1)
        {
            dish = SOUP;
        }
        if(dishNum == 2)
        {
            dish = STEAK;
        }
        if(dishNum == 3)
        {
            dish = SALAD;
        }
        if(dishNum == 4)
        {
            dish = SUSHI;
        }
    }

    std::string getDish()
    {
        if(dish == PIZZA)
        {
            return "pizza";
        }
        if(dish == SOUP)
        {
            return "soup";
        }
        if(dish == STEAK)
        {
            return "steak";
        }
        if(dish == SALAD)
        {
            return "salad";
        }
        if(dish == SUSHI)
        {
            return "sushi";
        }
    }

    int getNumber()
    {
        return number;
    }
};

void kitchen(std::vector<Order> &_orders, std::vector<Order> &_readyOrders)
{
    int counter = 0;
//    std::srand(std::time(nullptr));

    do {
        if(!_orders.empty())
        {
            int timer = std::rand() % 11 + 5;

            console.lock();
            std::cout << "- Kitchen cooking order # " << _orders[0].getNumber() << ":  " << _orders[0].getDish() << std::endl;
            console.unlock();

            std::this_thread::sleep_for(std::chrono::seconds(timer));

            readyOrdersLock.lock();
            _readyOrders.push_back(_orders[0]);
            readyOrdersLock.unlock();

            console.lock();
            std::cout << "- Order # " << _orders[0].getNumber() << ": " << _orders[0].getDish() << " ready" << std::endl;
            console.unlock();

            ordersLock.lock();
            _orders.erase(_orders.begin());
            ordersLock.unlock();
            counter++;
        }
    } while (counter < 10);

}

void manager(std::vector<Order> &_orders)
{
    int orderNum = 0;

    do
    {
        int timer = std::rand() %6 + 5;

        orderNum++;

        ordersLock.lock();
        _orders.push_back(Order(orderNum));
        ordersLock.unlock();

        console.lock();
        std::cout << "Order # " << orderNum << ":  " << _orders[_orders.size() - 1].getDish() << std::endl;
        console.unlock();

        std::this_thread::sleep_for(std::chrono::seconds( timer));
    } while (orderNum < 10);
}

void courier(std::vector<Order> &_readyOrders, std::vector<Order> &_deliveredOrders)
{
    do
    {
        std::this_thread::sleep_for(std::chrono::seconds(15));

        console.lock();
        std::cout << "\t - Courier delivered orders: " << std::endl;
        readyOrdersLock.lock();
        for (int i = 0; i < _readyOrders.size(); i++) {
            std::cout << "\t\t#" << _readyOrders[i].getNumber() << " " << _readyOrders[i].getDish() << std::endl;
            _deliveredOrders.push_back(_readyOrders[i]);
        }

        _readyOrders.clear();

        readyOrdersLock.unlock();
        console.unlock();
    } while (_deliveredOrders.size() < 10);
}

int main() {
    std::srand(std::time(nullptr));

    std::vector<Order> orders;
    std::vector<Order> readyOrders;
    std::vector<Order> deliveredOrders;

    std::thread t1 = std::thread(manager, std::ref(orders));

    std::thread t2 = std::thread(kitchen, std::ref(orders), std::ref(readyOrders));

    t1.detach();
    t2.detach();

    courier(readyOrders, deliveredOrders);



    console.lock();
    std::cout << std::endl << "Delivered orders:"  << deliveredOrders.size()<< std::endl;

    for(int i = 0; i < deliveredOrders.size(); i++)
    {
        std::cout << deliveredOrders[i].getDish() << std::endl;
    }
    console.unlock();

    return 0;
}
