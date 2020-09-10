#include "Queue.h"

Queue::Queue() : Vector(), min_resize(5), shift_at(7) {
	start = 0;
	end = -1;
}

Queue::Queue(unsigned _length, unsigned min, unsigned shift) : Vector(_length), min_resize(min), shift_at(shift) {
	start = 0;
	end = -1;
}

Queue::Queue(Queue& q) : Vector(q), min_resize(q.min_resize), shift_at(q.shift_at) {
	start = q.start;
	end = q.end;
}

void Queue::push(int x) {
	if (start >= shift_at) {
		shift();
	}
	if (!hasSpace()) {
		resize(_capacity + min_resize, 0);
	}
	elements[++end] = x;
	_length++;
}

void Queue::pop() {
	if (!isEmpty()) {
		start++;
		_length--;
	}
	if (start > shift_at) {
		shift();
	}
}

int Queue::peek() const {
	return elements[start];
}

bool Queue::isEmpty() const {
	return start > end;
}

void Queue::shift() {
	for (unsigned i = start; i <= end; i++) {
		elements[i - shift_at] = elements[i];
	}
	start = 0;
	end -= shift_at;
}

bool Queue::hasSpace() {
	if (_length == _capacity) {
		return false;
	}
	if (start < shift_at && end == _capacity - 1) {
		return false;
	}
	return true;
}