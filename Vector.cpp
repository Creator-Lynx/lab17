#include "Vector.h"
#include <exception>

template <class T>
vector<T>::vector(size_t size, const T& value) {
	_size = size;
	_capacity = size ? size : 1;
	_head = new T[_capacity];
	for (size_t i = 0; i < _size; i++) {
		*(_head + i) = value;
	}

}
template <class T>
vector<T>::vector(vector<T>& r) : _size(r._size), _capacity(r._capacity) {
	_head = new T[_capacity];
	for (size_t i = 0; i < _size; i++) {
		*(_head + i) = *(r._head + i);
	}
}
template <class T>
vector<T>::~vector() {
	delete[] _head;
	_head = nullptr;
}

template <class T>
vector<T>& vector<T>::operator=(const vector<T>& r) {
	if (this == &r) return *this;
	delete[] _head;
	_size = r._size;
	_capacity = r._capacity;
	_head = new T[_capacity];
	for (size_t i = 0; i < _size; i++) {
		*(_head + i) = *(r._head + i);
	}
	return *this;
}

template <class T>
void vector<T>::push_back(const T& value) {
	if (_size < _capacity) {
		*(_head + _size++) = value;
		return;
	}
	
	_capacity *= 2;
	T* tmp = new T[_capacity];
	for (size_t i = 0; i < _size; i++) {
		*(tmp + i) = *(_head + i);
	}
	delete[] _head;
	_head = tmp;
	*(_head + _size++) = value;
}

template <class T>
size_t vector<T>::size() const {
	return _size;
}

template<class T>
T& vector<T>::operator[](size_t i) const {
	return *(_head + i);
}

template<class T>
T& vector<T>::at(size_t i) const {
	if (i >= _size) {
		throw std::exception("at: required index >= size of vector");
	}
	return *(_head + i);
}

template<class T>
void vector<T>::insert(size_t i, const T& value) {
	if (i >= _size) {
		throw std::exception("insert: required index >= size of vector");
	}
	push_back(*(_head + _size - 1));
	for (size_t j = _size - 2; j > i; j--) {
		*(_head + j) = *(_head + j - 1);
	}
	*(_head + i) = value;
}

template<class T>
void vector<T>::erase(size_t i) {
	if (i >= _size) {
		throw std::exception("erase: required index >= size of vector");
	}
	_size--;
	for (size_t j = i; j < _size; j++) {
		*(_head + j) = *(_head + j + 1);
	}
	
}


