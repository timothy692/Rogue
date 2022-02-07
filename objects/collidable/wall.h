#ifndef __WALL_H
#define __WALL_H

#include "collidable_object.h"

#define TILE_WALL_COLOR 196 
#define TILE_WALL '#'

class wall : public collidable_object {
    public:
    enum allignment { vertical = 0, horizontal = 1 };
    wall(position pos, int width, int height, allignment allign);
    void update() override;
    void update_tiles() override;
    void collide(collidable_object *cobj) override;
};

#endif