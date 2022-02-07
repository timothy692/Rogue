#ifndef __GAME_OBJECT_H
#define __GAME_OBJECT_H

#include <vector>

#include "../map/tile.h"
#include "../map/position.h"

class game_object {
    public:
    std::vector<tile> map_tiles;
    position pos;
    position last_pos;
    int width, height, ch;
    game_object(position pos, int width, int height) : pos(pos), width(width), height(height), last_pos(pos) {}
    /* called on each game tick */
    virtual void update() = 0;
    /* called after update(), updating tiles should be done within this function */
    virtual void update_tiles() = 0;
    void update_key(int ch);
    bool did_move();
};

#endif