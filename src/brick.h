#ifndef _BRICK_H_
#define _BRICK_H_

#include "entity.h"

namespace breakout {
    class Brick: public Entity {
    private:
        bool alive;
    public:
        Brick(SDL_Surface *image);
        virtual bool is_dead();
        void destroy();
    };
}

#endif

// Local Variables:
// mode: c++
// End:
