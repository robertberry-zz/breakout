#ifndef _BAT_H_
#define _BAT_H_

#include "entity.h"

namespace breakout {
    class Bat: public Entity {
    private:
        SDL_Surface *image;
    public:
        Bat(SDL_Surface *img, int init_x, int init_y);
        void render(SDL_Surface *screen);
        bool is_dead();
        void step();
        SDL_Rect get_rect();
    };
}

#endif

// Local Variables:
// mode: c++
// End:
