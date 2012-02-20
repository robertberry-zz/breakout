#ifndef _BALL_H_
#define _BALL_H_

#include "SDL/SDL.h"
#include "entity.h"

class Ball: public Entity {
private:
    SDL_Surface *image;
    int x, y;
    int x_velocity, y_velocity;
public:
    Ball(SDL_Surface *image, int x, int y);
    virtual void step();
    virtual void render(SDL_Surface *screen);
};

#endif
