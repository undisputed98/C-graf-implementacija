#ifndef _QUEUE_H
#define _QUEUE_H

#include "Vector.h"

class Queue : public Vector<int> {
	const unsigned min_resize, shift_at;
	int start, end;
	void shift();
	bool hasSpace();
public:
	Queue();
	Queue(unsigned, unsigned = 5, unsigned = 6);
	Queue(Queue&);
	void push(int);
	void pop();
	int peek() const;
	bool isEmpty() const;
};

#endif // _QUEUE_H