#pragma once

struct BadSize {};

template <typename T>
class Arr {
private:
    size_t size_;
    T* storage_;
public:
    Arr();
    Arr(int S);
    ~Arr();
    Arr(const Arr<T>& X) {
        size_t Len = size_ + 1;
        storage_ = new T[Len];
    }
    void NULLStorage() {
        storage_ = nullptr;
        size_ = 0;
    }
    const T& GetElement(int index) const;
    T& GetElement(int index);
    T& operator[](int index);
    size_t GetSIZE() const;
    void PrintArrInformation() const;
    void ExportArrInFile(const char* NameOfFile = "") const;
    void AddElement(T el);
    void RemoveElement(size_t index);
};

template <typename T> Arr<T>::Arr() {
    size_ = 0;
    storage_ = nullptr;
}

template <typename T> Arr<T>::Arr(int S) {
    if (S > -1) {
        size_ = S;
        storage_ = new T[S];
    }
    else {
        throw BadSize();
    }
}

template <typename T> Arr<T>::~Arr() {
    if (storage_ != 0) {
        delete[] storage_;
    }

}

template <typename T> T& Arr<T>::GetElement(int index) {
    if ((index <= size_) || (index > 0))
        return (storage_[index]);
    throw BadSize();
}
template <typename T> const T& Arr<T>::GetElement(int index) const {
    if ((index <= size_) || (index > 0))
        return (storage_[index]);
    throw BadSize();
}

template <typename T> T& Arr<T>::operator[](int index) {
    if ((index <= size_) || (index > 0))
        return (storage_[index]);
    throw BadSize();
}


template <typename T> size_t Arr<T>::GetSIZE() const {
    return size_;
}

template <typename T> void Arr<T>::PrintArrInformation() const {
    //std::cout << "Size of storage: " << size_ << std::endl;
    //std::cout << "Storage: ";
    for (int i = 0; i < size_; ++i) {
        std::cout << storage_[i] << std::endl;
    }
}

template <typename T> void Arr<T>::AddElement(T el) {
    T* tArr = new T[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
        tArr[i] = storage_[i];
    }
    tArr[size_] = el;
    delete storage_;
    storage_ = new T[size_ + 1];
    for (size_t i = 0; i < size_ + 1; ++i) {
        storage_[i] = tArr[i];
    }
    ++size_;
    delete[] tArr;
}


template <typename T> void Arr<T>::RemoveElement(size_t index) {
    T delEl;
    if (index <= size_) {
        delEl = storage_[index];
        T* tArr = new T[size_ - 1];
        for (int i = 0; i < index; ++i) {
            tArr[i] = storage_[i];
        }
        for (int i = index + 1; i < size_; ++i) {
            tArr[i - 1] = storage_[i];
        }
        delete[] storage_;
        storage_ = new T[size_ - 1];
        for (size_t i = 0; i < size_ - 1; ++i) {
            storage_[i] = tArr[i];
        }
        --size_;
        delete[] tArr;
    }
    else {
        std::cout << "This element doesn't exist" << std::endl;
    }
}
template <typename T> void Arr<T>::ExportArrInFile(const char* NameOfFile) const {
    std::ofstream outFile(NameOfFile, std::ios_base::binary);
    if (outFile) {
        for (size_t i = 0; i < size_; ++i)
            outFile << storage_[i] << std::endl;
    }
    else {
        std::cout << "File didn't open" << std::endl;
    }
    outFile.close();
}