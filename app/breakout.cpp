#include "SDL/SDL.h"
#include <string>
#include <iostream>
#include <vector>

#include "utils.h"
#include "timer.h"
#include "entity.h"
#include "ball.h"

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
bool load_images();

int main (int argc, char **argv) {
    using std::cerr;

    std::vector<Entity*> entities = std::vector<Entity*>();

    if (!init()) {
        cerr << "Error initializing SDL.";
        return ERROR_INITIALIZE;
    }

    if (!load_images()) {
        cerr << "Error loading images.";
        return ERROR_LOAD_IMAGES;
    }

    bool running = true;
    Timer timer = Timer();
    Ball ball = Ball(ball_image, 50, 50);
    int remaining = 0;

    entities.push_back(&ball);

    while (running) {
        timer.start();

        /** game logic **/
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        for (int i = 0; i < entities.size(); ++i) {
            entities[i]->step();
        }

        /** rendering logic **/
        // white background
        SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

        for (int i = 0; i < entities.size(); ++i) {
            entities[i]->render(screen);
        }

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

    return 0;
}

bool init () {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return false;
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL) return false;
    SDL_WM_SetCaption(CAPTION, NULL);
    return true;
}

bool load_images() {
    ball_image = load_image("res/ball.png");

    if (ball_image == NULL) return false;

    return true;
}