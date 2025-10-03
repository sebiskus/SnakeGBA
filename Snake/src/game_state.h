#ifndef GAME_STATE_H
#define GAME_STATE_H

enum GAME_STATE {
    STOP,        // Spiel läuft nicht
    RUNNING,     // Spiel läuft
    PAUSE,       // pausiert: keine Aktualisierungen
    MENU,
    INITIALIZE,
};

#endif
