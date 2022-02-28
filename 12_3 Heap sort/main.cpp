#include <iostream>

/* Вспомогательная функция для вывода на экран массива размера n*/
void printArray(float arr[], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи


void heapify(float arr[], int n, int i) {
    int largest = i;

// Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(float arr[], int n) {

    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


// Управляющая программа
int main()
{
    float arr[]{1.2, 2.3, 1.11, 3.4, 5.5, 5.4, 5.3, 5.1, 1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);

    heapSort(arr, n);

    std::cout << "Sorted array is \n";

    printArray(arr, n);
}