#include <curses.h>
#include <vector>

#include "objects/game_object.h"
#include "objects/collidable/collidable_object.h"
#include "objects/collidable/player.h"
#include "objects/room.h"
#include "objects/grid.h"
#include "objects/collidable/wall.h"
#include "map/renderer.h"
#include "utils.h"

void init_win() {
  initscr();
  noecho();
  keypad(stdscr, true);

  refresh();
}

void print_info(player *player) {
    //mvprintw(max_x - 2, 1, "    X: %d", player->pos.x);
    //printw("    Y: %d", player->pos.y);
    //printw("    HP: %.1f(%.1f)", player->health, player->max_health);

    mvprintw(max_x - 2, 1, "    X: %d   Y: %d", player->pos.x);
}

int main(void) {
    init_win();
    renderer render;
    std::vector<game_object*> objects;
    std::vector<collidable_object*> collidables;

    grid background = grid(max_x, max_y);
    objects.push_back(&background);

    wall w = wall(position(15, 10), 3, 10);
    collidables.push_back(&w);

    player rogue_player = player(100.0f, 100.0f);
    collidables.push_back(&rogue_player);

    int ch;
    while((ch = getch()) != 'q') {
        for(auto obj : objects) {
          obj->update_key(ch);
          obj->update();
          obj->update_tiles();

          render.print(obj);
        }

        for(auto obj : collidables) {
            obj->update_key(ch);
            obj->update();

            if(obj->did_move()) {
              for(auto obj2 : collidables) {
                if(obj->check_collide(obj2)) {
                    obj->collide(obj2);
                    obj2->collide(obj);
                }
              }
            }

            obj->update_tiles();
            render.print(obj);
        }

        print_info(&rogue_player);
    }

    endwin();
    return 0;
}