#include "Pair.h"

Pair::Pair() {
    this->x = this->y = 0;
}

Pair::Pair(int _x, int _y) {
    this->x = _x;
    this->y = _y;
}

Pair::~Pair() {
   this-> x = this->y = 0;
}

int Pair::first() const {
    return this->x;
}

int Pair::second() const {
    return this->y;
}