#include <algorithm>

#include "room.h"

std::vector<tile> room::get_wall_tiles(side s, int corner_s) {
    std::vector<tile> out;
    
    switch(s) {
        case side::top:
            for(int j = pos.x + corner_s; j < pos.x + width - corner_s; j++) {
                out.push_back(tile(j, pos.y, TILE_ROOM_WALL));
            }
            break;
        case side::left:
            for(int j = pos.y + corner_s; j < pos.y + height - corner_s; j++) {
                out.push_back(tile(pos.x, j, TILE_ROOM_WALL));
            }
            break;
        case side::right:
            for (int j = pos.y + corner_s; j < pos.y + height - corner_s; j++) {
                out.push_back(tile(pos.x + width - 1, j, TILE_ROOM_WALL));
            }
        case side::bottom:
            for (int j = pos.x + corner_s; j < pos.x + width - corner_s; j++) {
                out.push_back(tile(j, pos.y + height - 1, TILE_ROOM_WALL));
            }
            break;
    }

    return out;
}

void room::draw_walls() {
    
}

void room::draw_floor() {
    rfloor fl = rfloor(this->pos, position(5, 5));
    this->room_floor = &fl;
}

void room::draw_doors() {

}

room::room(position pos, int width, int height) : game_object(pos, width, height, -1) {
    //this->draw_walls();
    this->draw_floor();
    //this->draw_doors();
}

rfloor *room::get_floor() {
    return this->room_floor;
}

std::vector<wall*> room::get_walls() {
    return this->room_walls;
}

void room::update() {

}

void room::update_tiles() {

}