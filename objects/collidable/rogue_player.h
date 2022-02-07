#ifndef __PLAYER_H
#define __PLAYER_H

#include "collidable_object.h"
#include "../../map/position.h"
#include "../../map/tile.h"

#define TILE_PLAYER '@'

class rogue_player : public collidable_object {
    private:
    float health, maxhealth;
    bool can_move(position pos);
    public:
    rogue_player(float health, float max_health, position start);
    void update() override;
    void update_tiles() override;
    void collide(collidable_object *cobj) override;
    void handle_input(int ch);
    float get_health();
    float get_maxhealth();
};

#endif