#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	std::cout << "argc - " << argc << std::endl;

	for (size_t i = 0; i < argc; ++i) {
		std::cout << i <<" - " << argv[i] << std::endl;
	}
	
	
	/*char src_file_name[256], dest_file_name[256]; //имена файлов
	std::cout << "Input source file name: ";
	std::cin.getline(src_file_name, 256);//пользователь вводит имя файла из которого будет копировать
	*/
	std::ifstream inFile(argv[1], std::ios_base::binary);//открытие файла в двоичном формате
	if (!inFile) {
		std::cout << "Can not open file " << argv[1] << std::endl;
		return 1;
	}

	/*std::cout << "Input destination file name: ";
	std::cin.getline(dest_file_name, 256);//пользователь вводит имя файла в который будет копировать
	*/

	std::ofstream outFile(argv[2], std::ios_base::binary | std::ios_base::trunc);//открытие файла в двоичном формате
	if (!outFile) {
		std::cout << "Can not open file " << argv[2] << std::endl;
		inFile.close();
		return 2;
	}

	int rows = 5;
	int cols = 5;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			arr[i][j] = rand() % 100;
		}
	}
	std::cout << "My Array:" << std::endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::ofstream ArrFile(argv[3], std::ios_base::binary | std::ios_base::trunc);
	if (!ArrFile) {
		std::cout << "Can not open file " << argv[3] << std::endl;
		inFile.close();
		outFile.close();
		return 3;
	}
	
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int c = arr[i][j];
			ArrFile.write((char*)&c, sizeof(c));
			ArrFile << ' ';
		}
		ArrFile << '\n';
	}
	std::cout << "Array goes to " << argv[3] << std::endl;
	int ch;
	//int count = 0;
	while ((ch = inFile.get()) != EOF) {
		//outFile.put(ch);
		const size_t bufsize = 3;
		char c[bufsize];
		inFile.seekg(0, std::ios_base::end);
		std::cout << "File size " << inFile.tellg() << std::endl;
		inFile.read((char*)c, bufsize *sizeof(int));
		std::cout << "Read " << inFile.gcount() << "bytes" << std::endl;
		std::cout << "Now at position " << inFile.tellg() << std::endl;
		outFile.write((char*)c, bufsize * sizeof(int));
		/*int c = 0;
		inFile.read((char*)&c, sizeof(c));
		std::cout << "Now at position " << inFile.tellg() << std::endl;
		outFile.write((char*)&c, sizeof(c));
		*/
		/*int c[7];
		inFile.read((char*)c, 7*sizeof(int));
		outFile.write((char*)c, 7*sizeof(int));
		*/
		//std::cout << "Read" << c << std::endl;
		//count =+ 4;
	}

	//std::cout << "Copied " << count << " bytes" << std::endl;

	inFile.close();
	outFile.close();
	for (int i = 0; i < rows; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;

	//Получить элемент массива из файла по заданному индексу с помощью указателя
}

