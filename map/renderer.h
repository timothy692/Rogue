#ifndef __RENDERER_H
#define __RENDERER_H

#include <curses.h>

#include "../objects/game_object.h"

class renderer {
    private:
    struct colored_tile { 
        
    };
    std::vector<short> color_pairs; 
    int find_pair_index(short color);
    public:
    renderer();
    void render(game_object *obj);
};

#endif