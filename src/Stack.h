#ifndef _STACK_H
#define _STACK_H

#include "Vector.h"

class Stack : public Vector<int> {
	const unsigned min_resize;
public:
	Stack();
	Stack(unsigned, unsigned = 5);
	Stack(Stack&);
	void push(int);
	void pop();
	int peek() const;
};

#endif // _STACK_H