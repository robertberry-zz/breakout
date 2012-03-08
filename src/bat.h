#ifndef _BAT_H_
#define _BAT_H_

#include "entity.h"

namespace breakout {
    class Bat: public Entity {
    private:
        SDL_Surface *image;
    public:
        Bat(SDL_Surface *img, int init_x, int init_y);
        bool is_dead();
        void step();
    };
}

#endif

// Local Variables:
// mode: c++
// End:
