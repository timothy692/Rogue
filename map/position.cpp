#include "position.h"

bool position::operator!=(const position other) {
    return !(this->x == other.x && this->y == other.y);
}

bool position::operator==(const position other) {
    return (this->x == other.x && this->y == other.y); 
}

position position::operator+(const position other) {
    return position(this->x + other.x, this->y + other.y);
}