#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "SDL/SDL.h"

namespace breakout {
    /**
     * Interface for classes that should be rendered in the game loop
     */
    class Renderable {
    public:
        /**
         * Given the screen surface render itself onto it.
         *
         * @param SDL_Surface *screen The screen
         */
        virtual void render(SDL_Surface *screen) = 0;

        /**
         * Return whether the Renderable is dead yet. Once dead the game loop will
         * remove the object from memory.
         *
         * @return bool Whether dead
         */
        virtual bool is_dead();
    };
}

#endif

// Local Variables:
// mode: c++
// End:
