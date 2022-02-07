#ifndef __RENDERER_H
#define __RENDERER_H

#include <curses.h>

#include "../objects/game_object.h"

class renderer {
    public:
    renderer() {}
    void render(game_object *obj);
};

#endif