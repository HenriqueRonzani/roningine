//
// Created by ronzani on 1/12/26.
//

#ifndef RONINGINE_INPUT_H
#define RONINGINE_INPUT_H
#include <array>

#include "Key.h"
#include "../event/Event.h"

struct InputState {
    bool pressed = false;
    bool released = false;
    bool down = false;
};

class Input {
    std::array<InputState, static_cast<std::size_t>(Key::COUNT)> keys;

    public:
        bool isPressed(Key key) const;
        bool isReleased(Key key) const;
        bool isDown(Key key) const;

        void handleEvent(const Event& event);
        void beginFrame();
};


#endif //RONINGINE_INPUT_H