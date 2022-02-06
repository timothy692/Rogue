#ifndef __WALL_H
#define __WALL_H

#include "collidable_object.h"

class wall : public collidable_object {
    public:
    wall(position start, position end, int width) :
        collidable_object()
};

#endif