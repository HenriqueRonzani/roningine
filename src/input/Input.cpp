//
// Created by ronzani on 1/12/26.
//

#include "Input.h"

bool Input::isDown(Key key) const {
    const auto id = static_cast<std::size_t>(key);

    return keys[id].down;
}

bool Input::isPressed(Key key) const {
    const auto id = static_cast<std::size_t>(key);
    return keys[id].pressed;
}

bool Input::isReleased(Key key) const {
    const auto id = static_cast<std::size_t>(key);
    return keys[id].released;
}

void Input::handleEvent(const Event& event) {
    if (event.type == EventType::KEY_DOWN) {
        const auto id = static_cast<std::size_t>(event.keyEvent.key);
        keys[id].pressed = true;
        keys[id].down = true;
    }
    if (event.type == EventType::KEY_UP) {
        const auto id = static_cast<std::size_t>(event.keyEvent.key);
        keys[id].released = true;
        keys[id].down = false;
    }
}

void Input::beginFrame() {
    for (auto&[pressed, released, down] : keys) {
        down = false;
        released = false;
        pressed = false;
    }
}