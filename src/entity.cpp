#include "entity.h"
#include "utils.h"

namespace breakout {
    Entity::Entity(SDL_Surface *img) :
        x(0),
        y(0),
        x_velocity(0),
        y_velocity(0),
        image(img)
    {}

    void Entity::render(SDL_Surface *screen) {
        apply_surface(get_x(), get_y(), image, screen);
    }

    SDL_Rect Entity::get_rect() {
        SDL_Rect rect = image->clip_rect;
        rect.x = get_x();
        rect.y = get_y();
        return rect;
    }
    
    void Entity::set_x(int n) {
        x = n;
    }

    void Entity::set_y(int n) {
        y = n;
    }

    int Entity::get_x() {
        return x;
    }

    int Entity::get_y() {
        return y;
    }

    void Entity::set_x_velocity(int n) {
        x_velocity = n;
    }

    void Entity::set_y_velocity(int n) {
        y_velocity = n;
    }

    int Entity::get_x_velocity() {
        return x_velocity;
    }

    int Entity::get_y_velocity() {
        return y_velocity;
    }

    void Entity::step() {
        set_x(get_x() + get_x_velocity());
        set_y(get_y() + get_y_velocity());
    }
}
