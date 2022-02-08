#include "wall.h"

wall::wall(position pos, int width, int height) : collidable_object(pos, width, height) {}

void wall::init() {
    for(int y = pos.y; y < pos.y + height; y++) {
        for(int x = pos.x; x < pos.x + width; x++) {
            this->map_tiles.push_back(tile(x, y, TILE_WALL));
        }
    }
}

void wall::update() {
    
}

void wall::update_tiles() {

}

void wall::collide(collidable_object *cobj) {

}