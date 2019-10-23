#ifndef CANDY_H
#define CANDY_H

#include <Godot.hpp>
#include <Area.hpp>
#include <candycounter.h>
#include <player.h>
#include <ctime>
#include <NodePath.hpp>

namespace godot {

class Candy : public Area {
    GODOT_CLASS(Candy, Area)

private:
    time_t time_hit;


public:
    static void _register_methods();

    Candy();
    ~Candy();

    void _ready();

    void _init(); // our initializer called by Godot

    void _process(float delta);

    void _on_body_entered(int body_id, Node *body, int body_shape, int area_shape);
};

}

#endif