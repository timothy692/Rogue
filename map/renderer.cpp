#include "renderer.h"

renderer::renderer() {
    start_color();
    use_default_colors();
    init_pair(1, 9, -1);
}

int renderer::find_pair_index(short color) {
    int out = -1;
    
    for(int c : this->color_pairs) {
        if(color == c) {
            out = c;
            break;
        }
    }

    if(out != -1) {
        return out;
    } else {
        this->color_pairs.push_back(color);
        init_pair(this->color_pairs.size(), color, -1);
    }

    return this->color_pairs.size();
}

void renderer::render(game_object *obj) {
    //int i = find_pair_index(obj->color);

    attron(COLOR_PAIR(1));
    for(auto &tile : obj->map_tiles) {
        mvprintw(tile.y, tile.x, "%c", tile.ch);
        
    }
    attroff(COLOR_PAIR(1));
}