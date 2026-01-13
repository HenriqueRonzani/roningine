//
// Created by ronzani on 12/23/25.
//

#include "EventQueue.h"

void EventQueue::clear() {
    this->events.clear();
}

void EventQueue::push(const Event event) {
    this->events.push_back(event);
}

bool EventQueue::poll(Event &event) {
    if (!this->events.empty()) {
        event = this->events.front();
        this->events.pop_front();
        return true;
    }
    return false;
}
