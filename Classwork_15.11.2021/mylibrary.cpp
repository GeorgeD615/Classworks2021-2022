#include <iostream>
#include "mylibrary.h"
int** create2DArray(int r, int c) {//�������� ���������� �������
	int** array;
	array = new int* [r];
	for (int i = 0; i < r; ++i) {
		array[i] = new int[c];
	}
	return array;
}
void delete2DArray(int** mas, int n, int m)//������� ������ �� ���������� �������
{
	for (int i = 0; i < n; i++)
		delete[] mas[i];
	delete[] mas;
}
void fillArrayRandomly(int* a, int size) {//���������� ����������� ������� ���������� ���������� 
	for (int i = 0; i < size; ++i) {
		a[i] = rand() % 10;
	}
}
void fill2DArrayRandomly(int** a, int rows, int cols) {//���������� ���������� ������� ���������� ���������� 
	for (int i = 0; i < rows; ++i) {
		fillArrayRandomly(a[i], cols);
	}
}
template<class Type>
void printArray(Type array, size_t size) {//����� ����������� �������
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
void print2Darray(int** array, int r, int c) {//����� ���������� ������� 
	for (int x = 0; x < r; ++x) {
		printArray(array[x], c);
	}
	std::cout << std::endl;
}

void fillArrayN(int* a, int size, int n) {//���������� ����������� ������� ����������� ���������
	for (int i = 0; i < size; ++i) {
		a[i] = n;
	}
}
void fill2DArrayN(int** a, int rows, int cols, int n) {//���������� ���������� ������� ����������� ���������
	for (int i = 0; i < rows; ++i) {
		fillArrayN(a[i], cols, n);
	}
}
void fill2DArrayDiag1(int** mas, int n, int m) {//���������� ������� ��������� �� ������� ��������� � ������ �� ���� ��������� ���������
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == j) {
				mas[i][j] = 1;
			}
			else {
				mas[i][j] = 0;
			}
		}
	}
}
int** createTrans2DArray(int** mas, int r, int c) { //�������� ���������� ������������������ �������
	int** array;
	array = new int* [c];
	for (int i = 0; i < c; ++i) {
		array[i] = new int[r];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			array[j][i] = mas[i][j];
		}
	}
	return array;
}
int** create1802DArray(int** mas, int r, int c) { //����������� ��������� 2-������� � ���� �������� �� 180 ��������.
	int** array;
	array = new int* [r];
	for (int i = 0; i < r; ++i) {
		array[i] = new int[c];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			array[i][j] = mas[r-i-1][c-j-1];
		}
	}
	return array;

}
void MultArr_By_number(int** mas, int n, int m, int k) {//��������� ������� �� �����
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
				mas[i][j] *= k;
		}
	}
}
int** createMultArr_By_number(int** mas, int r, int c, int k) { //�������� �������, ��� ���������� ��������� ������� �� �����.
	int** array;
	array = new int* [r];
	for (int i = 0; i < r; ++i) {
		array[i] = new int[c];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			array[i][j] = mas[i][j]*k;
		}
	}
	return array;
}

int** createArr_addition(int** mas1, int** mas2, int r, int c) { //�������� ������� ��� ���������� �������� ���� �������� ������.
	int** array;
	array = new int* [r];
	for (int i = 0; i < r; ++i) {
		array[i] = new int[c];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			array[i][j] = mas1[i][j] + mas2[i][j];
		}
	}
	return array;
}

int** createArr_mult(int** mas1, int** mas2, int r1, int c1, int c2) { //�������� ������� ��� ���������� ��������� ���� �������� ������.
	int** array;
	array = new int* [r1];
	for (int i = 0; i < r1; ++i) {
		array[i] = new int[c2];
	}
	for (int i = 0; i < r1; ++i) {
		for (int j = 0; j < c2; ++j) {
				array[i][j] = 0;
		}
	}
	for (int i = 0; i < r1; ++i) {
		for (int j = 0; j < c2; ++j) {
			for (int k = 0; k < c1; k++) {
				array[i][j] += mas1[i][k] * mas2[k][j];
			}
		}
	}
	return array;
}
void swapLines(int** mas, int n, int m, int n1, int n2) { //����� ������� ���� ����� 2-�������.
	int tmp = 0;
	for (int i = 0; i < m; ++i) {
		tmp = mas[n1-1][i];
		mas[n1-1][i] = mas[n2-1][i];
		mas[n2-1][i] = tmp;
	}
}
void swap�olumns(int** mas, int n, int m, int n1, int n2) { //����� ������� ���� ����� 2-�������.
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		tmp = mas[i][n1-1];
		mas[i][n1-1] = mas[i][n2-1];
		mas[i][n2-1] = tmp;
	}
}

int& GetArrElement(int** mas, int n, int m) {
	return mas[n - 1][m - 1];
}




