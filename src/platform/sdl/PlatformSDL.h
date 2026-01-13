//
// Created by ronzani on 12/23/25.
//

#ifndef RONINGINE_ADAPTER_H
#define RONINGINE_ADAPTER_H
#include <optional>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>

#include "../../event/Event.h"
#include "../../event/EventQueue.h"


class PlatformSDL {
    public:
        static Key convertKey (SDL_Keycode sdl_keycode);
        static std::optional<Event> convertEvent (const SDL_Event &sdl_event);
        void pollEvents(EventQueue &event_queue);
};


#endif //RONINGINE_ADAPTER_H