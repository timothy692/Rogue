#ifndef __WALL_H
#define __WALL_H

#include "collidable_object.h"

class wall : public collidable_object {
    public:
    wall(position pos, int width, int height) : collidable_object(pos, width, height) {}
    void on_collide(collidable_object *cobj) override;
};

#endif