#ifndef _TIMER_H_
#define _TIMER_H_

#include "SDL/SDL.h"

class Timer {
private:
    bool started;
    bool paused;
    int start_ticks;
    int paused_ticks;
public:
    Timer();

    void start();
    void stop();
    void pause();
    void unpause();

    int get_ticks();
    bool is_started();
    bool is_paused();
};

#endif

// Local Variables:
// mode: c++
// End:
