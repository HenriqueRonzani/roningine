//
// Created by ronzani on 12/23/25.
//


#include <optional>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>

#include "PlatformSDL.h"
#include "../../event/Event.h"
#include "../../event/EventQueue.h"

Key PlatformSDL::convertKey(const SDL_Keycode sdl_keycode) {
    switch (sdl_keycode) {
        case (SDLK_Z): return Key::Z;
        case (SDLK_X): return Key::X;
        case (SDLK_C): return Key::C;
        case (SDLK_V): return Key::V;

        case (SDLK_W): return Key::W;
        case (SDLK_A): return Key::A;
        case (SDLK_S): return Key::S;
        case (SDLK_D): return Key::D;

        case (SDLK_UP): return Key::UP;
        case (SDLK_DOWN): return Key::DOWN;
        case (SDLK_LEFT): return Key::LEFT;
        case (SDLK_RIGHT): return Key::RIGHT;

        case (SDLK_1): return Key::NUM_1;
        case (SDLK_2): return Key::NUM_2;
        case (SDLK_3): return Key::NUM_3;
        case (SDLK_4): return Key::NUM_4;
        case (SDLK_5): return Key::NUM_5;
        case (SDLK_6): return Key::NUM_6;
        case (SDLK_7): return Key::NUM_7;

        case (SDLK_SPACE): return Key::SPACE;
        case (SDLK_RETURN): return Key::RETURN;

        case (SDLK_LSHIFT):
        case (SDLK_RSHIFT): return Key::SHIFT;

        case (SDLK_LCTRL):
        case (SDLK_RCTRL): return Key::CTRL;

        case (SDLK_ESCAPE): return Key::ESCAPE;

        default: return Key::Unknown;
    }
}

std::optional<Event> PlatformSDL::convertEvent(const SDL_Event &sdl_event) {
    switch (sdl_event.type) {
        case (SDL_EVENT_KEY_DOWN):
            return Event(
                EventType::KEY_DOWN,
                KeyEvent(convertKey(sdl_event.key.key))
            );

        case (SDL_EVENT_KEY_UP):
            return Event(
                EventType::KEY_UP,
                KeyEvent(convertKey(sdl_event.key.key))
            );

        case (SDL_EVENT_QUIT):
            return Event(QuitEvent{});

        default:
            return std::nullopt;
    }
}

void PlatformSDL::pollEvents(EventQueue &event_queue) {
    SDL_Event sdl_event;

    while (SDL_PollEvent(&sdl_event)) {
        if (auto event = convertEvent(sdl_event)) {
            event_queue.push(*event);
        }
    }
}
