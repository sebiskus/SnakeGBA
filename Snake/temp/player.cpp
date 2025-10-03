#include <iostream>

namespace player {
    struct Position {
        int x;
        int y;
    };

    class Player {
        private:
        int size;
        Position position;
        bool visible;
        

        public:
        Player(int size, Position position, bool visible) {
            this->size = size;
            this->position = position;
            this->visible = visible;
        }
        ~Player(){
            std::cout << "Player wurde eliminiert" << std::endl;
        }

        void stringBuilder(int size, Position position, bool visible) {
            std::cout << "Der Player besteht aus "<< size << " und " << position.x << " . Derzeit sichtbar: " << visible << std::endl;
        }
    };
}

