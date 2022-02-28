#include <iostream>
#include <vector>

void mergeSort(std::vector<float> &vec_1, int start, int end) {

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

    std::vector<float> vec_2;

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

int main()
{
    std::vector<float> vec {1.2, 2.3, 1.11, 3.4, 5.5, 5.4, 5.3, 5.1, 1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251};
//    std::vector<float> vec (15);
//    std::cout << "Input 15 numbers:\n";
//    for (int i = 0; i < vec.size(); i++)
//        std::cin >> vec[i];

    vecPrint(vec);

    mergeSort(vec, 0, vec.size());

    std::cout << "Sorted array is \n";
    vecPrint(vec);
}
