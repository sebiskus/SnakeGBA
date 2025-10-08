#ifndef CONTROLS_H
#define CONTROLS_H

#include "bn_keypad.h"
#include "direction.h"   // stellt DIRECTION bereit

class Controls {
public:
    void update_per_frame(DIRECTION current_direction);
    DIRECTION peek_effective_direction(DIRECTION current_direction) const;
    bool try_consume(DIRECTION current_direction, DIRECTION& out_new_direction);
    void clear();

private:
    bool _has_pending = false;
    DIRECTION _pending = RIGHT;
    static bool _is_opposite(DIRECTION a, DIRECTION b);
};

#endif
