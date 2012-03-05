#ifndef _BALL_H_
#define _BALL_H_

#include "SDL/SDL.h"
#include "entity.h"

extern const int SCREEN_HEIGHT;

class Ball: public Entity {
private:
    SDL_Surface *image;
    int x, y;
    int x_velocity, y_velocity;
public:
    Ball(SDL_Surface *image, int x, int y, int x_vel=0, int y_vel=0);
    virtual void step();
    virtual void render(SDL_Surface *screen);
    bool is_dead();
};

#endif

// Local Variables:
// mode: c++
// End:
