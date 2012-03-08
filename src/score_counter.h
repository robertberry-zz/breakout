#ifndef _SCORE_COUNTER_H_
#define _SCORE_COUNTER_H_
#include "renderable.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>

using std::string;

namespace breakout {
    class ScoreCounter : public Renderable {
    private:
        TTF_Font *font;
        SDL_Color text_color;
        SDL_Surface *surface;
        int score;
        int x, y;
    public:
        ScoreCounter(int initial, string font_name, int font_size,
                     SDL_Color color);
        ~ScoreCounter();
        void set_score(int n);
        int get_score();
        void add_score(int n);
        void render(SDL_Surface *screen);
        SDL_Rect get_rect();
    };
}

#endif

// Local Variables:
// mode: c++
// End:
