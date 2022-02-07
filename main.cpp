#include <curses.h>
#include <vector>

#include "objects/game_object.h"
#include "objects/collidable/collidable_object.h"
#include "objects/collidable/rogue_player.h"
#include "objects/room.h"
#include "objects/grid.h"
#include "objects/rfloor.h"
#include "objects/collidable/wall.h"
#include "map/renderer.h"
#include "utils.h"

void init_win() {
  initscr();
  noecho();
  keypad(stdscr, true);

  refresh();
}

void print_info(rogue_player *player) {
    mvprintw(max_y - 2, 2, "X: %d    Y: %d    HP:%.1f(%.1f)", 
      player->pos.x, player->pos.y, player->get_health(), player->get_maxhealth());
}

int main(void) {
    init_win();
    renderer render;
    std::vector<game_object*> objects;
    std::vector<collidable_object*> collidables;

    rogue_player player = rogue_player(100.0f, 100.0f, position(5, 5));
    collidables.push_back(&player);

    room r = room(position(0, 0), 6, 3);
    objects.push_back(r.get_floor());

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
                if(obj->check_collision(obj2)) {
                    obj->collide(obj2);
                    obj2->collide(obj);
                }
              }
            }

            obj->update_tiles();
            render.print(obj);
        }

        print_info(&player);
    }

    endwin();
    return 0;
}