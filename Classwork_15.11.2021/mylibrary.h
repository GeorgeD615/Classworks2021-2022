#ifndef _My_library_2021_
#define _My_library_2021_

int** create2DArray(int r, int c);
void delete2DArray(int** mas, int n, int m);
void fill2DArrayRandomly(int** a, int rows, int cols);
void print2Darray(int** array, int r, int c);
void fill2DArrayN(int** a, int rows, int cols, int n);
int** create2DArrayDiag1(int rc);
int** createTrans2DArray(int** mas, int r, int c);
int** create1802DArray(int** mas, int r, int c);
void MultArr_By_number(int** mas, int n, int m, int k);
int** createMultArr_By_number(int** mas, int r, int c, int k);
int** createArr_addition(int** mas1, int** mas2, int r, int c);
int** createArr_mult(int** mas1, int** mas2, int r1, int c1, int c2);
void swapLines(int** mas, int n, int m, int n1, int n2);
void swapColumns(int** mas, int n, int m, int n1, int n2);
int& GetArrElement(int** mas, int n, int m);
#endif 