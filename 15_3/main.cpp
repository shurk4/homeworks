#include <iostream>
#include <vector>

void mergeSort(std::vector<int> &vec_1, int start, int end) {
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

void masPrint(std::vector<int> mas){
    for(int i = 0; i < mas.size(); i++)
        std::cout << mas[i] << " ";
    std::cout << "\n";
}

int main() {
    std::vector <int> mas;
    int num;
    int i = 0;

    do {
        std::cout << "Input number:\n";
        std::cin >> num;
        if(num == -1){
            if (i < 5) {
                std::cout << "Not enough numbers\n";
                continue;
            }
            else {
                mergeSort(mas, 0, mas.size());
                std::cout << "Sorted array:\n";
                masPrint(mas);
                std::cout << "The fifth ascending number :" << mas[4] << "\n";
            }
        } else {
            mas.push_back(num);
            i++;
        }
    } while (num > -2);
    return 0;
}

