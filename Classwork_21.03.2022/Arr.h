#pragma once

template <typename T>
class Marker {
private:
    T* m_cur_marker;
    T* m_storage;
    size_t m_size;
public:
    void Set_m_cur_marker(T* storage) { m_cur_marker = storage; }
    void Set_m_storage(T* storage) { m_storage = storage; }
    void Set_m_size(size_t size) { m_size = size; }
    Marker(T* storage_, size_t size_) {
        m_cur_marker = storage_;
        m_storage = storage_;
        m_size = size_;
    }
    Marker() {
        m_cur_marker = nullptr;
        m_storage = nullptr;
        m_size = 0;
    }
    T& GetCurValue() const { return *m_cur_marker; }
    void Move2Next() { ++m_cur_marker; }
    void Move2Prev() { --m_cur_marker; }
    void rewind() { m_cur_marker = m_storage; }
    void ff() { m_cur_marker = m_storage[m_size]; }
    bool canMove2Next() const { return m_cur_marker < m_storage + m_size; }
    bool canMove2Prev() const { return m_cur_marker < m_storage; }
};

template <typename T>
class Arr {
private:
    size_t size_;
    T* storage_;
    Marker<T> m;
public:
    Arr();
    Arr(size_t S);
    ~Arr();
    const T& GetElement(size_t index) const;
    T& GetElement(size_t index);
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    size_t GetSIZE() const;
    void PrintArrInformation() const;
    void ExportArrInFile(const char* NameOfFile = "") const;
    void AddElement(T el);
    void RemoveElement(size_t index);
    void PrintWithMarker();
    template <typename T>
    friend class Marker; 
};

template <typename T> Arr<T>::Arr() {
    size_ = 0;
    storage_ = nullptr;
    m.Set_m_cur_marker(storage_);
    m.Set_m_storage(storage_);
    m.Set_m_size(size_);
}
template <typename T> Arr<T>::Arr(size_t S) {
    size_ = S;
    storage_ = new T[S];
    m.Set_m_cur_marker(storage_);
    m.Set_m_storage(storage_);
    m.Set_m_size(size_);
}
template <typename T> Arr<T>::~Arr() {
    if (storage_ != 0) {
        delete[] storage_;
    }

}
template <typename T> T& Arr<T>::GetElement(size_t index) {
    if (index >= size_) throw "Out of array's bounds";
    return storage_[index];
}
template <typename T> const T& Arr<T>::GetElement(size_t index) const {
    if (index >= size_) throw "Out of array's bounds";
    return storage_[index];
}
template <typename T> const T& Arr<T>::operator[](size_t index) const {
    if (index >= size_) throw "Out of array's bounds";
    return storage_[index];
}
template <typename T>  T& Arr<T>::operator[](size_t index) {
    if (index >= size_) throw "Out of array's bounds";
    return storage_[index];
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
    if (index >= size_) throw "Out of array's bounds";
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
template <typename T> void Arr<T>::PrintWithMarker() {
    while (m.canMove2Next()) {
        std::cout << m.GetCurValue() << std::endl;
        m.Move2Next();
    }
}
//template <typename T>
//class Arr {
//private:
//    size_t size_;
//    T* storage_;
//    Marker<T> m;
//public:
//    Arr();
//    Arr(size_t S);
//    ~Arr();
//    const T& operator[](size_t index) const;
//    T& operator[](size_t index);
//    size_t GetSIZE() const;
//    void PrintArrInformation const();
//    void ExportArrInFile(const char* NameOfFile = "") const;
//    void AddElement(T el);
//    void RemoveElement(size_t index);
//};
//template <typename T> Arr<T>::Arr() {
//    size_ = 0;
//    storage_ = nullptr;
//}
//
//template <typename T> Arr<T>::Arr(size_t S) {
//    size_ = S;
//    storage_ = new T[S];
//}
//
//template <typename T> Arr<T>::~Arr() {
//    if (storage_ != 0) {
//        delete[] storage_;
//    }
//
//}
//
//template <typename T> T& Arr<T>::GetElement(size_t index) {
//    if (index >= size_) throw "Out of array's bounds";
//    return storage_[index];
//}
//template <typename T> const T& Arr<T>::GetElement(size_t index) const {
//    if (index >= size_) throw "Out of array's bounds";
//    return storage_[index];
//}
//
//template <typename T> const T& Arr<T>::operator[](size_t index) const {
//    if (index >= size_) throw "Out of array's bounds";
//    return storage_[index];
//}
//template <typename T>  T& Arr<T>::operator[](size_t index) {
//    if (index >= size_) throw "Out of array's bounds";
//    return storage_[index];
//}
//
//
//template <typename T> size_t Arr<T>::GetSIZE() const {
//    return size_;
//}
//
//template <typename T> void Arr<T>::PrintArrInformation() const {
//    for (int i = 0; i < size_; ++i) {
//        std::cout << storage_[i] << std::endl;
//    }
//}
//
//template <typename T> void Arr<T>::AddElement(T el) {
//    T* tArr = new T[size_ + 1];
//    for (size_t i = 0; i < size_; ++i) {
//        tArr[i] = storage_[i];
//    }
//    tArr[size_] = el;
//    delete[] storage_;
//    storage_ = new T[size_ + 1];
//    for (size_t i = 0; i < size_ + 1; ++i) {
//        storage_[i] = tArr[i];
//    }
//    ++size_;
//    delete[] tArr;
//}
//
//template <typename T> void Arr<T>::RemoveElement(size_t index) {
//    if (index >= size_) throw "Out of array's bounds";
//    T* tArr = new T[size_ - 1];
//    for (int i = 0; i < index; ++i) {
//        tArr[i] = storage_[i];
//    }
//    for (int i = index + 1; i < size_; ++i) {
//        tArr[i - 1] = storage_[i];
//    }
//    delete[] storage_;
//    storage_ = new T[size_ - 1];
//    for (size_t i = 0; i < size_ - 1; ++i) {
//        storage_[i] = tArr[i];
//    }
//    --size_;
//    delete[] tArr;
//}
//template <typename T> void Arr<T>::ExportArrInFile(const char* NameOfFile) const {
//    std::ofstream outFile(NameOfFile, std::ios_base::binary);
//    if (outFile) {
//        for (size_t i = 0; i < size_; ++i)
//            outFile << storage_[i] << std::endl;
//        std::cout << "Successfully exported." << std::endl;
//    }
//    else {
//        std::cout << "File didn't open" << std::endl;
//    }
//    outFile.close();
//}
//template <typename T> T& Marker<T>::GetCurValue() const {
//    return *m_cur_marker;
//}
//template <typename T> void Marker<T>::Move2Next() {
//    ++m_cur_marker;
//}
//template <typename T> void Marker<T>::Move2Prev() {
//    --m_cur_marker;
//}
//template <typename T> void Marker<T>::rewind() {
//    m_cur_marker = m_storage;
//}
//template <typename T> void Marker<T>::ff() {
//    m_cur_marker = m_storage[m_size];
//}
//template <typename T> bool Marker<T>::canMove2Next() const {
//    return m_cur_marker < m_storage + m_size;
//}
//template <typename T> bool Marker<T>::canMove2Prev() const {
//    return m_cur_marker < m_storage;
//}
