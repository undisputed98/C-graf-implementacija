#include "Vector.h"
#include "Pair.h"


template<class T>
Vector<T>::Vector()
	:_length(0), elements(0), _capacity(0)
{}

template<class T>
inline Vector<T>::Vector(const unsigned s)
	:_length(s), _capacity(s){
	if (_capacity == 0) {
		elements = NULL;
	}
	for (int index = 0; index < _length; ++index) {
		elements[index] = T();
	}
}

template<class T>
inline Vector<T>::Vector(const Vector & arg)
	:_length(arg._length), elements(new T[arg._length]), _capacity(arg._capacity) {
	for (int index = 0; index < arg._length; ++index) {
		elements[index] = arg.elements[index];
	}
}

template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& a) {
	if (a._length <= _capacity) {
		for (int index = 0; index < a._length; ++index) {
			elements[index] = a.elements[index];
			_length = a._length;
			return *this;
		}
	}

	T* p = new T[a._length];

	for (int index = 0; index < a._length; ++index) {
		p[index] = a.elements[index];
	}

	delete[] elements;
	_length = a._length;
	_capacity = a._length;
	elements = p;
	return *this;
}

template<class T>
Vector<T>::~Vector() {
	if (elements == NULL) {
		return;
	}
	_capacity = _length = 0;
	delete[] elements;
}

template<class T>
inline bool Vector<T>::empty() const {
	return (_length == 0);
}

template<class T>
inline bool Vector<T>::full() const {
	return (_length == _capacity);
}

template<class T>
inline void Vector<T>::reserve(int newalloc) {
	if (newalloc <= _capacity) return;
	T* p = new T[newalloc];

	for (int i = 0; i < _length; ++i) {
		p[i] = elements[i];
	}

	delete[] elements;

	elements = p;
	_capacity = newalloc;
}


template<class T>
unsigned Vector<T>::length() const {
	return _length;
}

template< class T> 
unsigned Vector<T> :: capacity() const {
	return _capacity;
}


template<class T>
inline void Vector<T>::push_back(const T& d) {
	if (_capacity == 0) {
		reserve(2);
	}
	else if (_length == _capacity) {
		reserve(2 * _capacity);
	}

	elements[_length] = d;
	++_length;
}



template<class T>
inline T & Vector<T>::operator[](int i) const {
	return elements[i];
}

template<class T>
inline T& Vector<T>::front() const {
	return elements[0];
}


template<class T>
inline T& Vector<T>::back() const {
	return elements[_length - 1];
}

template<class T>
inline void Vector<T>::resize(int newsize, T val) {
	reserve(newsize);
	for (int index = _length; index < newsize; ++index)
		elements[index] = T();

	_capacity = newsize;
}

template class Vector<int>;
template class Vector<Pair>;
template class Vector<Vector<int> >;
template class Vector<Vector<Pair> >;