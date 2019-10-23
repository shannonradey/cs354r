#ifndef WATCH_H
#define WATCH_H

#include <Godot.hpp>
#include <Label.hpp>
#include <Timer.hpp>
#include <ctime>

namespace godot {

class Watch : public Label {
    GODOT_CLASS(Watch, Label)

private:
    int m;
    int s;
    time_t t;
    bool dead;

public:
    static void _register_methods();

    Watch();
    ~Watch();

    void _init();

    void _ready();
    void _process(float delta);

    void start();

    void stop();


};

}

#endif