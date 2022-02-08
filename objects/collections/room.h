#ifndef __ROOM_H
#define __ROOM_H

#include "../game_object.h"
#include "../collidable/wall.h"
#include "../rfloor.h"
#include "../../map/position.h"
#include "../../utils.h"
#include "../door.h"

#define DOORS_PER_ROOM 3

class room : public game_object {
    private:
    enum side { top = 0, left = 1, right = 2, bottom = 3 };
    std::vector<tile> get_wall_tiles(side s, int corner_spacing);
    rfloor *room_floor;
    std::vector<wall*> room_walls;
    std::vector<door*> room_doors;
    void draw_walls();
    void draw_doors();
    void draw_floor();
    public:
    room(position pos, int width, int height);
    rfloor *get_floor();
    std::vector<wall*> get_walls();
    std::vector<door*> get_doors();
    void init() override;
    void update() override;
    void update_tiles() override;
};

#endif