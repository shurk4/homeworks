#include <iostream>
#include <vector>

void masPrint(std::vector<int> mas){
    for(int i = 0; i < mas.size(); i++)
        std::cout << mas[i] << " ";
    std::cout << "\n";
}

int main() {
    std::vector <int> mas {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//    std::vector <int> mas {7, -5, 1, -3, 4, -1, 8, -2, 2, 1, -5, 4};
    int min = 0, max = 0, minResult = 0, maxResult = 0;
    int minIndex = mas.size() - 1, maxIndex = 0;
    int result = 0;
    masPrint(mas);

    for (int i = 0; i < mas.size(); i++){
        min += mas[mas.size() - i - 1];
        max += mas[i];
        if(min > minResult){
            minResult = min;
            minIndex = mas.size() - i - 1;
        }
        if(max > maxResult){
            maxResult = max;
            maxIndex = i;
        }
    }

    for (int i = minIndex; i <= maxIndex; i++)
        result += mas[i];

    std::cout << "minIndex = " << minIndex << "\n";
    std::cout << "maxIndex = " << maxIndex << "\n";
    std::cout << "Result  = " << result << "\n";

    return 0;
}
