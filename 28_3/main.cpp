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
std::mutex kitchenLock;
std::mutex readyOrdersLock;

enum Dish
{
    PIZZA,
    SOUP,
    STEAK,
    SALAD,
    SUSHI
};

class Order;

std::vector<Order> readyOrders;
std::vector<Order> deliveredOrders;

class Order
{
    Dish dish;

public:

    Order()
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
};

void kitchen(int num)
{
    std::srand(std::time(nullptr));
    int timer = std::rand() %11 + 5;
    Order order;

    console.lock();
    std::cout << "Order # " << num << ":  " << order.getDish() << std::endl;
    console.unlock();

    kitchenLock.lock();

    console.lock();
    std::cout << "- Kitchen cooking order #" << num <<":  " << order.getDish() << std::endl;
    console.unlock();

    std::this_thread::sleep_for(std::chrono::seconds( timer));

    readyOrdersLock.lock();
    readyOrders.push_back(order);
    readyOrdersLock.unlock();

    console.lock();
    std::cout << "Order #" << num << ": " << order.getDish() << " ready" << std::endl;
    console.unlock();

    kitchenLock.unlock();
}

void manager()
{
    int orderNum = 0;

    do
    {
        int timer = std::rand() %6 + 5;
        orderNum++;

        std::thread cooking(kitchen, orderNum);
        cooking.detach();

        std::this_thread::sleep_for(std::chrono::seconds( timer));
    } while (orderNum < 10);
}

void courier()
{
    do
    {
        std::this_thread::sleep_for(std::chrono::seconds(15));

        console.lock();
        std::cout << "Courier delivered orders: " << std::endl;
        readyOrdersLock.lock();
        for (int i = 0; i < readyOrders.size(); i++) {
            std::cout << "\t" << readyOrders[i].getDish() << std::endl;
            deliveredOrders.push_back(readyOrders[i]);
        }

        readyOrders.clear();

        readyOrdersLock.unlock();
        console.unlock();
    } while (deliveredOrders.size() < 10);
}

int main() {
    std::srand(std::time(nullptr));

    std::thread t = std::thread(manager);

    courier();

    t.join();

    console.lock();
    std::cout << std::endl << "Delivered orders:"  << deliveredOrders.size()<< std::endl;
    console.unlock();
    for(int i = 0; i < deliveredOrders.size(); i++)
    {
        std::cout << deliveredOrders[i].getDish() << std::endl;
    }

    return 0;
}
