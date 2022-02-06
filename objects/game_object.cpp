#include "game_object.h"

void game_object::update() {

}

void game_object::update_tiles() {
    
}

void game_object::update_key(int ch) {
    this->ch = ch;
}

bool game_object::did_move() {
    return this->last_pos != this->pos;
}