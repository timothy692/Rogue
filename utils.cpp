#include <algorithm>

#include "map/position.h"
#include "utils.h"

template<>
int utils::rnd(int min, int max) {
    std::random_device dev;
    std::default_random_engine gen{dev()};
    std::uniform_int_distribution<int> dis{min, max};

    return dis(gen); 
}

template<>
bool utils::contains_other<position>(std::vector<position> vec1, std::vector<position> vec2) {
    int i = 0;
    
    for(auto &pos : vec1) {
        if(std::find(vec2.begin(), vec2.end(), pos) != vec2.end()) {
            i++;
        }
    }

    return i > 0;
}