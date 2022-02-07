#include "rfloor.h"

rfloor::rfloor(position start, position end) : game_object(start, start.x + end.x, start.y + end.y) {
    for(int y = start.y; y < end.y + 1; y++) {
        for(int x = start.x; x < end.y + 1; x++) {
            this->map_tiles.push_back(tile(x, y, TILE_FLOOR));
        }
    }

    this->endpos = end;
}

void rfloor::update() {

}

void rfloor::update_tiles() {

}