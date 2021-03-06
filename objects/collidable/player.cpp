#include <curses.h>
#include <iostream>

#include "player.h"
#include "../../utils.h"
#include "../collections/room.h"

bool player::can_move(position pos) {
    return !(pos.x >= max_x || pos.x < 0 || pos.y >= max_y || pos.y < 0);
}

player::player(position pos, float health, float max_health) : collidable_object(pos, 1, 1), health(health), maxhealth(max_health) {}

void player::init() {
    this->map_tiles.push_back(tile(0, 0, TILE_PLAYER));
    this->last_pos = pos;
}

void player::update() {
    this->handle_input(this->ch);
}

void player::update_tiles() {
    map_tiles[0] = tile(pos.x, pos.y, TILE_PLAYER);
}

void player::collide(collidable_object *cobj) {
    this->pos = this->last_pos;
}

void player::handle_input(int ch) {
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

float player::get_health() {
    return this->health;
}

float player::get_maxhealth() {
    return this->maxhealth;
}