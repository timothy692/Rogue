#include "grid.h"

grid::grid(int m_width, int m_height) : game_object(position(0, 0), m_width, m_height) {
    for(int y = 0; y < m_height; y++) {
        for(int x = 0; x < m_height; x++) {
            this->map_tiles.push_back(tile(x, y, TILE_GRID));
        }
    }
}

void grid::update() {

}

void grid::update_tiles() {
    
}