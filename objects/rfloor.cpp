#include "rfloor.h"

rfloor::rfloor(position start, position end) : game_object(start, start.x + end.x, start.y + end.y) {
    this->endpos = end;
}

void rfloor::init() {
    for(int y = this->pos.y; y < this->endpos.y + 1; y++) {
        for(int x = this->pos.x; x < this->endpos.x + 1; x++) {
            this->map_tiles.push_back(tile(x, y, TILE_FLOOR));
        }
    }
}

void rfloor::update() {

}

void rfloor::update_tiles() {

}