#ifndef GAME_STATE_H
#define GAME_STATE_H

enum GAME_STATE {
    STARTUP,
    MENU,
    INITIALIZE,
    RUNNING,     // Spiel läuft
    PAUSE,       // pausiert: keine Aktualisierungen
    STOP,        // Spiel läuft nicht
    
    _DEBUG,
};

#endif
