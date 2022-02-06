#include "utils.h"

template<>
int randomizer::rnd(int min, int max) {
    std::random_device dev;
    std::default_random_engine gen{dev()};
    std::uniform_int_distribution<int> dis{min, max};

    return dis(gen); 
}