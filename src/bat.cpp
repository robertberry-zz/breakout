#include "bat.h"
#include "utils.h"

namespace breakout {
    Bat::Bat(SDL_Surface *img, int init_x, int init_y) :
        image(img),
        x(init_x),
        y(init_y),
        x_velocity(0)
    {}

    void Bat::step() {
        x += x_velocity;
    }

    void Bat::render(SDL_Surface *screen) {
        apply_surface(x, y, image, screen);
    }

    bool Bat::is_dead() {
        return false;
    }
}
