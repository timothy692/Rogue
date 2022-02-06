#ifndef __TILE_H
#define __TILE_H

struct tile {
    public:
    int x, y;
    char ch;
    tile(int xx, int yy, char ch) : x(xx), y(yy), ch(ch) {}
};

#endif