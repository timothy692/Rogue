#include "wall.h"

wall::wall(position pos, int width, int height, allignment allign) : collidable_object(pos, width, height, TILE_WALL_COLOR) {
    if(allign == allignment::vertical) {
        for(int y = pos.y; y < pos.y + height; y++) {
            for(int x = pos.x; x < pos.x + width; x++) {
                this->map_tiles.push_back(tile(x, y, TILE_WALL));
            }
        }
    } else {
        for(int y = pos.y; y < pos.y + height; y++) {
            for(int x = pos.x; x < pos.x + width; x++) {
                this->map_tiles.push_back(tile(x, y, TILE_WALL));
            }
        }
    }
}

void wall::update() {
    
}

void wall::update_tiles() {

}

void wall::collide(collidable_object *cobj) {

}