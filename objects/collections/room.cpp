#include <algorithm>

#include "room.h"

std::vector<tile> room::get_wall_tiles(side s, int corner_s) {
    std::vector<tile> out;
    
    switch(s) {
        case side::top:
            for(int j = pos.x + corner_s; j < pos.x + width - corner_s; j++) {
                out.push_back(tile(j, pos.y, 'c'));
            }
            break;
        case side::left:
            for(int j = pos.y + corner_s; j < pos.y + height - corner_s; j++) {
                out.push_back(tile(pos.x, j, 'c'));
            }
            break;
        case side::right:
            for (int j = pos.y + corner_s; j < pos.y + height - corner_s; j++) {
                out.push_back(tile(pos.x + width - 1, j, 'c'));
            }
        case side::bottom:
            for (int j = pos.x + corner_s; j < pos.x + width - corner_s; j++) {
                out.push_back(tile(j, pos.y + height - 1, 'c'));
            }
            break;
    }

    return out;
}

void room::draw_walls() {
    
}

void room::draw_floor() {

}

void room::draw_doors() {

}

room::room(position pos, int width, int height) : game_object(pos, width, height) {}

rfloor *room::get_floor() {
    return this->room_floor;
}

std::vector<wall*> room::get_walls() {
    return this->room_walls;
}

std::vector<door*> room::get_doors() {
    return this->room_doors;
}

void room::init() {
    position top_right = pos + position(this->width, 0);
    position bottom_left = pos + position(0, this->height);
    position bottom_right = bottom_left + position(this->width, 0);

    this->map_tiles.push_back(tile(this->pos.x, this->pos.y, '1'));
    this->map_tiles.push_back(tile(top_right.x, top_right.y, '2'));
    this->map_tiles.push_back(tile(bottom_left.x, bottom_left.y, '3'));
    this->map_tiles.push_back(tile(bottom_right.x, bottom_right.y, '4'));
}

void room::update() {

}

void room::update_tiles() {

}