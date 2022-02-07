#include "collidable_object.h"

bool collidable_object::check_collide(collidable_object *cobj) {
  return this != cobj && (this->pos.x >= cobj->pos.x) &&
         (this->pos.x <= (cobj->pos.x + cobj->width - 1)) &&
         (this->pos.y >= cobj->pos.y) &&
         (this->pos.y <= (cobj->pos.y + cobj->height - 1));
}

void collidable_object::collide(collidable_object *cobj) {
  
}