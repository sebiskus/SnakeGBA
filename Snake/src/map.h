#ifndef MAP_H
#define MAP_H

#include "bn_vector.h"
#include "bn_random.h"
#include "bn_seed_random.h"


constexpr int x_size = 16;
constexpr int y_size = 10;

struct pos {
    int x;
    int y;
};

struct spawn {
    int x;
    int y;
};



enum TileType {
        FLOOR_TILE = 0,
        WALL_TILE = 1,
        SNAKE_TILE = 2,
        APPLE_TILE = 3
    };

using Map = int[y_size][x_size];

Map& selectMap(int mapID);
void update_map(Map& map, int mapID, const bn::vector<pos, 200>& snake_body);
spawn spawn_snake(Map& map);
void spawn_apple(Map& map);

void initialize_apple(Map& map);
void initialize_random_seed(); // Neue Funktion für Seed-Initialisierung
void reset_random_seed(); // Reset für neues Spiel



void reset_map(Map& map);

#endif