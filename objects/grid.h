#ifndef __FLOOR_H
#define __FLOOR_H

#include "../map/position.h"
#include "game_object.h"

#define TILE_GRID ' '

class grid : public game_object {
    public:
    grid(int m_width, int m_height);
    void update() override;
    void update_tiles() override;
};

#endif