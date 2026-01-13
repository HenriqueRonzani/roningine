//
// Created by ronzani on 1/12/26.
//

#include "Engine.h"

#include <SDL3/SDL_events.h>

#include "../event/EventQueue.h"
#include "../platform/sdl/PlatformSDL.h"

void Engine::run() {
    while (running) {
        eventQueue.clear();
        platformSDL->pollEvents(eventQueue);

        input.beginFrame();

        Event event;
        while (eventQueue.poll(event)) {
            if (event.type == EventType::QUIT) {
                running = false;
                break;
            }
            input.handleEvent(event);
        }

        // Handle render
    }
}
