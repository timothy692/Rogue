#ifndef __GAME_H
#define __GAME_H

#include <iostream>
#include <vector>
#include "objects/collidable/rogue_player.h"
#include "objects/game_object.h"
#include "objects/collidable/collidable_object.h"

class game {
    private:
    rogue_player *player;
    std::vector<game_object*> game_objects;
    std::vector<collidable_object*> collidable_game_objects;
    public:
    game(rogue_player player);
    void add_collidable_object(collidable_object *cobject);
    void add_object(game_object *object);
    void update_objects();
};

#endif