#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	//Минимальный элемент массива и его номер
	/*const int N = 20;
	int n = 0;
	int Arr[N];
	for (int i = 0; i < N; ++i) {
		Arr[i] = rand() % 100;
	}
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}
	int min = Arr[0];
	for (int i = 0; i < N; ++i) {
		if (Arr[i] < min) {
			min = Arr[i];
			n = i+1;
		}
	}
	std::cout << "min = " << min << " " << "n = " << n;*/
	//Номера всех минимальных элементов массива
	/*const int N = 1000;
	int n = 0;
	int Arr[N];
	for (int i = 0; i < N; ++i) {
		Arr[i] = rand() % 100;
	}
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
	int min = Arr[0];
	for (int i = 0; i < N; ++i) {
		if (Arr[i] < min) {
			min = Arr[i];
		}
	}
	std::cout << "min = " << min << std::endl;
	std::cout << "n = ";
	for (int i = 0; i < N; ++i) {
		if (Arr[i] == min) {
			std::cout << i + 1 << " ";
		}
	}*/
	//Среднее арифметическое всех элементов массива
	/*const int N = 1000;
	int n = 0;
	int S = 0;
	int Arr[N];
	for (int i = 0; i < N; ++i) {
		Arr[i] = rand() % 100;
	}
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < N; ++i) {
		S += Arr[i];
	}
	std::cout <<"Среднее арифметическое: " << double(S) / double(N) << std::endl;*/
	//Массив случайных 16-ричных цифр
	/*char ArrSimbols[]{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	const int N = 100;
	char Arr[N];
	for (int i = 0; i < N; ++i) {
		Arr[i] = ArrSimbols[rand() % 16];
	}
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}*/
	//Расстановка элементов массива в обратном порядке
	/*int tmp;
	const int N = 21;
	int Arr[N];
	for (int i = 0; i < N; ++i) {
		Arr[i] = rand() % 100;
	}
	std::cout << "befor:" << std::endl;
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < N / 2; ++i) {
		tmp = Arr[i];
		Arr[i] = Arr[N - 1 - i];
		Arr[N - 1 - i] = tmp;
	}
	std::cout << "after:" << std::endl;
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl; */
	//Перестановка элементов в зависимости от разности со средним арифметическим 
	/*const int N = 10;
	int n = 0;
	int S = 0;
	int Arr[N];
	for (int i = 0; i < N; ++i) {
		Arr[i] = rand() % 100;
	}
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < N; ++i) {
		S += Arr[i];
	}
	double Sa = double(S) / double(N);
	std::cout << "Среднее арифметическое: " << Sa << std::endl;
	std::cout << "befor:" << std::endl;
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}
	int Na = N-1;
	int tmp;
	for (int i = 0; i < N; ++i) {
		if (i >= Na){
			break;
		}
		while (Arr[i] > Sa) {
			tmp = Arr[i];
			Arr[i] = Arr[Na];
			Arr[Na] = tmp;
			--Na;
		}
	}
	std::cout << std::endl;
	std::cout << "after:" << std::endl;
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}*/
	//Нахождение элемента повторяющегося наибольшее количество раз (без упорядочивания в определённом диапозоне (100))
	/*int k = 0; int R = 0, t = 0;
	const int N = 20;
	int n = 0;
	int Arr[N], All[100];
	for (int i = 0; i < 100; ++i) {
		All[i] = 0;
	}
	for (int i = 0; i < N; ++i) {
		Arr[i] = rand()%100;
	}
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < N; ++i) {
		t = Arr[i];
		All[t]++;
	}
	for (int i = 0; i < 100; ++i) {
		if (All[i] >= k) {
			k = All[i];
			R = i;
		}
	}
	for (int i = 0; i < 100; ++i) {
		std::cout << All[i] << " ";
	}
	std::cout << "result = " << R;
	*/
	//Нахождение элемента повторяющегося наибольшее количество раз (с упорядочиванием)
	/*const int N = 30;
	int Arr[N];
	for (int i = 0; i < N; ++i) {
		Arr[i] = rand();
	}
	std::cout << "Неотсортированный массив" << std::endl;
	for (int i = 0; i < N; ++i) {
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
	int temp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (Arr[j] > Arr[j + 1]) {
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
			}
		}
	}
	std::cout << "Отсортированный массив" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
	int k = 1, kmax = 0, R = 0;
	for (int i = 1; i < N; i++) {
		if (Arr[i] == Arr[i - 1]) {
			k++;
			if (k >= kmax) {
				kmax = k;
				R = Arr[i];
			}
		}
		else {
			k = 1;
		}
	}
	std::cout << "result = " << R << std::endl;*/
	//Объедтнение двух массивов попарно в один
	/*const int N = 10;
	int Arr1[N], Arr2[N], Arr3[2 * N];
	for (int i = 0; i < N; ++i) {
		Arr1[i] = rand() % 100 + 50;
	}
	std::cout << "Arr1: ";
	for (int i = 0; i < N; ++i) {
		std::cout << Arr1[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < N; ++i) {
		Arr2[i] = rand() % 50;
	}
	std::cout << "Arr2: ";
	for (int i = 0; i < N; ++i) {
		std::cout << Arr2[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < N; ++i) {
		Arr3[2*i] = Arr1[i];
	}
	for (int i = 0; i < N; ++i) {
		Arr3[2*i+1] = Arr2[i];
	}
	std::cout << "Arr3: ";
	for (int i = 0; i < 2*N; ++i) {
		std::cout << Arr3[i] << " ";
	}*/
	//Создание и заполнение двумерного массива случайными числами
	/*const int R = 3, C = 4;
	int Arr[R][C];
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			Arr[i][j] = rand();
		}
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cout << Arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}*/
	//Перестановка строк в массиве в обратном порядке
	/*const int R = 5, C = 5;
	int Arr[R][C];
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			Arr[i][j] = rand();
		}
	}
	std::cout<< "before:" << std::endl;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cout << Arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	int tmp;
	for (int i = 0; i < R/2; ++i) {
		for (int j = 0; j < C; ++j) {
			tmp = Arr[i][j];
			Arr[i][j] = Arr[R - 1 - i][j];
			Arr[R-1-i][j] = tmp;
		}
	}
	std::cout << "after:" << std::endl;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cout << Arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}*/
}
