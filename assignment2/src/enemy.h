#ifndef ENEMY_H
#define ENEMY_H

#include <Godot.hpp>
#include <Area.hpp>

namespace godot {

class Enemy : public Area {
    GODOT_CLASS(Enemy, Area)

private:


public:
    static void _register_methods();

    Enemy();
    ~Enemy();

    void _ready();

    void _init(); // our initializer called by Godot

    void _process(float delta);

    void _on_body_entered(int body_id, Node *body, int body_shape, int area_shape);
};

}

#endif