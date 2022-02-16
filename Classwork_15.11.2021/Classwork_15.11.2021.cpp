#include <iostream>
#include "mylibrary.h"

void test_fill2DArrayN(int r, int c, int n) {//Тест на заполнение массива константным значением
	int** arr = create2DArray(r, c);
	fill2DArrayN(arr, r, c, n);
	int fail_count = 0, pass_count = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == n) {
				++pass_count;
			}
			else {
				++fail_count;
			}
		}
	}
	std::cout << "Test failed: " << fail_count << " times" << std::endl;
	std::cout << "Test passed: " << pass_count << " times" << std::endl;
	delete2DArray(arr, r, c);
}

void test_create2DArrayDiag1(int rc) {//Тест на создание диагональной матрицы
	int** arr = create2DArrayDiag1(rc);
	int fail_count = 0, pass_count = 0;
	for (int i = 0; i < rc; ++i) {
		for (int j = 0; j < rc; ++j) {
			if (i == j) {
				if (arr[i][j] == 1){
					++pass_count;
				}
				else {
					++fail_count;
				}
			}
			else {
				if (arr[i][j] == 0) {
					++pass_count;
				}
				else {
					++fail_count;
				}
			}
			
		}
	}
	std::cout << "Test failed: " << fail_count << " times" << std::endl;
	std::cout << "Test passed: " << pass_count << " times" << std::endl;
	delete2DArray(arr, rc, rc);
}

void test_createTrans2DArray(int r, int c) {// Тест на создание транспонированной матрицы
	int** arr = create2DArray(r, c);
	fill2DArrayRandomly(arr, r, c);
	int** Tarr = createTrans2DArray(arr, r, c);
	int fail_count = 0, pass_count = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == Tarr[j][i]) {
				++pass_count;
			}
			else {
				++fail_count;
			}
		}
	}
	std::cout << "Test failed: " << fail_count << " times" << std::endl;
	std::cout << "Test passed: " << pass_count << " times" << std::endl;
	delete2DArray(Tarr, r, c);
	delete2DArray(arr, r, c);
}

void test_create1802DArray(int r, int c) {//Тест на создание матрицы повёрнутой на 180 градусов
	int** arr = create2DArray(r, c);
	fill2DArrayRandomly(arr, r, c);
	int** arr180 = create1802DArray(arr, r, c);
	int fail_count = 0, pass_count = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == arr180[r-i-1][c-j-1]) {
				++pass_count;
			}
			else {
				++fail_count;
			}
		}
	}
	std::cout << "Test failed: " << fail_count << " times" << std::endl;
	std::cout << "Test passed: " << pass_count << " times" << std::endl;
	delete2DArray(arr180, r, c);
	delete2DArray(arr, r, c);


}

void test_MultArr_By_number(int r, int c, int k) {//Тест на умножение матрицы на число
	int** arr = create2DArray(r, c);
	fill2DArrayRandomly(arr, r, c);
	int** copy_arr = create2DArray(r, c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			copy_arr[i][j] = arr[i][j];
		}
	}
	MultArr_By_number(arr, r, c, k);
	int fail_count = 0, pass_count = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == copy_arr[i][j] * k) {
				++pass_count;
			}
			else {
				++fail_count;
			}
		}
	}
	std::cout << "Test failed: " << fail_count << " times" << std::endl;
	std::cout << "Test passed: " << pass_count << " times" << std::endl;
	delete2DArray(arr, r, c);
	delete2DArray(copy_arr, r, c);
}

void test_createMultArr_By_number(int r, int c, int k) {// Тест на создание массива, как произведение массива на число
	int** arr = create2DArray(r, c);
	fill2DArrayRandomly(arr, r, c);
	int** Marr = createMultArr_By_number(arr, r, c, k);
	int fail_count = 0, pass_count = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (Marr[i][j] == arr[i][j] * k) {
				++pass_count;
			}
			else {
				++fail_count;
			}
		}
	}
	std::cout << "Test failed: " << fail_count << " times" << std::endl;
	std::cout << "Test passed: " << pass_count << " times" << std::endl;
	delete2DArray(arr, r, c);
	delete2DArray(Marr, r, c);
}

void test_createArr_addition(int r, int c) {// Тест на создание массива, как суммы двух массивов 
	int** arr_1 = create2DArray(r, c);
	fill2DArrayRandomly(arr_1, r, c);
	int** arr_2 = create2DArray(r, c);
	fill2DArrayRandomly(arr_2, r, c);
	int** arr_add = createArr_addition(arr_1, arr_2, r, c);
	int fail_count = 0, pass_count = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr_add[i][j] == arr_1[i][j] + arr_2[i][j]) {
				++pass_count;
			}
			else {
				++fail_count;
			}
		}
	}
	std::cout << "Test failed: " << fail_count << " times" << std::endl;
	std::cout << "Test passed: " << pass_count << " times" << std::endl;
	delete2DArray(arr_1, r, c);
	delete2DArray(arr_2, r, c);
	delete2DArray(arr_add, r, c);

}

int main() {
	std::cout << "********** Test function: fill2DArrayN *************" << std::endl;
	test_fill2DArrayN(3, 4, 6);
	test_fill2DArrayN(4, 6, 6);
	test_fill2DArrayN(6, 13, 5);

	std::cout << "********** Test function: create2DArrayDiag1 *************" << std::endl;
	test_create2DArrayDiag1(5);
	test_create2DArrayDiag1(10);
	test_create2DArrayDiag1(20);

	std::cout << "********** Test function: createTrans2DArray *************" << std::endl;
	test_createTrans2DArray(6, 14);
	test_createTrans2DArray(13, 25);
	
	std::cout << "********** Test function: create1802DArray *************" << std::endl;
	test_create1802DArray(3, 4);
	test_create1802DArray(5, 4);
	test_create1802DArray(6, 7);

	std::cout << "********** Test function: MultArr_By_number *************" << std::endl;
	test_MultArr_By_number(3, 4, 5);
	test_MultArr_By_number(6, 7, 19);
	test_MultArr_By_number(7, 5, 7);

	std::cout << "********** Test function: createMultArr_By_number *************" << std::endl;
	test_MultArr_By_number(3, 4, 5);
	test_MultArr_By_number(6, 7, 19);
	test_MultArr_By_number(7, 5, 7);

	std::cout << "********** Test function: createArr_addition *************" << std::endl;
	test_createArr_addition(3, 4);
	test_createArr_addition(6, 7);
	test_createArr_addition(7, 5);

	/*int rows, cols;
	std::cout << "Enter a number of rows and columns:\n";
	std::cout << "rows: ";
	std::cin >> rows;
	std::cout << "columns: ";
	std::cin >> cols;

	int** d = create2DArray(rows, cols); //1)Создание 2-массива с заданными размерами
	fill2DArrayRandomly(d, rows, cols);
	std::cout << "Random Array:" << std::endl;
	print2Darray(d, rows, cols);

	std::cout << "================================" << std::endl;
	std::cout << std::endl;

	std::cout << "Input n(all elements of array): ";
	int n;
	std::cin >> n;
	fill2DArrayN(d, rows, cols, n);//3)Инициализация 2-массива - все элементы одинаковы и равны заданному значению.
	std::cout << "Array, which every element is " << n << ':' << std::endl;
	print2Darray(d, rows, cols);

	std::cout << std::endl;
	int rc = 0;
	std::cout << "Input rows and columns for array, which 1 on main diag and 0 in others: ";
	std::cin >> rc;
	int** dDiag;
	dDiag = create2DArrayDiag1(rc);//4)Инициализация 2-массива с 1 на главной диагонали и 0 в остальных элементах.
	std::cout << "Array, which 1 on main diag and 0 in others:" << std::endl;
	print2Darray(dDiag, rc, rc);

	std::cout << "================================" << std::endl;
	std::cout << std::endl;

	fill2DArrayRandomly(d, rows, cols);
	std::cout << "My Array:" << std::endl;
	print2Darray(d, rows, cols);

	int** dTrans = createTrans2DArray(d, rows, cols);//5)Создание 2-массива, являющегося транспонированным исходным
	std::cout << "TransArray:" << std::endl;
	print2Darray(dTrans, cols, rows);

	int** d180 = create1802DArray(d, rows, cols); //6)Модификация исходного 2 - массива в виде поворота на 180 градусов.
	std::cout << "Array 180:" << std::endl;
	print2Darray(d180, rows, cols);

	std::cout << "================================" << std::endl;
	std::cout << std::endl;

	int k = 0;
	std::cout << "Input k, which will be a multiplier: ";
	std::cin >> k;

	fill2DArrayRandomly(d, rows, cols);
	std::cout << "Array before:" << std::endl;
	print2Darray(d, rows, cols);
	MultArr_By_number(d, rows, cols, k); //7)Умножение матрицы на число.
	std::cout << "Array times a number " << k << std::endl;
	print2Darray(d, rows, cols);

	std::cout << "================================" << std::endl;
	std::cout << std::endl;

	fill2DArrayRandomly(d, rows, cols);
	std::cout << "Array before:" << std::endl;
	print2Darray(d, rows, cols);
	int** dMult = createMultArr_By_number(d, rows, cols, k);//8)Создание матрицы, как результата умножения матрицы на число.
	std::cout << "Array (created) times a number " << k << std::endl;
	print2Darray(dMult, rows, cols);

	std::cout << "================================" << std::endl;
	std::cout << std::endl;


	int** d1 = create2DArray(rows, cols);
	fill2DArrayRandomly(d1, rows, cols);
	std::cout << "Array_1:" << std::endl;
	print2Darray(d1, rows, cols);
	int** d2 = create2DArray(rows, cols);
	fill2DArrayRandomly(d2, rows, cols);
	std::cout << "Array_2:" << std::endl;
	print2Darray(d2, rows, cols);

	int** dAdd = createArr_addition(d1, d2, rows, cols); //9)Создание матрицы как результата сложения двух числовых матриц.
	std::cout << "Array is the result of adding two matrices (Array_1 and Array_2):" << std::endl;
	print2Darray(dAdd, rows, cols);

	std::cout << "================================" << std::endl;
	std::cout << std::endl;

	int rows1, cols1, rows2, cols2;
	std::cout << "Enter a number of rows and columns for multiplication of two matrices:\n";
	std::cout << "rows_1: ";
	std::cin >> rows1;
	std::cout << "columns_1 and rows_2: ";
	std::cin >> cols1;
	rows2 = cols1;
	std::cout << "columns_2: ";
	std::cin >> cols2;

	int** d_1 = create2DArray(rows1, cols1);
	fill2DArrayRandomly(d_1, rows1, cols1);
	std::cout << "Array_1:" << std::endl;
	print2Darray(d_1, rows1, cols1);
	int** d_2 = create2DArray(rows2, cols2);
	fill2DArrayRandomly(d_2, rows2, cols2);
	std::cout << "Array_2:" << std::endl;
	print2Darray(d_2, rows2, cols2);

	int** dMultArr = createArr_mult(d_1, d_2, rows1, cols1, cols2);//10)Создание матрицы как результата умножения двух числовых матриц.
	std::cout << "Array is the result of multiplication two matrices (Array_1 and Array_2):" << std::endl;
	print2Darray(dMultArr, rows2, cols2);

	std::cout << "================================" << std::endl;
	std::cout << std::endl;


	std::cout << "Swapping two rows / columns of a 2-array." << std::endl; //11)Обмен местами двух строк / столбцов 2 - массива.

	int Srows, Scols;
	std::cout << "Enter a number of rows and columns:\n";
	std::cout << "rows: ";
	std::cin >> Srows;
	std::cout << "columns: ";
	std::cin >> Scols;
	int** dSwap = create2DArray(Srows, Scols);
	fill2DArrayRandomly(dSwap, Srows, Scols);
	std::cout << "Array before:" << std::endl;
	print2Darray(dSwap, Srows, Scols);

	int l1, l2;
	std::cout << "Input the lines numbers you want to swap: " << std::endl;
	std::cout << "Input first line: ";
	std::cin >> l1;
	std::cout << "Input second line: ";
	std::cin >> l2;

	swapLines(dSwap, Srows, Scols, l1, l2);

	std::cout << "Array after swapping lines : " << std::endl;
	print2Darray(dSwap, Srows, Scols);

	swapLines(dSwap, Srows, Scols, l1, l2);//Возвращение массива в исходное состояние

	int c1, c2;
	std::cout << "Input the columns numbers you want to swap: " << std::endl;
	std::cout << "Input first column: ";
	std::cin >> c1;
	std::cout << "Input second column: ";
	std::cin >> c2;

	swapColumns(dSwap, Srows, Scols, c1, c2);

	std::cout << "Array after swapping columns :" << std::endl;
	print2Darray(dSwap, Srows, Scols);

	swapColumns(dSwap, Srows, Scols, c1, c2);//Возвращение массива в исходное состояние

	std::cout << "================================" << std::endl;
	std::cout << std::endl;

	std::cout << "My array" << std::endl;
	print2Darray(dSwap, Srows, Scols);

	int L, C;
	std::cout << "Input number of line and column of element what you want to get: " << std::endl;
	std::cout << "Input number of line: ";
	std::cin >> L;
	std::cout << "Input number of column: ";
	std::cin >> C;

	int E = GetArrElement(dSwap, L, C);

	std::cout << "Element what you ask: " << E << std::endl;

	delete2DArray(dDiag, rc, rc);
	delete2DArray(dSwap, Srows, Scols);
	delete2DArray(dMultArr, rows, cols);
	delete2DArray(d_1, rows, cols);
	delete2DArray(d_2, rows, cols);
	delete2DArray(d1, rows, cols);
	delete2DArray(d2, rows, cols);
	delete2DArray(dAdd, rows, cols);
	delete2DArray(dMult, rows, cols);
	delete2DArray(d180, rows, cols);
	delete2DArray(dTrans, rows, cols);
	delete2DArray(d, rows, cols);//2)Освобождение ресурсов занимаемых 2-массивом
	*/
	return 0;
}


