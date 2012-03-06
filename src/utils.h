#ifndef _UTILS_H_
#define _UTILS_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "entity.h"

SDL_Surface *load_image(std::string filename);
void apply_surface(int x, int y, SDL_Surface* source,
                   SDL_Surface* destination, SDL_Rect* clip = NULL);

namespace breakout {
    bool collides(Entity *a, Entity *b);
    bool collides(SDL_Rect a, SDL_Rect b);
}

#endif

// Local Variables:
// mode: c++
// End:
