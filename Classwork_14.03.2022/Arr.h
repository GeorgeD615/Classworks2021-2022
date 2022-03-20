#pragma once

template <typename T>
class Arr {
private:
    size_t size_;
    T* storage_;
    T* m_cur_marker;
public:
    Arr();
    Arr(size_t S);
    ~Arr();
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    size_t GetSIZE() const;
    void PrintArrInformation() const;
    void ExportArrInFile(const char* NameOfFile = "") const;
    void AddElement(T el);
    void RemoveElement(size_t index);

    T& GetCurValue();
    void Move2Next();
    void rewind();
    bool canMove2Next();

};

template <typename T> Arr<T>::Arr() {
    size_ = 0;
    storage_ = nullptr;
    m_cur_marker = nullptr;
}

template <typename T> Arr<T>::Arr(size_t S) {
    size_ = S;
    storage_ = new T[S];
    m_cur_marker = storage_;
}

template <typename T> Arr<T>::~Arr() {
    if (storage_ != 0) {
        delete[] storage_;
    }
}



template <typename T> const T& Arr<T>::operator[](size_t index) const{
    if (size_ > 0) {
        if (index <= size_) {
            return (storage_[index]);
        }
        else {
            return (storage_[0]);
        }
    }
    else {
        std::cout << "Empty!" << std::endl;
        T A;
        return A;
    }
}
template <typename T>  T& Arr<T>::operator[](size_t index) {
    if (size_ > 0) {
        if (index <= size_) {
            return (storage_[index]);
        }
        else {
            return (storage_[0]);
        }
    }
    else {
        std::cout << "Empty!" << std::endl;
        T A;
        return A;
    }
}


template <typename T> size_t Arr<T>::GetSIZE() const {
    return size_;
}

template <typename T> void Arr<T>::PrintArrInformation() const {
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
    delete[] storage_;
    storage_ = new T[size_ + 1];
    for (size_t i = 0; i < size_ + 1; ++i) {
        storage_[i] = tArr[i];
    }
    ++size_;
    delete[] tArr;
}


template <typename T> void Arr<T>::RemoveElement(size_t index) {
    if (index < size_) {
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
        std::cout << "Successfully exported." << std::endl;
    }
    else {
        std::cout << "File didn't open" << std::endl;
    }
    outFile.close();
}

template <typename T> T& Arr<T>::GetCurValue()  {
    return *m_cur_marker;
}

template <typename T> void Arr<T>::Move2Next() {
    ++m_cur_marker;
}

template <typename T> void Arr<T>::rewind() {
    m_cur_marker = storage_;
}

template <typename T> bool Arr<T>::canMove2Next() {
   if (m_cur_marker + 1 > &storage_[GetSIZE()-1]){
       return false;
   }
   else {
       return true; 
   }
}