#include <iostream>
#include <vector>
#include <cmath>

void mergeSort(std::vector<int> &vec_1, int start, int end) {
    if (end - start < 2) {
        return;
    }

    if (end - start == 2) {
        if (abs(vec_1[start]) > abs(vec_1[start + 1])) {
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
        if (b1 >= e1 || (b2 < end && abs(vec_1[b2]) <= abs(vec_1[b1]))) {
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

void masInput(std::vector<int> &mas){
    int num, size;
    do {
        std::cout << "Input size of array: ";
        std::cin >> size;
        if(size < 1) std::cout << "Wront input!\n";
    } while (size < 1);

    std::cout << "Input " << size << " numbers:\n";
    for(int i = 0; i < size; i++) {
        std::cin >> num;
        mas.push_back(num);
    }
}

void masPrint(std::vector<int> mas){
    for(int i = 0; i < mas.size(); i++)
        std::cout << mas[i] << " ";
    std::cout << "\n";
}

int main() {
//    std::vector <int> mas {-100,-50, -5, 1, 10, 15};
//    std::vector <int> mas {-100,-50, -5, 1, 10, -16, 24, -3, 12, 15, -6, -11, 97};

    std::vector <int> mas;
    masInput(mas);

    mergeSort(mas, 0, mas.size());

    std::cout << "Sorted array:\n";
    masPrint(mas);

    return 0;
}


