#include "bat.h"
#include "utils.h"

namespace breakout {
    Bat::Bat(SDL_Surface *img, int init_x, int init_y) :
        image(img)
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

    void Bat::render(SDL_Surface *screen) {
        apply_surface(get_x(), get_y(), image, screen);
    }

    bool Bat::is_dead() {
        return false;
    }

    SDL_Rect Bat::get_rect() {
        SDL_Rect rect = image->clip_rect;
        rect.x = get_x();
        rect.y = get_y();
        return rect;        
    }
}
