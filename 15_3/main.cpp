#include <iostream>
#include <vector>

void mergeSort(std::vector<int> vec_1, int start, int end) {

    if (end - start < 2) {
        return;
    }

    if (end - start == 2) {
        if (vec_1[start] > vec_1[start + 1]) {
            std::swap(vec_1[start], vec_1[start + 1]);
        }
        return;
    }
    mergeSort(vec_1, start, start + (end - start) / 2);
    mergeSort(vec_1, start + (end - start) / 2, end);

    std::vector<int> vec_2;

    int b1 = start;
    int e1 = start + (end - start) / 2;
    int b2 = e1;

    while (vec_2.size() < end - start) {
        if (b1 >= e1 || (b2 < end && vec_1[b2] <= vec_1[b1])) {
            vec_2.push_back(vec_1[b2]);
            ++b2;
        }
        else {
            vec_2.push_back(vec_1[b1]);
            ++b1;
        }
    }

    for (int i = start; i < end; ++i) {
        vec_1[i] = vec_2[i - start];
    }
}

void vecPrint(std::vector<float> vec){
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";
}

//С клавиатуры вводятся числа.
// Когда пользователь вводит -1 -- необходимо выводить на экран пятое по возрастанию число среди введённых.
// Когда пользователь вводит -2 -- программа завершает работу.
//
//Пример:
//
//ввод: 7 5 3 1 2 4 6 -1
//
//вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
//
//ввод: 1 1 1 -1
//
//вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
//
//ввод -2
//
//завершение программы

void masPrint(std::vector<int> mas){
    for(int i = 0; i < mas.size(); i++)
        std::cout << mas[i] << " ";
    std::cout << "\n";
}

int main() {
    std::vector <int> mas(5);
    int i = 0;

    do {
        std::cout << "I = " << i << "\n";
        std::cout << "Input number:\n";
        std::cin >> mas[i];
        if(mas[i] == -1){
            if (i < 5) continue;
            else {
                mergeSort(mas, 0, mas.size());
                masPrint(mas);
            }
        } else {
            i++;
        }
    } while (mas[i] > -2);
    return 0;

}

