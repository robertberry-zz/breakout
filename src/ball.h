#ifndef _BALL_H_
#define _BALL_H_

#include "SDL/SDL.h"
#include "entity.h"

extern const int SCREEN_HEIGHT;

namespace breakout {
    class Ball: public Entity {
    private:
        SDL_Surface *image;
    public:
        Ball(SDL_Surface *image, int x, int y, int x_vel=0, int y_vel=0);
        void render(SDL_Surface *screen);
        bool is_dead();
        SDL_Rect get_rect();
    };
}

#endif

// Local Variables:
// mode: c++
// End:
