#include "SDL/SDL.h"
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <stdexcept>

#include "utils.h"
#include "timer.h"
#include "entity.h"
#include "ball.h"
#include "bat.h"
#include "image_pack.h"

const char *CAPTION = "Breakout";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

enum { ERROR_INITIALIZE = 1,
       ERROR_LOAD_IMAGES,
       ERROR_FLIP };

const int MAXIMUM_FPS = 40;

SDL_Surface *screen = NULL;
SDL_Surface *ball_image = NULL;

SDL_Event event;

bool init();

int main (int argc, char **argv) {
    using breakout::Ball;
    using breakout::Bat;
    using std::cerr;
    using std::mem_fun;
    using std::bind2nd;
    using std::list;
    using std::vector;

    list<Entity*> entities = list<Entity*>();

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
                     SCREEN_HEIGHT / 2, 0, 1);
    Bat bat = Bat(images->get_image("bat.png"), SCREEN_WIDTH / 2,
                  SCREEN_HEIGHT - 50);
    int remaining = 0;

    entities.push_back(&ball);
    entities.push_back(&bat);

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

        /** rendering logic **/
        // white background
        SDL_FillRect(screen, &screen->clip_rect,
                     SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
        for_each(entities.begin(), entities.end(),
                 bind2nd(mem_fun<void, Entity, SDL_Surface *>(&Entity::render),
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

    return 0;
}

bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return false;
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
                              SDL_SWSURFACE);
    if (screen == NULL) return false;
    SDL_WM_SetCaption(CAPTION, NULL);
    return true;
}
