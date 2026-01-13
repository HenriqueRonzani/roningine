//
// Created by ronzani on 12/23/25.
//

#ifndef RONINGINE_EVENTQUEUE_H
#define RONINGINE_EVENTQUEUE_H
#include <queue>

#include "Event.h"


class EventQueue {
    std::deque<Event> events;

public:
    void clear();
    void push(Event event);
    bool poll(Event& event);
};


#endif //RONINGINE_EVENTQUEUE_H