#ifndef ATTACKLIGHT_H
#define ATTACKLIGHT_H

#include <Godot.hpp>
#include <Area.hpp>

namespace godot {

class AttackLight : public Area {
    GODOT_CLASS(AttackLight, Area)

private:
    time_t time_hit;


public:
    static void _register_methods();

    AttackLight();
    ~AttackLight();

    void _ready();

    void _init();

    void _process(float delta);

    void _on_body_entered(int body_id, Node *body, int body_shape, int area_shape);
};

}

#endif