#include "ball.h"
#include "utils.h"

extern const int SCREEN_HEIGHT;

namespace breakout {
    Ball::Ball(SDL_Surface *img, int init_x, int init_y, int init_x_vel,
               int init_y_vel) :
        image(img),
        x(init_x),
        y(init_y),
        x_velocity(init_x_vel),
        y_velocity(init_y_vel)
    {
    }

    void Ball::step() {
        x += x_velocity;
        y += y_velocity;
    }

    void Ball::bounce() {
        x_velocity = -x_velocity;
        y_velocity = -y_velocity;
    }

    void Ball::render(SDL_Surface *screen) {
        apply_surface(x, y, image, screen);
    }

    bool Ball::is_dead() {
        return y > SCREEN_HEIGHT;
    }

    SDL_Rect Ball::get_rect() {
        SDL_Rect rect = image->clip_rect;
        rect.x = x;
        rect.y = y;
        return rect;
    }

    int Ball::getX() {
        return x;
    }

    int Ball::getY() {
        return y;
    }
}
