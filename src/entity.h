#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "SDL/SDL.h"
#include "renderable.h"

namespace breakout {
    /**
     * Interface for classes that need both to be rendered and to have step logic
     * for each frame.
     */
    class Entity : public Renderable {
    private:
        int x, y;
        int x_velocity, y_velocity;
        SDL_Surface *image;
    public:
        Entity(SDL_Surface *image);

        /**
         * Renders the Entity on to the screen
         *
         * @param screen The screen
         */
        void render(SDL_Surface *screen);

        /**
         * Sets the x co-ordinate of the entity
         *
         * @param n The new x co-ordinate
         */
        void set_x(int n);

        /**
         * Sets the y co-ordinate of the entity
         *
         * @param n The new y co-ordinate
         */
        void set_y(int n);

        /**
         * Returns the x co-ordinate of the entity
         *
         * @return The x co-ordinate
         */
        int get_x();

        /**
         * Returns the y co-ordinate of the entity
         *
         * @return The y co-ordinate
         */
        int get_y();

        /**
         * Sets the x velocity of the entity
         *
         * @param n The new velocity
         */
        void set_x_velocity(int n);

        /**
         * Sets the y velocity of the entity
         *
         * @param n The new velocity 
         */
        void set_y_velocity(int n);

        /**
         * Returns the x velocity of the entity
         *
         * @return The x velocity
         */
        int get_x_velocity();

        /**
         * Returns the y velocity of the entity
         *
         * @return The y velocity
         */
        int get_y_velocity();
        
        /**
         * Step logic - called once per frame, before rendering.
         */
        virtual void step();

        /**
         * Returns the rect for collision detection.
         *
         * @return The rect
         */
        SDL_Rect get_rect();

        /**
         * Return whether the Entity is dead yet. Once dead the game loop will
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
