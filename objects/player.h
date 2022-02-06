#ifndef __PLAYER_H
#define __PLAYER_H

#include "game_object.h"
#include "../map/position.h"
#include "../map/tile.h"

#define TILE_PLAYER '@'

class player : public game_object {
    private:
    bool can_move(position pos);
    public:
    float health, max_health;
    player(float health, float max_health);
    void update() override;
    void update_tiles() override;
    void handle_input(int ch);
};

#endif