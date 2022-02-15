#include <algorithm>
#include <tuple>
#include <iostream>

#include "room.h"

std::pair<std::vector<position>, room::side> room::get_side(side s, bool ign_c) {
    std::vector<position> out;

    int inc = ign_c ? 1 : 0;

    switch(s) {
        case side::top:
            for(int x = pos.x + inc; x < pos.x + width; x++) {
                out.push_back(position(x, pos.y));
            }
        case side::bottom:
            for(int x = (pos.y + height + 1) + inc; x < (pos.y + height + 1) + width; x++) {
                out.push_back(position(x, pos.y + height + 1));
            }
        break;
        case side::left:
            for(int y = pos.y + inc; y < pos.y + height; y++) {
                out.push_back(position(pos.x, y));
            }
        break;
        case side::right:
            bool c = ign_c ? 0 : 1;
            for(int y = top_r.y + inc; y < top_r.y + height + c; y++) {
                out.push_back(position(top_r.x, y));
            }
        break;
    }

    return std::make_pair(out, s);
}

void room::draw_doors() {
    std::vector<int> _sides;

    do {
        int s = utils::rnd<int>(0, 3);
        auto s_vec = get_side((side)s, true).first;
        position pos = s_vec.at(utils::rnd<int>(0, s_vec.size() - 1));

        if(std::find(_sides.begin(), _sides.end(), s) != _sides.end()) {
            continue;
        }
        
        door d = door(pos, 1, 1);
        this->room_doors.push_back(d);
        _sides.push_back(s);
    } while(_sides.size() < DOORS_PER_ROOM);
}

void room::draw_walls() {
    std::vector<position> door_positions;
    for(auto &d : room_doors) {
        door_positions.push_back(d.pos);
    }

    for(int i = 0; i < 4; i++) {
        auto s = get_side((room::side)i, false);
        
        if(!utils::contains_other<position>(s.first, door_positions)) {
            std::cout << s.second << '\n'; 
        }
        /*
        bool has_door = false;
        bool is_horizontal = (s.second == side::bottom || s.second == side::top);
        
        for(auto &d : room_doors) {
            if(std::find(s_vec.begin(), s_vec.end(), d.pos) != s_vec.end()) {
                has_door = true;
            }
        }

        if(!has_door) {
            int width = is_horizontal ? this->width + 1 : 1;
            int height = is_horizontal ? 1 : this->height + 1;

            for(auto &p : s_vec) {
                wall wa = wall(p, 1, 1);
                this->room_walls.push_back(wa);
            }

            std::cout << s.second << '\n';
        }*/
    }
}


void room::draw_floor() {

}

room::room(position pos, int width, int height) : collective_object(pos, width, height) {}

void room::add_objects() {
    for(auto &d : room_doors) {
        this->game_objects.push_back(&d);
    }

    for(auto &w : room_walls) {
        this->collidable_game_objects.push_back(&w);
    }

    this->game_objects.push_back(&this->room_floor);
}

void room::init() {
    this->top_r = pos + position(this->width, 0);
    this->bottom_l = pos + position(0, this->height);
    this->bottom_r = this->bottom_l + position(this->width, 0);

    this->draw_doors();
    this->draw_walls();
    this->draw_floor();
}

void room::update() {

}

void room::update_tiles() {

}