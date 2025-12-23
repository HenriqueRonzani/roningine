//
// Created by ronzani on 12/23/25.
//

#ifndef RONINGINE_EVENT_H
#define RONINGINE_EVENT_H
#include "../input/Key.h"

enum class EventType {
    KEY_DOWN,
    KEY_UP,
    QUIT
};

struct KeyEvent {
    Key key;
    explicit KeyEvent (const Key key) : key(key) {}
};

struct QuitEvent {};

struct Event {
    EventType type;
    union {
        KeyEvent key;
        QuitEvent quit;
    };

    explicit Event (const EventType type, const KeyEvent& k) : type(type), key(k) {}
    explicit Event (const QuitEvent& q) : type(EventType::QUIT), quit(q) {}
};

#endif //RONINGINE_EVENT_H