#ifndef __POSITION_H
#define __POSITION_H

class position {
    public:
    int x, y;
    position(const int xx, const int yy) : x(xx), y(yy) {}
    position() : x(0), y(0) {}
    bool operator==(const position other);
    bool operator!=(const position other);
    position operator+(const position other);
};

#endif