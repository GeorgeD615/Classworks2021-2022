#include <iostream>


/*void IntegralSearh(int* a[][], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            a[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 1; i < r; ++i) {
        a[i][0] += a[i - 1][0];
    }
    for (int j = 1; j < c; ++j) {
        a[0][j] += a[0][j - 1];
    }
    for (int i = 1; i < r; ++i) {
        for (int j = 1; j < c; ++j) {
            a[i][j] += a[i - 1][j] + a[i][j - 1];
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int N = 12;
    std::cout << "Searh:" << N << std::endl;
    for (int i = 0; i < r - 1; ++i) {
        if ((a[i][i] <= N) & (a[i + 1][i + 1] >= N)) {
            for (int j = i + 1; j < r; ++j) {
                for (int k = 0; k < i + 1; ++k) {
                    if (a[j][k] == N) {
                        std::cout << "(" << j + 1 << ", " << k + 1 << ")" << std::endl;
                    }
                }
            }
            for (int j = 0; j < i + 1; ++j) {
                for (int k = i + 1; k < r; ++k) {
                    if (a[j][k] == N) {
                        std::cout << "(" << j + 1 << ", " << k + 1 << ")" << std::endl;
                    }
                }
            }

        }
    }
}*/
void printarr(int* a[][], int r, int c){
    int k = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < r; ++j) {
            a[j + c * i] = ++k;
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < r; ++j) {
            std::cout << a[j + c * i] << " ";
        }
        std::cout << std::endl;
    }
}


int main()
{
    const int r = 4, c = 4;
    int arr[r][c];
    printarr(&arr[0][0], r, c);
    //IntegralSearh(&arr[0][0], r, c);
    
}


