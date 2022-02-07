#include <curses.h>
#include <vector>

#include "objects/collidable/player.h"
#include "objects/collidable/wall.h"
#include "objects/rfloor.h"
#include "objects/room.h"
#include "utils.h"
#include "game.h"

#define STR_COLOR_XY 255
#define STR_COLOR_HP 196

void init_win() {
  initscr();
  noecho();
  keypad(stdscr, true);

  refresh();
}

void print_info(player *pl) {
    mvprintw(max_y - 2, 2, "X: %d", pl->pos.x);
    printw("    Y: %d", pl->pos.y);
    printw("    HP: %.1f(%.1f)", pl->get_health(), pl->get_maxhealth());
}

int main(void) {
    init_win();
    player pl = player(position(0, 0), 20.0f, 20.0f);
    game g = game(pl);

    wall wa_r = wall(position(0, 6), 7, 1, wall::allignment::vertical);
    wall wa_b = wall(position(6, 0), 1, 7, wall::allignment::horizontal);
    rfloor fl = rfloor(position(0, 0), position(5, 5));

    g.add_object(&fl);
    g.add_collidable_object(&wa_r);
    g.add_collidable_object(&wa_b);
    g.add_collidable_object(&pl);

    int ch;
    while((ch = getch()) != 'q') {
        g.update_objects(ch);

        print_info(&pl);
    }

    endwin();
    return 0;
}