/*
Реализуйте простую модель работы персонального компьютера в качестве многомодульного проекта.
 В компьютере несколько основных, условных компонент.

Центральный процессор (cpu) — должен иметь в себе функцию compute,
 которая складывает 8 чисел из буфера оперативной памяти (см. далее) и выводит результат в консоль.

Оперативная память (ram) — содержит буфер на 8 целых чисел, которые можно заполнить функцией write и считать функцией read.

Жёсткий диск (disk) — имеет в себе две функции, save и load.
 Функция save должна сохранить состояние 8 чисел из оперативной памяти на постоянный носитель в файл data.txt.
 Функция load — загрузить их с носителя в оперативную память.

Графическая карта (gpu) — выводит в консоль 8 чисел из оперативной памяти.

Клавиатура (kbd) — позволяет ввести 8 чисел и разместить их в оперативной памяти.

Каждая компонента должна располагаться в отдельном модуле, с отдельным заголовочным файлом.
 Основной модуль программы (main.cpp) должен считывать пользовательский ввод команды,
 которая соответствует отдельным функциям устройств:
 sum (вычисление суммы),
 save (сохранить в файл),
 load (загрузить из файла),
 input (ввести с клавиатуры),
 display (вывести на экран).
 exit — выходит из программы.

Советы и рекомендации
Тщательно продумайте зависимости между модулями и теми файлами,
 которые должны быть включены в те или иные исходные файлы. Не забывайте про #pragma once в заголовочных файлах.

В заголовочных файлах модулей располагайте только объявления функций. Их определения должны быть уже в исходных файлах (.cpp).
*/

#include <string>

#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"

int main()
{
    std::string com;

    hello();

    do
    {
        in();
        command(com);

        if(com == "sum")
        {
            compute_print(compute());
        }
        if(com == "save")
        {
            save();
        }
        if(com == "load")
        {
            load();
        }
        if(com == "input")
        {
            input();
        }
        if(com == "display")
        {
            display();
        }
    }while(com != "exit");

    bye();

    return 0;
}
