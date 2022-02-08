#ifndef __RFLOOR_H
#define __RFLOOR_H

#include "game_object.h"

#define TILE_FLOOR '.'

class rfloor : public game_object {
    public:
    position endpos;
    rfloor(position start, position end);
    void init() override;
    void update() override;
    void update_tiles() override;
};

#endif