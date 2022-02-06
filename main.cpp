#include <curses.h>
#include <vector>

#include "objects/game_object.h"
#include "objects/player.h"
#include "objects/room.h"
#include "objects/grid.h"
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
    grid background = grid(max_x, max_y);
    player rogue_player = player(100.0f, 100.0f);

    room room1 = room(position(15, 15), 20, 10);
    room room2 = room(position(52, 22), 15, 7);

    objects.push_back(&background);
    objects.push_back(&room1);
    objects.push_back(&room2);
    objects.push_back(&rogue_player);

    int ch;
    while((ch = getch()) != 'q') {
        for(auto obj : objects) {
          obj->update_key(ch);
          obj->update();
          obj->update_tiles();

          render.print(obj);
        }

        print_info(&rogue_player);
    }

    endwin();
    return 0;
}