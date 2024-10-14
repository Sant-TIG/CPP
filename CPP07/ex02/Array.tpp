#ifndef ARRAY_TPP

# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _data(), _size(0) {
}

template <typename T>
Array<T>::Array( unsigned int size ) : _data(new T[size]()), _size(size) {
}

template <typename T>
Array<T>::Array( const Array &otherArray ) : _data(), _size(size) {
	*this = otherArray;
}

template <typename T>
Array<T>::~Array( void ) {
    delete[] _data;
}

template <typename T>
Array<T> & Array<T>::operator=( const Array &otherArray ) {
    if (this != &otherArray) {
        delete[] _data;

        _size = otherArray._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            _data[i] = otherArray._data[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}
#endif