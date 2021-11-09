#include <iostream>

int main()
{
    //Одномерный динамический массив с заданным числом элементов в порядке возрастания
    /*int n;
    std::cout << "Input size of array: ";
    std::cin >> n;
    int* arr = new int [n];
    int k;
    std::cout << "Input first element: ";
    std::cin >> k;
    for (int i = 0; i < n; ++i) {
        arr[i] = k++;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
    */
    //Ввод и вывод двумерного динамического массива по горизонтали
    /*
    int r, c, k = 0;
    std::cout << "Input rows: ";
    std::cin >> r;
    std::cout << "Input cols: ";
    std::cin >> c;
    int** arr = new int* [r];
    for (int i = 0; i < r; ++i) {
        arr[i] = new int[c];
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            arr[i][j] = ++k;
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < r; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    */
    //Ввод и вывод двумерного динамического массива по диагонали(змейкой)
    /*int r, c, k = 0;
    std::cout << "Input rows: ";
    std::cin >> r;
    std::cout << "Input cols: ";
    std::cin >> c;
    int** arr = new int* [r];
    for (int i = 0; i < r; ++i) {
        arr[i] = new int[c];
    }
    for (int l = 0; l < r + c; ++l) {
        if (l % 2 == 0) {
            for (int i = 0; i <= l; ++i) {
                if ((i > (r - 1)) || ((l-i) > (c - 1))) continue;
                arr[i][l - i] = ++k;
            }
        }
        else {
            for (int i = 0; i <= l; ++i) {
                if ((i > (c - 1)) || ((l-i) > (r - 1))) continue;
                arr[l - i][i] = ++k;
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < r; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    */
}


