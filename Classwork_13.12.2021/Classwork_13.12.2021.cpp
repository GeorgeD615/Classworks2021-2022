#include <iostream>
#include <fstream>
#include <string>

//Информация о цвете пикселя (монохромное изображение)
bool getPixel(std::string name, size_t width, size_t heigth, size_t row, size_t col) {
    std::ifstream Picture;
    Picture.open(name, std::ios_base::binary);
    if (Picture.is_open()) {
        std::cout << "File with picture opened" << std::endl;
        Picture.seekg(10);
        unsigned int bitOff = 0;
        Picture.read((char*)&bitOff, sizeof(int));
        unsigned int px = 0;
        px += bitOff + 4 * (heigth - row - 1) + (col/8);
        Picture.seekg(px); 
        int byte = Picture.get();
        byte = ((byte >> (8 - col % 8)) & 1);
        if (byte == 1)
            return false;
        else
            return true;

    }
    else {
        std::cout << "Can not open file"<<std::endl;;
    }
}

//Вставить одну картинку в другую 
void insertPicture(std::string name1, std::string name2) {
    std::ifstream image1;
    std::ifstream image2;
    image1.open(name1, std::ios_base::binary | std::ios_base::in);
    image2.open(name2, std::ios_base::binary | std::ios_base::in);
    if (!image1.is_open() || !image2.is_open()) {
        std::cout << "failed to open";
    }
    else {
        unsigned int width1 = 0;
        unsigned int height1 = 0;
        image1.seekg(18, std::ios_base::beg);
        image1.read((char*)&width1, sizeof(int));
        image1.read((char*)&height1, sizeof(int));
        if (width1 % 32 != 0) {
            width1 = width1 + 32 - (width1 % 32);
        }
        unsigned int width2 = 0;
        unsigned int height2 = 0;
        image2.seekg(18, std::ios_base::beg);
        image2.read((char*)&width2, sizeof(int));
        image2.read((char*)&height2, sizeof(int));
        if (width2 % 32 != 0) {
            width2 = width2 + 32 - (width2 % 32);
        }
        std::cout << width1 << " " << height1 << std::endl;
        std::cout << width2 << " " << height2 << std::endl;
        image2.close();

        std::ofstream image2;
        image2.open(name2, std::ios_base::binary | std::ios_base::in | std::ios_base::out);
        if (!image2.is_open()) {
            std::cout << "failed to open";
            return;
        }
        int sizeInBytes1 = width1 / 8;
        int sizeInBytes2 = width2 / 8;
        char* buffer = new char[sizeInBytes1];
        for (int i = 1; i < height1; i++) {
            image1.seekg((-1) * sizeInBytes1 * i, std::ios_base::end);
            image1.read(buffer, sizeInBytes1 * sizeof(char));
            image2.seekp((-1) * sizeInBytes2 * i, std::ios_base::end);
            image2.write(buffer, sizeInBytes1 * sizeof(char));
        }
        delete[] buffer;
        image1.close();
        image2.close();
    }
}


int main(int argc, char *argv[])
{
    std::cout << "My arguments: " << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << i << " - " << argv[i] << std::endl;
    }

    std::string name1 = argv[1]; //меньшая картинка
    std::string name2 = argv[2]; // большая картинка

    insertPicture(name1, name2);


}
