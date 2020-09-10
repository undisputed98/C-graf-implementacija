#include "Stack.h"
#include "Vector.h"
#include <iostream>


Stack::Stack() : Vector(0), min_resize(5) { }

Stack::Stack(unsigned size, unsigned min) : Vector(size), min_resize(min) { }

Stack::Stack(Stack &s) : Vector(s), min_resize(s.min_resize) { }

void Stack::push(int x) {
	if (_length == _capacity) {
		resize(_capacity + min_resize, 0);
	}
	elements[_length++] = x;
}

void Stack::pop() {
	if (!empty()) {
		_length--;
	}
}

int Stack::peek() const {
	return elements[_length - 1];
}