#include "player.h"


Player::Player(){
        this->active = false;
        this->length = 0;
        this->speed = 1.0;
        this->direction = DIRECTION::RIGHT;
        this->snake_body_update_delay = false;

        //TODO:
        this->move_counter = 0;
        this->move_delay = 60; // 1 Sekunde bei speed = 1
    }

    
    void Player::start(int map_speed, Map& map){
        /* Initialisierung vom Spiel */
        active = true;
        snake_body.clear();

        /* Snake initialisieren */
        spawn spawn_pos = spawn_snake(map);
        pos initial_pos = {spawn_pos.x, spawn_pos.y};
        snake_body.push_back(initial_pos);
        length = snake_body.size();
        snake_body_update_delay = false;

        move_counter = 0;
    
        // Speed Delay: 60fps / map_speed ergibt die Tick-Speed
        move_delay = static_cast<int>(60.0 / map_speed);
    }




    void Player::update(SCANNER scanner){
        /*
        Updated Player Objekt
        - Movement: Steuerung lesen, Koordinaten verarbeiten
        - update_position: Snake Position wird angepasst
        - TODO: snake_body_updater()
        */
        
        move_counter++;
        if(move_counter >= move_delay) {

            movement(scanner);

            /* 
            Weitere Methoden 
            */

            move_counter = 0; // Reset counter
        }

    }


    
SCANNER Player::front_scanner(Map& map, GAME_STATE switch_game_state, const bn::vector<pos, 200>& snake_body) {
    if(snake_body.empty()) {
        return SCANNER::SAFE_AREA;
    }
    
    // NUR die aktuelle Kopfposition prüfen
    int current_x = snake_body[0].x;
    int current_y = snake_body[0].y;
    
    // Map-Wert der AKTUELLEN Position prüfen
    if(map[current_y][current_x] == 1) {
        return SCANNER::BORDER;
    } else if(map[current_y][current_x] == 3) {
        return SCANNER::APPLE;
    }
    
    // Selbst-Kollision prüfen (aber nur ab Index 1, da Index 0 = Kopf)
    for(int i = 1; i < snake_body.size(); ++i) {
        if (current_x == snake_body[i].x && current_y == snake_body[i].y) {
            return SCANNER::PLAYER;
        }
    }
    
    return SCANNER::SAFE_AREA;
}


// In player.cpp implementieren:
SCANNER Player::check_next_position(Map& map) {
    if(snake_body.empty()) {
        return SCANNER::SAFE_AREA;
    }
    
    // Temporäre Variablen für die NÄCHSTE Position
    int temp_x = snake_body[0].x;
    int temp_y = snake_body[0].y;
    
    // Berechne die nächste Position basierend auf direction
    switch(direction) {
        case UP: temp_y--; break;
        case DOWN: temp_y++; break;
        case LEFT: temp_x--; break;
        case RIGHT: temp_x++; break;
    }
    
    // Prüfe Grenzen BEVOR auf map zugegriffen wird
    //TODO: x_size und y_size benutzen bei if
    if(temp_x < 0 || temp_y < 0 || temp_x >= 16 || temp_y >= 10) {
        return SCANNER::BORDER;
    }
    
    // Map-Wert der NÄCHSTEN Position prüfen
    if(map[temp_y][temp_x] == 1) {
        return SCANNER::BORDER;
    } else if(map[temp_y][temp_x] == 3) {
        return SCANNER::APPLE;
    }
    
    // Selbst-Kollision mit NÄCHSTER Position prüfen
    pos temp_pos = {temp_x, temp_y};
    for(int i = 0; i < snake_body.size(); ++i) {
        if (temp_pos.x == snake_body[i].x && temp_pos.y == snake_body[i].y) {
            return SCANNER::PLAYER;
        }
    }
    
    return SCANNER::SAFE_AREA;
}






    void Player::movement(SCANNER scanner){
        DIRECTION prev_direction = direction;

        if(bn::keypad::up_held() && prev_direction != DOWN) {
            direction = DIRECTION::UP;
        } else if(bn::keypad::down_held() && prev_direction != UP) {
            direction = DIRECTION::DOWN;
        } else if(bn::keypad::left_held() && prev_direction != RIGHT) {
            direction = DIRECTION::LEFT;
        } else if(bn::keypad::right_held() && prev_direction != LEFT) {
            direction = DIRECTION::RIGHT;
        }

        switch(direction) {
            case UP:
                update_position(0, -1, scanner);
                break;
            case DOWN:
                update_position(0, 1, scanner);
                break;
            case LEFT:
                update_position(-1, 0, scanner);
                break;
            case RIGHT:
                update_position(1, 0, scanner);
                break;
            default:
                break;
            }
    }

void Player::update_position(int dx, int dy, SCANNER scanner) {
    if(snake_body.size() == 0) return;
    
    pos new_head = {snake_body[0].x + dx, snake_body[0].y + dy};
    
    // Apfel-Check komplett außerhalb des Scanners
    extern spawn current_apple_location;
    extern bool apple_exists;
    
    // Direkte Koordinaten-Prüfung - kein Scanner
    if(apple_exists && 
       new_head.x == current_apple_location.x && 
       new_head.y == current_apple_location.y) {
        
        // Schwanz duplizieren (Wachstum)
        pos tail = snake_body[snake_body.size() - 1];
        snake_body.push_back(tail);
        
        // Apfel sofort entfernen
        apple_exists = false;
        
        this->length = snake_body.size();
    }
    
    // Snake bewegen (egal ob Wachstum oder nicht)
    for(int i = snake_body.size() - 1; i > 0; i--) {
        snake_body[i] = snake_body[i - 1];
    }
    snake_body[0] = new_head;
}







    void Player::update_snake_body(bn::vector<pos, 200>& snake_body){
        /*
        TODO:
        Wird vom Scanner gecallt. snake_body Ende wird temporär gesichert
        und wird am Ende von update_position() eingefügt
        */
    }


    void Player::pause(){
        /*
        *WHILE Pause = true
        *speed ist auf 0 gesetzt und wird dann aus temp wieder übernommen
        *direction bleibt gleich
        *Vielleicht aber auch einfach mit game_update() lösen? Solange !start(){} passiert nix, also kein game_update()
        */

        speed = 0;
    }


Player::~Player(){}