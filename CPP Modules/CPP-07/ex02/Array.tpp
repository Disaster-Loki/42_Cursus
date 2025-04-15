template <typename T>
Array<T>::Array() : array(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), length(n) {}

template <typename T>
Array<T>::~Array() {
    delete[] array;
}

template <typename T>
Array<T>::Array(const Array& copy)
: array(new T[copy.length]), length(copy.length) {
    for (unsigned int i = 0; i < length; ++i)
        array[i] = copy.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy) {
    if (this != &copy) {
        delete[] array;
        length = copy.length;
        array = new T[length];
        for (unsigned int i = 0; i < length; ++i)
            array[i] = copy.array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= length)
        throw std::out_of_range("Index out of range");
    return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= length)
        throw std::out_of_range("Index out of range");
    return array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return length;
}
