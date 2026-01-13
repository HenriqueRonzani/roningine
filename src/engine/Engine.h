//
// Created by ronzani on 1/12/26.
//

#ifndef RONINGINE_END_H
#define RONINGINE_END_H
#include "../event/EventQueue.h"
#include "../input/Input.h"
#include "../platform/sdl/PlatformSDL.h"


class Engine {
    public:
        EventQueue eventQueue;
        bool running = true;

        PlatformSDL* platformSDL{};
        Input input;
        void run();
};


#endif //RONINGINE_END_H