#pragma once

#include <cstring>

template<class T> 
class Vector {
protected:
    unsigned	_length;		// number of elements
	T*		elements;	// pointer to first element
	unsigned	_capacity;		// total space (elements and free space)
public:
	Vector();
	Vector(const unsigned);
	Vector(const Vector<T>&); // copy contructor
	Vector<T>& operator=(const Vector<T>&);
	~Vector();

	bool empty() const;
	bool full() const;

	void reserve(int);
	void resize(int, T);

	unsigned length() const;
	unsigned capacity() const;
	void push_back(const T&);
	void pop_back();

	T& operator[](int) const;
	T& front() const;
	T& back() const;
};

