#pragma once
#ifndef DEBUG
#include <iostream>
#endif // !DEBUG


template <typename T>
class Arr {
public:

    Arr();
    Arr(size_t S);
    ~Arr();

    const T& GetElement(size_t index) const;
    //T& GetElement(size_t index);
    T& operator[](size_t index);
    size_t GetSIZE() const;
    void PrintArrInformation() const;
    void AddElement(T el);
    T RemoveElement(size_t index);

private:
    size_t size;
    T* storage;
};

template <typename T> Arr<T>::Arr() {
    size = 0;
    storage = nullptr;
}

template <typename T> Arr<T>::Arr(size_t S) {
    size = S;
    storage = new T[S];
}

template <typename T> Arr<T>::~Arr() {
    if (storage != 0) {
        delete[] storage;
#ifndef DEBUG
        std::cout << "Destructor" << std::endl;
#endif 
    }

}

//template <typename T> T& Arr<T>::GetElement(size_t index) {
    //if (index <= size) {
        //return (storage[index]);
    //}
    //else {
       //std::cout << "This element doesn't exist (return first element)" << std::endl;
       //return (storage[0]);
    //}
//}
template <typename T> const T& Arr<T>::GetElement(size_t index) const {
    if (index <= size) {
        return (storage[index]);
    }
    else {
        std::cout << "This element doesn't exist (return first element)" << std::endl;
        return (storage[0]);
    }
}

template <typename T> T& Arr<T>::operator[](size_t index) {
    if (index <= size) {
        return (storage[index]);
    }
    else {
        std::cout << "This element doesn't exist (return first element)" << std::endl;
        return (storage[0]);
    }
}


template <typename T> size_t Arr<T>::GetSIZE() const {
    return size;
}

template <typename T> void Arr<T>::PrintArrInformation() const {
    std::cout << "Size of storage: " << size << std::endl;
    std::cout << "Storage: ";
    for (int i = 0; i < size; ++i) {
        std::cout << storage[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T> void Arr<T>::AddElement(T el) {
    T* tArr = new T[size + 1];
    for (size_t i = 0; i < size; ++i) {
        tArr[i] = storage[i];
    }
    tArr[size] = el;
    delete storage;
    storage = new T[size + 1];
    for (size_t i = 0; i < size + 1; ++i) {
        storage[i] = tArr[i];
    }
    ++size;
    delete[] tArr;
}


template <typename T> T Arr<T>::RemoveElement(size_t index) {
    T delEl;
    if (index <= size) {
        delEl = storage[index];
        T* tArr = new T[size - 1];
        for (int i = 0; i < index; ++i) {
            tArr[i] = storage[i];
        }
        for (int i = index + 1; i < size; ++i) {
            tArr[i - 1] = storage[i];
        }
        delete[] storage;
        storage = new T[size - 1];
        for (size_t i = 0; i < size - 1; ++i) {
            storage[i] = tArr[i];
        }
        --size;
        return delEl;
        delete[] tArr;
    }
    else {
        std::cout << "This element doesn't exist" << std::endl;
        return T;
    }
}