#ifndef __GAME_H
#define __GAME_H

#include <iostream>
#include <vector>
#include "map/renderer.h"
#include "objects/collidable/player.h"
#include "objects/game_object.h"
#include "objects/collidable/collidable_object.h"
#include "objects/collections/collective_object.h"

class game {
    private:
    player *pl;
    renderer game_renderer;
    std::vector<game_object*> game_objects;
    std::vector<collidable_object*> collidable_game_objects;
    std::vector<collective_object*> collective_game_objects;
    public:
    game(player pl);
    void add_collidable_object(collidable_object *cobject);
    void add_object(game_object *object);
    void add_collective_object(collective_object *cobj);
    void update_objects(int ch);
};

#endif