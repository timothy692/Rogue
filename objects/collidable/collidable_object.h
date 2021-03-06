#ifndef __COLLIDABLE_OBJECT_H
#define __COLLIDABLE_OBJECT_H

#include "../game_object.h"
#include "../../map/position.h"

class collidable_object : public game_object {
    public:
    collidable_object(position pos, int width, int height) : game_object(pos, width, height) {}
    bool check_collision(collidable_object *cobj);
    virtual void collide(collidable_object *cobj) = 0;
};

#endif