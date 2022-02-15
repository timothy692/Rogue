#include <curses.h>
#include <vector>

#include "objects/collidable/player.h"
#include "objects/collidable/wall.h"
#include "objects/rfloor.h"
#include "objects/collections/room.h"
#include "objects/door.h"
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
    mvprintw(max_y - 2, 2, "X: %d(%d)", pl->pos.x, max_x);
    printw("    Y: %d(%d)", pl->pos.y, max_y);
    printw("    HP: %.1f(%.1f)", pl->get_health(), pl->get_maxhealth());
}

int main(void) {
    init_win();
    player pl = player(position(0, 0), 20.0f, 20.0f);
    game g = game(pl);

    /*int width = 10, height = 5;
    position tl = position(12, 8);

    door d = door(position(tl.x + (width / 2), tl.y + height - 1), 1, 1);

    wall wa_top = wall(tl, width, 1);
    wall wa_left = wall(tl, 1, height);
    wall wa_right = wall(tl + position(width - 1, 0), 1, height);
    
    wall wa_bottom_l = wall(tl + position(0, height - 1), (width / 2), 1);
    wall wa_bottom_r = wall(tl + position((width / 2) + 1, height - 1), (width / 2) - 1, 1);

    rfloor flo = rfloor(tl + position(1, 1), position(position(tl.x + width - 2, tl.y + height - 2)));

    g.add_object(&flo);
    g.add_object(&d);
    g.add_collidable_object(&wa_top);
    g.add_collidable_object(&wa_left);
    g.add_collidable_object(&wa_right);
    g.add_collidable_object(&wa_bottom_l);
    g.add_collidable_object(&wa_bottom_r);*/

    room r = room(position(5, 5), 10, 10);

    g.add_collective_object(&r);
    g.add_collidable_object(&pl);

    int ch;
    while((ch = getch()) != 'q') {
        g.update_objects(ch);

        print_info(&pl);
    }

    endwin();
    return 0;
}