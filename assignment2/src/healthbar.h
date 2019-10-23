#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <Godot.hpp>
#include <TextureProgress.hpp>
#include <unistd.h>

namespace godot {

class Healthbar : public TextureProgress {
    GODOT_CLASS(Healthbar, TextureProgress)

private:
    time_t time_hit;


public:
    static void _register_methods();

    Healthbar();
    ~Healthbar();

    void _ready();

    void _init();

    void _decrement();

};

}

#endif