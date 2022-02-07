#include "renderer.h"

void renderer::render(game_object *obj) {
    for(auto &tile : obj->map_tiles) {
        mvprintw(tile.y, tile.x, "%c", tile.ch);
    }
}