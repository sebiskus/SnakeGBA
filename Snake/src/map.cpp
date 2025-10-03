//GBA screen size: 240x160
//tile size: 4x4
/*
* 0 = safe area
* 1 = border
* 2 = player spawnpoint
* 3 = apple
*/

#include "map.h"
#include "bn_core.h"

spawn current_apple_location;
bool apple_exists = false;
bn::seed_random global_random; // Globaler Random-Generator mit Seed
bool random_initialized = false; // Flag für Initialisierung


// Seed Initialisierung
void initialize_random_seed() {
    if (!random_initialized) {
        // Kombiniere mehrere Hardware-basierte Werte für bessere Entropie
        unsigned int seed_base = reinterpret_cast<unsigned int>(&random_initialized);
        
        // Sammle zusätzliche Entropie-Quellen
        int entropy_factor = 1;
        for (int i = 0; i < 10; i++) {
            entropy_factor ^= (bn::core::current_cpu_usage().integer() << (i % 4));
            bn::core::update(); // Kleine Verzögerung für Timing-Variation
        }
        
        // Kombiniere alle Faktoren für finalen Seed
        unsigned int final_seed = seed_base ^ 
                                 (entropy_factor * 0x9E3779B9) ^ 
                                 (bn::core::last_missed_frames() * 1103515245);
        
        global_random = bn::seed_random(final_seed);
        random_initialized = true;
    }
}

//TODO: vielleicht zu TileType umwandeln
int map0[y_size][x_size] = { //16x10
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int map1[y_size][x_size] = { //16x10
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
int map2[y_size - 5][x_size] = { //16x10
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

Map& selectMap(int mapID) {
    switch(mapID) {
        case 0:
            return map0;
        default:
            return map0;
    }
}


void update_map(Map& map, int mapID, const bn::vector<pos, 200>& snake_body) {
    // 1) Map-Vorlage übernehmen
    Map& template_map = selectMap(mapID);
    for(int y = 0; y < y_size; y++) {
        for(int x = 0; x < x_size; x++) {
            map[y][x] = template_map[y][x];
        }
    }
    
    // 2) Nur existierenden Apfel setzen
    if(apple_exists) {
        map[current_apple_location.y][current_apple_location.x] = 3;
    } else {
        spawn_apple(map);
    }
    
    // 3) Snake Body zeichnen
    for(int i = 0; i < snake_body.size(); i++) {
        int snake_x = snake_body[i].x;
        int snake_y = snake_body[i].y;
        
        // Apfel gefressen?
        if(apple_exists && snake_x == current_apple_location.x && snake_y == current_apple_location.y) {
            apple_exists = false;
            spawn_apple(map);
        }
        
        map[snake_y][snake_x] = 2;
    }
}


spawn spawn_snake(Map& map){
    int spawn_x = x_size / 2;
    int spawn_y = y_size / 2;

    return {spawn_x, spawn_y};
}

//TODO: DIE FUNKTION IST NUR TEMPORÄR SO IMPLEMENTIERT WORDEN
//HIER ALS PARAMETER DIE AKTUELLE POSITION VON APFEL UND SNAKE, DAMIT ES NICHT ÜBERLAPPT

void spawn_apple(Map& map) {
    // Seed ist bereits beim Boot initialisiert
    int max_attempts = 100;
    int attempts = 0;
    
    do {
        // Korrigierte Grenzen für Array-Zugriff
        current_apple_location.x = global_random.get_unbiased_int(1, x_size - 1);
        current_apple_location.y = global_random.get_unbiased_int(1, y_size - 1);
        attempts++;
    } while(map[current_apple_location.y][current_apple_location.x] != 0 && attempts < max_attempts);
    
    apple_exists = true;
    map[current_apple_location.y][current_apple_location.x] = 3;
}

// Für neues Spiel - generiert neuen Seed ohne Neustart
void reset_random_seed() {
    random_initialized = false;
    initialize_random_seed();
}

void initialize_apple(Map& map) {
    apple_exists = false;
    spawn_apple(map);
}
