#include "game.h"

game::game(rogue_player player) {

}

void game::add_collidable_object(collidable_object *cobject) {
    this->collidable_game_objects.push_back(cobject);
}

void game::add_object(game_object *object) {
    this->game_objects.push_back(object);
}

void game::update_objects() {
    
}