#ifndef _My_library_2021_
#define _My_library_2021_
int** create2DArray(int r, int c);
void delete2DArray(int** mas, int n, int m);
void fillArrayRandomly(int* a, int size);
void fill2DArrayRandomly(int** a, int rows, int cols);
template<class Type>
void printArray(Type array, size_t size);
void print2Darray(int** array, int r, int c);
void fillArrayN(int* a, int size, int n);
void fill2DArrayN(int** a, int rows, int cols, int n);
void fill2DArrayDiag1(int** mas, int n, int m);
int** createTrans2DArray(int** mas, int r, int c);
int** create1802DArray(int** mas, int r, int c);
void MultArr_By_number(int** mas, int n, int m, int k);
int** createMultArr_By_number(int** mas, int r, int c, int k);
int** createArr_addition(int** mas1, int** mas2, int r, int c);
int** createArr_mult(int** mas1, int** mas2, int r1, int c1, int c2);
void swapLines(int** mas, int n, int m, int n1, int n2);
void swapÑolumns(int** mas, int n, int m, int n1, int n2);
int& GetArrElement(int** mas, int n, int m);
#endif 

