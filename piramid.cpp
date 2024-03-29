  GNU nano 7.2                                                                      lab3piramidalnay.cpp                                                                               
#include <iostream>
#include <cstdlib>
#include <ctime>


bool isSorted(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


void heapify(int* arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}


void heapSort(int* arr, int size) {

    for (int i = size / 2 - 1; i >= 0; i--)

^G Справка      ^O Записать     ^W Поиск        ^K Вырезать     ^T Выполнить    ^C Позиция      M-U Отмена      M-A Установить мM-] На скобку   M-Q Предыдущий  ^B Назад
^X Выход        ^R ЧитФайл      ^\ Замена       ^U Вставить     ^J Выровнять    ^/ К строке     M-E Повтор      M-6 Копировать  ^Q Обр. поиск   M-W Следующий   ^F Вперёд
