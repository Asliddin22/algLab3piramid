#include <iostream>
#include <cstdlib>
#include <ctime>

bool isSorted(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void heapify(int* arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}


void heapSort(int* arr, int size) {

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);


    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int* createRandomArray(int size, int minVal, int maxVal) {
    int* arr = new int[size];
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
    return arr;
}

int main() {
    int n;
    std::cout << "Input  count of elements: ";
    std::cin >> n;

    int* arr = createRandomArray(n, 1, 100);

    clock_t start = clock(); 
    heapSort(arr, n); 
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    printf("The time: %f seconds\n", seconds);
    std::cout << "Array " << (isSorted(arr, n) ? "is ordered" : "is not ordered") << std::endl;

    delete[] arr; 

    return 0;
}
