#include "score_counter.h"
#include <stdexcept>
#include <sstream>
#include "utils.h"

using std::stringstream;

namespace breakout {
    ScoreCounter::ScoreCounter(int initial, string font_name, int font_size,
                               SDL_Color color) :
        score(initial),
        text_color(color),
        x(5),
        y(5),
        font(NULL),
        surface(NULL)
    {
        font = TTF_OpenFont((string("res/") + font_name).c_str(), font_size);
        if (font == NULL) {
            throw std::runtime_error(string("Unable to load font ") + font_name +
                                     ": " + SDL_GetError());
        }
    }

    /**
     * Cleans up the TTF font
     */
    ScoreCounter::~ScoreCounter() {
        TTF_CloseFont(font);
    }
    
    /**
     * Sets the score
     *
     * @param n The new score
     */
    void ScoreCounter::set_score(int n) {
        score = n;
    }

    /**
     * Returns the current score
     *
     * @return The score
     */
    int ScoreCounter::get_score() {
        return score;
    }

    /**
     * Adds the given amount to the score
     *
     * @param n How much to add
     */
    void ScoreCounter::add_score(int n) {
        score += n;
    }

    void ScoreCounter::step() {
        // nothing
    }

    /**
     * Renders the score counter on the screen
     *
     * @param screen The screen
     */
    void ScoreCounter::render(SDL_Surface *screen) {
        SDL_Surface *score_surface;
        stringstream text_score;

        text_score << score;
        surface = TTF_RenderText_Solid(font, text_score.str().c_str(),
                                       text_color);

        if (surface == NULL) {
            throw std::runtime_error("Failed trying to render score counter.");
        }

        // render here
        apply_surface(x, y, surface, screen);
    }

    /**
     * Keep alive. Must be explicitly destroyed.
     */
    bool ScoreCounter::is_dead() {
        return false;
    }

    SDL_Rect ScoreCounter::get_rect() {
        return surface->clip_rect;
    }
}
