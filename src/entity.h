#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "SDL/SDL.h"

/**
 * Game entity interface. Any object in the game that has logic and / or can be
 * rendered needs to be implemented as a subclass.
 */
class Entity {
public:
    /**
     * Step logic - called once per frame, before rendering.
     */
    virtual void step() = 0;

    /**
     * Given the screen surface render itself onto it.
     *
     * @param SDL_Surface *screen The screen
     */
    virtual void render(SDL_Surface *screen) = 0;

    /**
     * Returns whether the Entity is dead yet. Once dead the game loop will
     * remove the object from memory.
     *
     * @return bool Whether dead
     */
    virtual bool is_dead() = 0;

    /**
     * Returns the rect for collision detection
     *
     * @return The rect
     */
    virtual SDL_Rect get_rect() = 0;
};

#endif

// Local Variables:
// mode: c++
// End:
