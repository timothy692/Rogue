#ifndef __UTILS_H
#define __UTILS_H

#include <random>
#include <vector>
#include <curses.h>

#define max_x getmaxx(stdscr)
#define max_y getmaxy(stdscr)

class utils {
    public: 
    template<typename T> 
    static T rnd(T min, T max);
    template<typename T>
    static bool contains_other(std::vector<T> vec1, std::vector<T> vec2);
};

#endif