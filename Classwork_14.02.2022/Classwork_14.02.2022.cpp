#include <iostream>

struct Arr {
    size_t size;
    int* storage;
};

int& GetElement(Arr a, size_t index) {
    if (index <= a.size) {
        return (a.storage[index]);
    }
    else {
        std::cout << "This element doesn't exist (return first element)" << std::endl;
        return (a.storage[0]);
    }
}

void PrintArrInformation(Arr a) {
    std::cout << "Size of storage: " << a.size << std::endl;
    std::cout << "Storage: ";
    for (int i = 0; i < a.size; ++i) {
        std::cout << a.storage[i] << ' ';
    }
    std::cout << std::endl;
}

void FillStorageRand(Arr& a) {
    for (int i = 0; i < a.size; ++i) {
        a.storage[i] = rand() % 10;
    }
}

void FillStorageConst(Arr& a, int con) {
    for (int i = 0; i < a.size; ++i) {
        a.storage[i] = con;
    }
}

void AddElement(Arr &a,int el) {
    int* tArr = new int[a.size + 1];
    for (int i = 0; i < a.size; ++i) {
        tArr[i] = a.storage[i];
    }
    tArr[a.size] = el;
    a.storage = tArr;
    ++a.size;
}

int RemoveElement(Arr &a, size_t index) {
    int delEl = -1;
    if (index <= a.size) {
        delEl = a.storage[index];
        int* tArr = new int[a.size - 1];
        for (int i = 0; i < index; ++i) {
            tArr[i] = a.storage[i];
        }
        for (int i = index + 1; i < a.size; ++i) {
            tArr[i - 1] = a.storage[i];
        }
        a.storage = tArr;
        --a.size;
        return delEl;
    }
    else {
        std::cout << "This element doesn't exist" << std::endl;
        return delEl;
    }
}

void ResizeStorage(Arr &a, size_t S) {
    int* tArr = new int[S];
    for (int i = 0; i < S; ++i) 
        if (i < a.size)
            tArr[i] = a.storage[i];
        else
            tArr[i] = 0;
    a.storage = tArr;
    a.size = S;
}

//Тесты

void GetElementTest(Arr a) {
    int success = 0, fail = 0;
    for (int i = 0; i < a.size; ++i) {
        if (a.storage[i] == GetElement(a, i))
            ++success;
        else
            ++fail;
    }
    std::cout << "The test was failed " << fail << " times" << std::endl;
    std::cout << "The test was successful " << success << " times" << std::endl;
}

void AddElementTest(Arr a, int el) {
    int success = 0, fail = 0;
    int* tArr = new int[a.size];
    tArr = a.storage;
    AddElement(a, el);
    for (int i = 0; i < a.size-1; ++i) {
        if (tArr[i] == a.storage[i])
            ++success;
        else
            ++fail;
    }
    if (a.storage[a.size-1] == el) 
        ++success;
    else
        ++fail;
    std::cout << "The test was failed " << fail << " times" << std::endl;
    std::cout << "The test was successful " << success << " times" << std::endl;
}

void RemoveElementTest(Arr a, size_t index) {
    int DelEl = a.storage[index];
    if (DelEl == RemoveElement(a, index))
        std::cout << "Test passed" << std::endl;
    else
        std::cout << "Test failed" << std::endl;
}

void ResizeStorageTest(Arr a, size_t S) {
    ResizeStorage(a, S);
    if (a.size == S)
        std::cout << "Test passed" << std::endl;
    else
        std::cout << "Test failed" << std::endl;
}

int main()
{
    /*
    Arr store;
    std::cout << "Input size of storage: ";
    std::cin >> store.size;
    store.storage = new int[store.size];
    FillStorageRand(store);
    PrintArrInformation(store);
    std::cout << std::endl;

    //Взять элемент
    size_t num;
    std::cout << "What element you want to get: ";
    std::cin >> num;
    std::cout << "Your element is: " << GetElement(store, num-1) << std::endl;
    std::cout << std::endl;

    //Добавить элемент
    int el;
    std::cout << "What element you want to add: ";
    std::cin >> el;
    AddElement(store, el);
    PrintArrInformation(store);
    std::cout << std::endl;

    //Удалить элемент
    int ind;
    std::cout << "What element you want to remove: ";
    std::cin >> ind;
    std::cout << "Element what you remove: " << RemoveElement(store, ind-1) << std::endl;
    PrintArrInformation(store);
    std::cout << std::endl;
    
    //Измнить размер
    int S;
    std::cout << "What size you want to assign: ";
    std::cin >> S;
    ResizeStorage(store, S);
    PrintArrInformation(store);
    std::cout << std::endl;
    */

    //Тесты

    Arr a,b,c;
    a.size = 10; a.storage = new int[a.size];
    b.size = 1; b.storage = new int[b.size];
    c.size = 100; c.storage = new int[c.size];

    FillStorageConst(a, 5);
    FillStorageRand(b);
    FillStorageRand(c);

    PrintArrInformation(a);
    PrintArrInformation(b);
    PrintArrInformation(c);
    std::cout << std::endl;

    std::cout << "GetElementTest:" << std::endl;
    GetElementTest(a);
    GetElementTest(b);
    GetElementTest(c);
    std::cout << std::endl;

    std::cout << "AddElementTest:" << std::endl;
    AddElementTest(a, 10);
    AddElementTest(b, 100);
    AddElementTest(c, 1000);
    std::cout << std::endl;

    std::cout << "RemoveElementTest:" << std::endl;
    RemoveElementTest(a, 3);
    RemoveElementTest(b, 1);
    RemoveElementTest(c, 34);
    std::cout << std::endl;

    std::cout << "ResizeStorageTest:" << std::endl;
    ResizeStorageTest(a, 5);
    ResizeStorageTest(b, 7);
    ResizeStorageTest(a, 0);
    std::cout << std::endl;
}
