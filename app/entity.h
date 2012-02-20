#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "SDL/SDL.h"

class Entity {
 public:
    virtual void step() = 0;
    virtual void render(SDL_Surface *screen) = 0;
};

#endif
