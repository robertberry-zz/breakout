#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <stdexcept>

#include "utils.h"
#include "timer.h"
#include "renderable.h"
#include "entity.h"
#include "ball.h"
#include "bat.h"
#include "image_pack.h"
#include "score_counter.h"

const char *CAPTION = "Breakout";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

enum { ERROR_INITIALIZE = 1,
       ERROR_LOAD_IMAGES,
       ERROR_FLIP };

const int MAXIMUM_FPS = 50;

SDL_Surface *screen = NULL;
SDL_Event event;

void clean_up();
bool init();

int main (int argc, char **argv) {
    using namespace breakout;
    using namespace std;

    list<Entity*> entities = list<Entity*>();
    list<Renderable*> renders = list<Renderable*>();

    if (!init()) {
        cerr << "Error initializing SDL.";
        return ERROR_INITIALIZE;
    }

    const char *paths[] = {"ball.png", "bat.png"};
    vector<string> image_paths(paths, paths + sizeof(paths) / sizeof(char*));
    ImagePack *images;

    try {
        images = new ImagePack(image_paths);
    } catch (std::runtime_error e) {
        cerr << "Error loading images.";
        return ERROR_LOAD_IMAGES;
    }

    bool running = true;
    Timer timer = Timer();
    Ball ball = Ball(images->get_image("ball.png"), SCREEN_WIDTH / 2,
                     SCREEN_HEIGHT / 2, 5, 7);
    Bat bat = Bat(images->get_image("bat.png"), SCREEN_WIDTH / 2,
                  SCREEN_HEIGHT - 50);
    SDL_Color score_color = {0, 0, 0};
    ScoreCounter score = ScoreCounter(0, string("LiberationSans-Regular.ttf"), 20,
                                      score_color);
    int remaining = 0;

    entities.push_back(&ball);
    entities.push_back(&bat);

    renders.push_back(&ball);
    renders.push_back(&bat);
    renders.push_back(&score);

    int bat_width = bat.get_rect().w;
    int ball_width = ball.get_rect().w;
    int ball_height = ball.get_rect().h;

    while (running) {
        timer.start();

        /** game logic **/
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        for_each(entities.begin(), entities.end(), mem_fun(&Entity::step));
        remove_if(entities.begin(), entities.end(), mem_fun(&Entity::is_dead));
        
        if (collides(&ball, &bat)) {
            ball.set_x_velocity(-ball.get_x_velocity());
            ball.set_y_velocity(-ball.get_y_velocity());
        }

        if (ball.get_x() < 0 || ball.get_x() >= SCREEN_WIDTH - ball_width) {
            ball.set_x_velocity(-ball.get_x_velocity());
        }

        if (ball.get_y() < 0 || ball.get_y() >= SCREEN_HEIGHT - ball_height) {
            ball.set_y_velocity(-ball.get_y_velocity());
        }
        
        if (bat.get_x() < 0) {
            bat.set_x(0);
        } else if (bat.get_x() > SCREEN_WIDTH - bat_width) {
            bat.set_x(SCREEN_WIDTH - bat_width);
        }

        /** rendering logic **/
        // white background
        SDL_FillRect(screen, &screen->clip_rect,
                     SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
        for_each(renders.begin(), renders.end(),
                 bind2nd(mem_fun<void, Renderable, SDL_Surface *>(&Renderable::render),
                         screen));

        /** limit framerate **/
        
        remaining = 1000 / MAXIMUM_FPS - timer.get_ticks();

        if (SDL_Flip(screen) == -1) {
            cerr << "Flip error.";
            return ERROR_FLIP;
        }
        
        if (remaining > 0) {
            SDL_Delay(remaining);
        }
    }

    delete images;

    clean_up();

    return 0;
}

/**
 * Closes external libraries (SDL, TTF)
 */
void clean_up() {
    TTF_Quit();
    SDL_Quit();
}

/**
 * Sets up external libraries and window
 */
bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return false;
    }

    if (TTF_Init() == -1) {
        return false;
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
                              SDL_SWSURFACE);
    if (screen == NULL) return false;
    SDL_WM_SetCaption(CAPTION, NULL);
    return true;
}
