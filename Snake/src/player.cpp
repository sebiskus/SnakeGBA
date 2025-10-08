#include "player.h"
#include "controls.h"  



Player::Player(){
        this->active = false;
        this->length = 0;
        this->speed = 1.0;
        this->direction = DIRECTION::RIGHT;
        this->snake_body_update_delay = false;

        this->move_counter = 0;
        this->move_delay = 60; // Je 60 Frames = eine Sekunde
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




    void Player::update(SCANNER scanner, Controls& controls) {
    move_counter++;
    if(move_counter >= move_delay) {
        // 1) Eingabe gepuffert konsumieren (falls vorhanden und gültig)
        DIRECTION new_dir;
        if(controls.try_consume(direction, new_dir)) {
            direction = new_dir;
        }
        // 2) Bewegung in gesetzter Richtung ausführen
        movement(scanner);
        move_counter = 0;
    }
}


    
SCANNER Player::front_scanner(Map& map, GAME_STATE switch_game_state, const bn::vector<pos, 200>& snake_body) {
    if(snake_body.empty()) {
        return SCANNER::SAFE_AREA;
    }
    
    // aktuelle Kopfposition prüfen
    int current_x = snake_body[0].x;
    int current_y = snake_body[0].y;
    
    // Map-Wert der aktuellen Position prüfen
    if(map[current_y][current_x] == 1) {
        bn::sound_items::game_over.play();
        return SCANNER::BORDER;
    } else if(map[current_y][current_x] == 3) {
        bn::sound_items::snake_eating.play();
        return SCANNER::APPLE;
    }
    
    // Selbst-Kollision prüfen (nur ab Index 1, da Index 0 = Kopf)
    for(int i = 1; i < snake_body.size(); ++i) {
        if (current_x == snake_body[i].x && current_y == snake_body[i].y) {
            return SCANNER::PLAYER;
        }
    }
    
    return SCANNER::SAFE_AREA;
}


SCANNER Player::check_next_position(Map& map, DIRECTION dir) {
    if(snake_body.empty()) {
        return SCANNER::SAFE_AREA;
    }
    int temp_x = snake_body[0].x;
    int temp_y = snake_body[0].y;

    switch(dir) {
        case UP:    temp_y--; break;
        case DOWN:  temp_y++; break;
        case LEFT:  temp_x--; break;
        case RIGHT: temp_x++; break;
        default: break;
    }
    
    // Prüfe Grenzen BEVOR auf map zugegriffen wird
    //TODO: x_size und y_size benutzen bei if
    if(temp_x < 0 || temp_y < 0 || temp_x >= 16 || temp_y >= 10) {
        return SCANNER::BORDER;
    }
    
    // Map-Wert der nächsten Position prüfen
    if(map[temp_y][temp_x] == 1) {
        return SCANNER::BORDER;
    } else if(map[temp_y][temp_x] == 3) {
        return SCANNER::APPLE;
    }
    
    // Selbst-Kollision mit nächster Position prüfen
    pos temp_pos = {temp_x, temp_y};
    for(int i = 0; i < snake_body.size(); ++i) {
        if (temp_pos.x == snake_body[i].x && temp_pos.y == snake_body[i].y) {
            return SCANNER::PLAYER;
        }
    }
    
    return SCANNER::SAFE_AREA;
}

    void Player::movement(SCANNER scanner){

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
    
    if(apple_exists && 
       new_head.x == current_apple_location.x && 
       new_head.y == current_apple_location.y) {
        
        // Tail duplizieren (Wachstum)
        pos tail = snake_body[snake_body.size() - 1];
        snake_body.push_back(tail);
        
        // Apfel sofort löschen
        apple_exists = false;
        
        this->length = snake_body.size();
    }
    
    // Snake bewegen
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