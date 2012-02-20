#include "ball.h"
#include "utils.h"

Ball::Ball(SDL_Surface *img, int init_x, int init_y) :
    image(img),
    x(init_x),
    y(init_y),
    x_velocity(0),
    y_velocity(0)
{
}

void Ball::step() {
    x += x_velocity;
    y += y_velocity;
}

void Ball::render(SDL_Surface *screen) {
    apply_surface(x, y, image, screen);
}
