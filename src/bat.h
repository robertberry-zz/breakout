#ifndef _BAT_H_
#define _BAT_H_

#include "entity.h"

namespace breakout {
    class Bat: public Entity {
    private:
        SDL_Surface *image;
        int x, y;
        int x_velocity;
    public:
        Bat(SDL_Surface *img, int init_x, int init_y);
        void step();
        void render(SDL_Surface *screen);
        bool is_dead();
    };
}

#endif

// Local Variables:
// mode: c++
// End:
