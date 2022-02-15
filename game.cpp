#include "game.h"

game::game(player pl) {
    this->pl = &pl;
}

void game::add_collidable_object(collidable_object *cobject) {
    cobject->init();
    this->collidable_game_objects.push_back(cobject);
}

void game::add_object(game_object *object) {
    object->init();
    this->game_objects.push_back(object);
}

void game::add_collective_object(collective_object *cobj) {
    cobj->init();
    cobj->add_objects();

    for(auto co : cobj->collidable_game_objects) {
        co->init();
        this->collidable_game_objects.push_back(co);
    } 

    for(auto o : cobj->game_objects) {
        o->init();
        this->game_objects.push_back(o);
    }

    this->collective_game_objects.push_back(cobj);
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
            for(auto &co2 : collidable_game_objects) {
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