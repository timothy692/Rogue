#ifndef __WALL_H
#define __WALL_H

#include "collidable_object.h"

#define TILE_WALL '#'

class wall : public collidable_object {
    public:
    struct door {
        position pos;
        int width, height;
        door(position pos, int width, int height) : pos(pos), width(width), height(height) {}
    };
    wall(position pos, int width, int height);
    void init() override;
    void update() override;
    void update_tiles() override;
    void collide(collidable_object *cobj) override;};

#endif