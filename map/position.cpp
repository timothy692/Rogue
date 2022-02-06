#include "position.h"

bool position::operator!=(const position other) {
    return (this->x == other.x && this->y == other.y); 
}

bool position::operator==(const position other) {
    return !(this->x == other.x && this->y == other.y);
}