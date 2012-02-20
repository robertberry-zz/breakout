#include "timer.h"

Timer::Timer() {
    started = false;
    paused = false;
    start_ticks = 0;
    paused_ticks = 0;
}

void Timer::start() {
    started = true;
    paused = false;
    start_ticks = SDL_GetTicks();
}

void Timer::stop() {
    paused = false;
    started = false;
}

int Timer::get_ticks() {
    if (started) {
        if (paused) {
            return paused_ticks;
        } else {
            return SDL_GetTicks() - start_ticks;
        }
    }

    // error would be better
    return 0;
}

void Timer::pause() {
    if (started && !paused) {
        paused = true;
        paused_ticks = SDL_GetTicks() - start_ticks;
    }
}

void Timer::unpause() {
    if (paused) {
        paused = false;
        start_ticks = SDL_GetTicks() - paused_ticks;
        paused_ticks = 0;
    }
}

bool Timer::is_paused() {
    return paused;
}

bool Timer::is_started() {
    return started;
}


