#include "ball.h"
#include "utils.h"

extern const int SCREEN_HEIGHT;

namespace breakout {
    Ball::Ball(SDL_Surface *img, int init_x, int init_y, int init_x_vel,
               int init_y_vel) :
        image(img)
    {
        set_x(init_x); set_y(init_y);
        set_x_velocity(init_x_vel); set_y_velocity(init_y_vel);
    }

    void Ball::render(SDL_Surface *screen) {
        apply_surface(get_x(), get_y(), image, screen);
    }

    bool Ball::is_dead() {
        return get_y() > SCREEN_HEIGHT;
    }

    SDL_Rect Ball::get_rect() {
        SDL_Rect rect = image->clip_rect;
        rect.x = get_x();
        rect.y = get_y();
        return rect;
    }
}
