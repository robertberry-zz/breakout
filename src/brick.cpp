#include "brick.h"

namespace breakout {
    Brick::Brick(SDL_Surface *img) :
        Entity(img),
        alive(true)
    {}
    
    bool Brick::is_dead() {
        return !alive;
    }

    void Brick::destroy() {
        alive = false;
    }
}
