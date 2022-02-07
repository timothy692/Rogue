#include <curses.h>
#include <iostream>

#include "rogue_player.h"
#include "../../utils.h"
#include "../room.h"

bool rogue_player::can_move(position pos) {
    return !(pos.x >= max_x || pos.x < 0 || pos.y >= max_y || pos.y < 0);
}

rogue_player::rogue_player(float health, float max_health, position start) : collidable_object(start, 2, 2), 
        health(health), maxhealth(max_health) {
    this->map_tiles.push_back(tile(0, 0, TILE_PLAYER));
    this->last_pos = pos;
}

void rogue_player::update() {
    this->handle_input(this->ch);
}

void rogue_player::update_tiles() {
    map_tiles[0] = tile(pos.x, pos.y, TILE_PLAYER);
}

void rogue_player::collide(collidable_object *cobj) {
    this->pos = this->last_pos;
}

void rogue_player::handle_input(int ch) {
    position pos(-1, -1);

    switch(ch) {
        case 'w':
        case 'W':
            pos.x = this->pos.x;
            pos.y = this->pos.y - 1;
            break;
        case 'a':
        case 'A':
            pos.x = this->pos.x - 1;
            pos.y = this->pos.y;
            break;
        case 's':
        case 'S':
            pos.x = this->pos.x;
            pos.y = this->pos.y + 1;
            break;
        case 'd':
        case 'D':
            pos.x = this->pos.x + 1;
            pos.y = this->pos.y;
            break;
        default:
            break;
    }

    if(can_move(pos)) {
        this->last_pos = this->pos;
        this->pos = pos;
    }
}

float rogue_player::get_health() {
    return this->health;
}

float rogue_player::get_maxhealth() {
    return this->maxhealth;
}