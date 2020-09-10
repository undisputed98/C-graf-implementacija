#ifndef _PAIR_H
#define _PAIR_H

class Pair {
public:
    int x, y;
    Pair();
    Pair(int, int);
    int first() const;
    int second() const;
    ~Pair(); 
};

#endif
