#ifndef __UTILS_H
#define __UTILS_H

#include <random>
#include <curses.h>

#define max_x getmaxx(stdscr)
#define max_y getmaxy(stdscr)

class randomizer {
    public: 
    template<typename T> 
    static T rnd(T min, T max);
};

#endif