#ifndef __DOOR_H
#define __DOOR_H

#include "game_object.h"

#define TILE_DOOR '+'

class door : public game_object {
    public:
    door(position pos, int width, int height);
    void init() override;
    void update() override;
    void update_tiles() override;
};

#endif