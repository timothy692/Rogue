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
    for(int i = 0; i < 3; i++) {
        std::vector<tile> tiles = get_wall_tiles((side)i, 0);

        for(int j = 0; j < tiles.size(); j++) {
            this->map_tiles.push_back(tiles[j]);
        }   
    }
}

void room::draw_doors() {
    int n_doors = 0;

    do {
        std::vector<tile> w_tiles = get_wall_tiles((side)randomizer::rnd<int>(0, 3), 1);
        std::vector<char> tiles_c;
        for(auto t : w_tiles) {
            tiles_c.push_back(t.ch);
        }

        if(!(std::find(tiles_c.begin(), tiles_c.end(), TILE_ROOM_DOOR) != tiles_c.end())) {

            int n = randomizer::rnd<int>(0, w_tiles.size() - 1);
            tile r_tile = tile(w_tiles[n].x, w_tiles[n].y, TILE_ROOM_DOOR);
            this->map_tiles.push_back(r_tile);
            n_doors++;
        } else {
            n_doors--;
        }

    } while(n_doors < DOORS_PER_ROOM);
}

void room::draw_floor() {
    for(int y = pos.y + 1; y < pos.y + height - 1; y++) {
        for(int x = pos.x + 1; x < pos.x + width - 1; x++) {
            this->map_tiles.push_back(tile(x, y, TILE_ROOM_FLOOR));
        }
    }
}

room::room(position pos, int width, int height) : game_object(pos, width, height) {
    this->draw_walls();
    this->draw_floor();
    this->draw_doors();
}

void room::update() {

}

void room::update_tiles() {

}