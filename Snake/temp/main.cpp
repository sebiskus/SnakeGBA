#include <iostream>
#include "game.cpp"
#include "player.cpp"
#include <thread>
#include "bn_core.h"


using namespace std;

int main() {

    player::Position pos = {2, 3};
    player::Player meinSpieler(10, pos, false);


    cout << "Hello World" << endl;
    cin >> pos.x;
    meinSpieler.stringBuilder(10, pos, false);
    

    return 0;
}