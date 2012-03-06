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
        Uint8 *keystates = SDL_GetKeyState(NULL);
        if (keystates[SDLK_RIGHT]) {
            x_velocity = 10;
        } else if (keystates[SDLK_LEFT]) {
            x_velocity = -10;
        } else {
            x_velocity = 0;
        }
        x += x_velocity;
    }

    void Bat::render(SDL_Surface *screen) {
        apply_surface(x, y, image, screen);
    }

    bool Bat::is_dead() {
        return false;
    }

    SDL_Rect Bat::get_rect() {
        SDL_Rect rect = image->clip_rect;
        rect.x = x;
        rect.y = y;
        return rect;        
    }
}
