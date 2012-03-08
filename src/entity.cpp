#include "entity.h"

namespace breakout {
    Entity::Entity() :
        x(0),
        y(0),
        x_velocity(0),
        y_velocity(0)
    {}

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
