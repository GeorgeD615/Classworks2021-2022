#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    //Вывод аргументов командной строки
    std::cout << "My arguments: " << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << i << " - " << argv[i] << std::endl;
    }
    
    //Поменять местами ширину и высоту файла
    int width = 0, height = 0;
    std::ifstream File1;//640x480
    File1.open(argv[1], std::ios_base::binary);
    File1.seekg(18);
    File1.read((char *) &width, sizeof(int));
    File1.read((char *) &height, sizeof(int));
    std::cout << "Width = "<< width << " Heidth = " << height << std::endl;
    std::ofstream File2;//480x640
    File2.open(argv[2], std::ios_base::binary | std::ios_base::trunc);
    const int filesize = 38462;
    File1.seekg(2);
    File1.read((char *) &filesize, sizeof(int));
    int buffer[filesize];
    File1.seekg(std::ios::beg);
    File1.read((char *) &buffer, filesize * sizeof(char));
    File2.write((char *) &buffer, filesize * sizeof(char));
    File2.seekp(18);
    File2.write((char *) &height, sizeof(int));
    File2.write((char *) &width, sizeof(int));
    File2.close();
    File1.close();
    std::cout << "File " << argv[2] << " changed" << std::endl;
    
    //Представление BMP файла в виде 0 и 1
    std::ifstream fileWithPicture;
    fileWithPicture.open(argv[3], std::ios_base::binary);
    fileWithPicture.seekg(18);
    int WidthFWP = 0, HeightFWP = 0;

    fileWithPicture.read((char*)&WidthFWP, sizeof(int));
    fileWithPicture.read((char*)&HeightFWP, sizeof(int));

    std::cout << "Width of file with picture: " << WidthFWP << std::endl;
    std::cout << "Height of file with picture: " << HeightFWP << std::endl;
    fileWithPicture.seekg(10);
    unsigned int bitOff = 0;
    fileWithPicture.read((char*)&bitOff, sizeof(int));
    std::cout << "Read bitOff " << bitOff << std::endl;

    unsigned int bpp = 0;
    fileWithPicture.seekg(28);
    fileWithPicture.read((char*)&bpp, sizeof(int));
    std::cout << "BPP " << bpp << std::endl;

    fileWithPicture.seekg(bitOff);
    for (size_t rows = 0; rows < HeightFWP; ++rows) {
        for (size_t cols = 0; cols < WidthFWP; cols += 8) {
            unsigned char bTmp = 0;
            if (fileWithPicture.eof()) {
                break;
            }
            fileWithPicture.read((char*)&bTmp, bpp);
            //01000000
            //11000100
            for (unsigned char mask = 0x80; mask != 0; mask>>=1) {
                std::cout << (((bTmp & mask) == 0) ? 1 : 0);
            }
        }
        std::cout << std::endl;
    }
    fileWithPicture.close();
    
    //Вставить один BMP файл в другой
    /*std::ifstream Picture;
    std::ifstream Collage;
    Picture.open(argv[4], std::ios_base::binary);
    Collage.open(argv[5], std::ios_base::binary);
    unsigned int Width1 = 0;
    unsigned int Height1 = 0;
    Picture.seekg(18, std::ios_base::beg);
    Picture.read((char*)&Width1, sizeof(int));
    Picture.read((char*)&Height1, sizeof(int));
    unsigned int Width2 = 0;
    unsigned int Height2 = 0;
    Collage.seekg(18, std::ios_base::beg);
    Collage.read((char*)&Width2, sizeof(int));
    Collage.read((char*)&Height2, sizeof(int));
    Collage.close();
    std::cout << Width1 << " " << Height1 << std::endl;
    std::cout << Width2 << " " << Height2 << std::endl;
    std::ifstream Collage;
    Collage.open(argv[5], std::ios_base::binary | std::ios_base::in);
    if (!Collage.is_open()) {
        std::cout << "failed to open";
        return 0;
    }
    char byte;
    for (int i = 1; i <= Height1; i++) {
        for (int j = 0; i < Width1; j++) {
            int k = (-i) * Width1 - j;
            int l = (-i) * Width2 - j;
            Picture.seekg(k, std::ios_base::end);
            Picture.read(&byte, 1);
            Collage.seekp(l, std::ios_base::end);
            Collage.write(&byte, 1);
        }
    }
    */

}