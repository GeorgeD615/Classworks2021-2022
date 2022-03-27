#include <iostream>
#include "Arr.h"

int main()
{
    Arr<int> A(10);
    for (int i = 0; i < A.GetSIZE(); ++i) {
        A[i] = rand() % 10;
    }
    A.PrintWithMarker();
}

