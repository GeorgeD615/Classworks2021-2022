#include <iostream>
#include <fstream>


int main(int argc, char* argv[])
{
    //Вывод аргументов командной строки
    std::cout << "My arguments: " << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << i << " - " << argv[i] << std::endl;
    }

    //Чтение ширины и высоты BMP файла
    std::ifstream fileWithPicture;
    fileWithPicture.open(argv[1],std::ios_base::binary);
    fileWithPicture.seekg(18);
    int Width = 0, Height = 0;

    fileWithPicture.read((char*)&Width, sizeof(int));
    fileWithPicture.read((char*)&Height, sizeof(int));

    std::cout << "Width = " << Width << std::endl;
    std::cout << "Height = " << Height << std::endl;

    fileWithPicture.seekg(std::ios_base::beg); // вернули указатель get в начало
    //Поменять местами ширину и высоту
    /*
    std::ofstream EmptyPicture;
    EmptyPicture.open(argv[2], std::ios_base::binary);

    EmptyPicture.seekp(18);

    EmptyPicture.write((char*)&Height, sizeof(int));
    EmptyPicture.write((char*)&Width, sizeof(int));

    EmptyPicture.seekp(std::ios_base::beg);// вернули указатель put в начало
    int c = 0;
    while (!fileWithPicture.eof() || !EmptyPicture.eof()) {
        if (EmptyPicture.tellp() != 18 || EmptyPicture.tellp() != 19 || fileWithPicture.tellg()!=18 || fileWithPicture.tellg() != 19) {
            fileWithPicture.seekg(1, std::ios_base::cur);
            EmptyPicture.seekp(1, std::ios_base::cur);
        }
        c = fileWithPicture.get();
        EmptyPicture.put(c);
    }
    */
    //Представление BMP файла в виде 0 и 1
    fileWithPicture.seekg(10);
    unsigned int bitOff = 0;
    fileWithPicture.read((char*)&bitOff, sizeof(int));
    std::cout << "Read bitOff " << bitOff << std::endl;

    unsigned int bpp = 0;
    fileWithPicture.seekg(28);
    fileWithPicture.read((char*)&bpp, sizeof(int));
    std::cout << "BPP " << bpp << std::endl;

    fileWithPicture.seekg(bitOff);
    for (size_t rows = 0; rows < Width; ++rows) {
        for (size_t cols = 0; cols < Height; cols += 8) {
            unsigned char bTmp = 0;
            if (fileWithPicture.eof()) {
                break;
            }
            fileWithPicture.read((char*)&bTmp, bpp);
            
            for (unsigned char mask = 0x80; mask != 0; mask>>=1) {
                std::cout << (((bTmp & mask) == 0) ? 1 : 0);
            }
        }
        std::cout << std::endl;
    }


}