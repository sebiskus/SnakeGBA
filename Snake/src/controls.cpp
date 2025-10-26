#include "controls.h"

static bool is_pressed_up()    { return bn::keypad::up_held(); }
static bool is_pressed_down()  { return bn::keypad::down_held(); }
static bool is_pressed_left()  { return bn::keypad::left_held(); }
static bool is_pressed_right() { return bn::keypad::right_held(); }

bool Controls::_is_opposite(DIRECTION a, DIRECTION b) {
    return (a == UP && b == DOWN) || (a == DOWN && b == UP) ||
           (a == LEFT && b == RIGHT) || (a == RIGHT && b == LEFT);
}

void Controls::update_per_frame(DIRECTION current) {
    DIRECTION candidate = current;
    bool any = false;

    if(is_pressed_up())    { candidate = UP;    any = true; }
    if(is_pressed_down())  { candidate = DOWN;  any = true; }
    if(is_pressed_left())  { candidate = LEFT;  any = true; }
    if(is_pressed_right()) { candidate = RIGHT; any = true; }

    if(any && !_is_opposite(current, candidate)) {
        _pending = candidate;
        _has_pending = true;
    }
}

DIRECTION Controls::peek_effective_direction(DIRECTION current) const {
    return _has_pending ? _pending : current;
}

bool Controls::try_consume(DIRECTION current, DIRECTION& out) {
    if(!_has_pending) {
        return false;
    }
    if(_is_opposite(current, _pending)) {
        _has_pending = false;
        return false;
    }
    out = _pending;
    _has_pending = false;
    return true;
}

void Controls::clear() {
    _has_pending = false;
}
