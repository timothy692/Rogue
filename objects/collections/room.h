#ifndef __ROOM_H
#define __ROOM_H

#include "collective_object.h"
#include "../collidable/wall.h"
#include "../rfloor.h"
#include "../../map/position.h"
#include "../../utils.h"
#include "../door.h"
#include "../../game.h"

#define DOORS_PER_ROOM 2

class room : public collective_object {
    private:
    enum side { top = 0, left = 1, right = 2, bottom = 3 };
    std::pair<std::vector<position>, room::side> get_side(side s, bool ign_c);
    position top_r, bottom_l, bottom_r;
    std::vector<door> room_doors;
    rfloor room_floor = rfloor(position(0, 0), position(0, 0));
    std::vector<wall> room_walls;
    void draw_doors();
    void draw_walls();
    void draw_floor();
    public:
    room(position pos, int width, int height);
    void add_objects() override;
    void init() override;
    void update() override;
    void update_tiles() override;
};

#endif