#include "door.h"

door::door(position pos, int width, int height): game_object(pos, width, height) {}

void door::init() {
    for(int y = pos.y; y < pos.y + height; y++) {
        for(int x = pos.x; x < pos.x + width; x++) {
            this->map_tiles.push_back(tile(x, y, TILE_DOOR));
        }
    }
}

void door::update() {

}

void door::update_tiles() {

}