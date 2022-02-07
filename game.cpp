#include "game.h"

game::game(player pl) {
    this->pl = &pl;
}

void game::add_collidable_object(collidable_object *cobject) {
    this->collidable_game_objects.push_back(cobject);
}

void game::add_object(game_object *object) {
    this->game_objects.push_back(object);
}

void game::update_objects(int ch) {
    for(auto o : game_objects) {
        o->update_key(ch);
        o->update();
        o->update_tiles();

        game_renderer.render(o);
    }

    for(auto co : collidable_game_objects) {
        co->update_key(ch);
        co->update();

        if(co->did_move()) {
            for(auto co2 : collidable_game_objects) {
                if(co->check_collision(co2)) {
                    co->collide(co2);
                    co2->collide(co);
                }
            }
        }

        co->update_tiles();
        game_renderer.render(co);
    }
}