#ifndef __ROOM_H
#define __ROOM_H

#include "game_object.h"
#include "../map/position.h"
#include "../utils.h"

#define TILE_ROOM_FLOOR '.'
#define TILE_ROOM_WALL '#'
#define TILE_ROOM_DOOR '+'

#define DOORS_PER_ROOM 3

class room : public game_object {
    private:
    enum side { top = 0, left = 1, right = 2, bottom = 3 };
    std::vector<tile> get_wall_tiles(side s, int corner_spacing);
    void draw_walls();
    void draw_doors();
    void draw_floor();
    public:
    std::vector<tile> doors;
    room(position pos, int width, int height);
    void update() override;
    void update_tiles() override;
};

#endif