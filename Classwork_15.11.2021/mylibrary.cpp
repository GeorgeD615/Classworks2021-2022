#include <iostream>
#include "mylibrary.h"

int** create2DArray(int r, int c) {//�������� 2-������� � ��������� ���������.
	int **array = new int* [r];
	for (int i = 0; i < r; ++i) {
		array[i] = new int[c];
	}
	return array;
}
void delete2DArray(int** mas, int n, int m)//������������ �������� �� ���������� �������
{
	for (int i = 0; i < n; i++)
		delete[] mas[i];
	delete[] mas;
}
void fill2DArrayRandomly(int** a, int rows, int cols) {//���������� ������� ���������� ����������
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			a[i][j] = rand() % 10;
		}
	}
}

void print2Darray(int** array, int r, int c) {// ����� ���������� ������� 
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			std::cout << array[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
void fill2DArrayN(int** a, int rows, int cols, int n) {//���������� ���������� ������� ����������� ���������
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			a[i][j] = n;
		}
	}
}
int** create2DArrayDiag1(int rc) {//������������� 2-������� � 1 �� ������� ��������� � 0 � ��������� ���������.
	int** mas = create2DArray(rc, rc);
	for (int i = 0; i < rc; ++i) {
		for (int j = 0; j < rc; ++j) {
			if (i == j) {
				mas[i][j] = 1;
			}
			else {
				mas[i][j] = 0;
			}
		}
	}
	return mas;
}
int** createTrans2DArray(int** mas, int r, int c) { //�������� ����������������� �������
	int** array = create2DArray(c, r);
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < r; ++j) {
			array[i][j] = mas[j][i];
		}
	}
	return array;
}
int** create1802DArray(int** mas, int r, int c) {//�������� ������� ��������� �� 180 ��������
	int** array;
	array = new int* [r];
	for (int i = 0; i < r; ++i) {
		array[i] = new int[c];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			array[i][j] = mas[r - i - 1][c - j - 1];
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
int** createMultArr_By_number(int** mas, int r, int c, int k) { //�������� ������� ���������� �� �����
	int** array;
	array = new int* [r];
	for (int i = 0; i < r; ++i) {
		array[i] = new int[c];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			array[i][j] = mas[i][j] * k;
		}
	}
	return array;
}

int** createArr_addition(int** mas1, int** mas2, int r, int c) { //�������� �������, ��� ����� ���� ������
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

int** createArr_mult(int** mas1, int** mas2, int r1, int c1, int c2) { //�������� �������, ��� ������������ ���� ������
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
void swapLines(int** mas, int n, int m, int n1, int n2) { // �������� ������� ������ � �������
	int tmp = 0;
	for (int i = 0; i < m; ++i) {
		tmp = mas[n1 - 1][i];
		mas[n1 - 1][i] = mas[n2 - 1][i];
		mas[n2 - 1][i] = tmp;
	}
}
void swapColumns(int** mas, int n, int m, int n1, int n2) { // �������� ������� ������� � �������
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		tmp = mas[i][n1 - 1];
		mas[i][n1 - 1] = mas[i][n2 - 1];
		mas[i][n2 - 1] = tmp;
	}
}

int& GetArrElement(int** mas, int n, int m) { //�������� ������� ������� �� ��������
	return mas[n - 1][m - 1];
}







