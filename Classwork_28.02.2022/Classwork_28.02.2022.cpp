#include <iostream>
#include "Arr.h"
#define DEBUG

void outArr(Arr<int>& a) {
    for (size_t k = 0; k < a.GetSIZE(); k++) {
        std::cout << a.GetElement(k) << ' ';
    }
    std::cout << std::endl;
}


int main()
{
    Arr<int> MyBase(10);
    for (size_t i = 0; i < 10; ++i) {
        MyBase[i] = rand() % 10;
    }
    MyBase.AddElement(42);
    outArr(MyBase);
    //MyBase.AddElement(45);
    //MyBase.AddElement(42);
    //outArr(MyBase);
}