#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <chrono>

int main()
{
    auto start = std::chrono::steady_clock::now();//Вычисление времени работы программы (1 маркер)

    std::mt19937 gen(time(0));
    std::uniform_real_distribution<> urd(0, 100); //Генерация случайного вещественного значения в диапозоне от 0 до 100
    //std::cout << urd(gen) << std::endl;//Случайное вещественное значение
    //std::cin.get();
    /*char c = fs.get();
      std::cout << c << std::endl;
      c = fs.get();
      std::cout << c << std::endl;
      c = fs.get();
      std::cout << c << std::endl;
      c = fs.get();*/
    /*fs.put('1');
    fs.put('2');
    fs.put('3');*/
    //Побайтовое копирование из одного файла в другой
    /*std::fstream fs_1;
    std::fstream fs_2;
    fs_1.open("C:\\Users\\OMEN\\Desktop\\file_1.txt");
    fs_2.open("C:\\Users\\OMEN\\Desktop\\file_2.txt");

    if (fs_1.is_open() && fs_1.is_open()) {
        std::cout << "File opened " << std::endl;
        while (!fs_1.eof()) { // Копирование информации из одного файла в другой побайтово
            char c = fs_1.get();
            fs_2.put(c);
        }
        fs_1.close();
        fs_2.close();
    }
    */
    //Отправление массива случайных вещественных чисел в файл и его изъятие из файла
    /*double r = 1000, c = 1000;
    double** arr = new double* [r];//Создание массива, который мы отправим в файл
    for (int i = 0; i < r; ++i) {
        arr[i] = new double[c];
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            arr[i][j] = urd(gen);
        }
    }
    std::cout << "My Array: " << std::endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::fstream fs_3;
    fs_3.open("C:\\Users\\OMEN\\Desktop\\file_3.txt", std::ios_base::out | std::ios_base::trunc); //файл для ввода информации
    if (fs_3.is_open()) {
        for (int i = 0; i < r; ++i) {//Отправление массива в файл
            for (int j = 0; j < c; ++j) {
                fs_3 << arr[i][j] << '\t';
                //fs_3.flush(); //Если вводить элементы массива отправлять одним столбцом (\n)  fs_3.flush() - ускорит передачу массива
            }
            fs_3 << "\n";
        }
        fs_3.close();
    }
    std::cout << "Array from file: " << std::endl;
    fs_3.open("C:\\Users\\OMEN\\Desktop\\file_3.txt", std::ios_base::in); //файл для получения информации
    if (fs_3.is_open()) {
        while (!fs_3.eof()) {//Поучение массива из файла
            char c = fs_3.get();
            std::cout << c;
        }
        fs_3.close();
    }
    */
    auto end = std::chrono::steady_clock::now();//Вычисление времени работы программы (2 маркер)
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    //Есть произвольный файл, представить его в виде нулей и единиц (побайтово). Пользователь задаёт некоторые размеры - высоту и ширину картинки. Полученные нули единицы представить в виде картинки с заданными размерами, где 1 - *; 0 - (space).
    //
}


