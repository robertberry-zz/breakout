#include "ball.h"

namespace breakout {
    Ball::Ball(SDL_Surface *img, int init_x, int init_y, int init_x_vel,
               int init_y_vel) :
        Entity(img)
    {
        set_x(init_x); set_y(init_y);
        set_x_velocity(init_x_vel); set_y_velocity(init_y_vel);
    }
}
