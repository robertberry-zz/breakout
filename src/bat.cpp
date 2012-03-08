#include "bat.h"

namespace breakout {
    Bat::Bat(SDL_Surface *img, int init_x, int init_y) :
        Entity(img)
    {
        set_x(init_x); set_y(init_y);
    }

    void Bat::step() {
        Uint8 *keystates = SDL_GetKeyState(NULL);
        if (keystates[SDLK_RIGHT]) {
            set_x_velocity(10);
        } else if (keystates[SDLK_LEFT]) {
            set_x_velocity(-10);
        } else {
            set_x_velocity(0);
        }
        Entity::step();
    }

    bool Bat::is_dead() {
        return false;
    }
}
