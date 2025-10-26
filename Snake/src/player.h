#include "bn_core.h"
#include "bn_vector.h"
#include "bn_array.h"
#include "bn_keypad.h"
#include "bn_sound_items.h"
#include "map.h"

#include "game_state.h"
#include "direction.h"   
#include "graphics.h"


class Controls;


enum SCANNER {
    SAFE_AREA,
    APPLE,
    BORDER,
    PLAYER,
};

class Player {
private:

    bool active;

    int length; //Gleichzeitig Punktzahl
    double speed;

    DIRECTION direction;
    SCANNER scanner;

    // Frame-Counter für Speed-basiertes Movement
    int move_counter;
    int move_delay; // Berechnet aus speed: 60.0 / speed

    /*
    *   Snake Body:
    *   Positionen werden als Vektorpaare (x|y) gesichert. 
    *   Index 0 Kopf
    *   Je Punkt wird Vektorkette verlängert
    * 
    *   Je Tick: 
    *   1) Neue Position in temp_pos1 schreiben
    *   2) Pos 0 in temp_pos2 sichern und dann 
    *   3) temp_pos1 in Pos 0 überschreiben. 
    *   => temp_pos rotieren und das ganze dann mit anderen paaren wiederholen
    */
    bn::vector<pos, 200> snake_body;

    pos temp_pos1;
    pos temp_pos2;

    
public:
    bool snake_body_update_delay;

    Player();
    ~Player();
    void start(int map_speed, Map& map);
    void update(SCANNER scanner, Controls& controls);
    SCANNER front_scanner(Map& map, GAME_STATE switch_game_state, const bn::vector<pos, 200>& snake_body);
    SCANNER check_next_position(Map& map, DIRECTION dir);

    void movement(SCANNER scanner);
    void update_position(int dx, int dy, SCANNER scanner);
    
    const bn::vector<pos, 200>& get_snake_body() const { return snake_body; }

    void reset_player(Player& player) {
        player = Player();
    };

    



    DIRECTION get_direction() const { return direction; }


};