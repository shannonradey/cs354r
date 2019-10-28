#ifndef ENEMY_H
#define ENEMY_H

#include <Godot.hpp>
#include <KinematicBody.hpp>

namespace godot {

class Enemy : public KinematicBody {
    GODOT_CLASS(Enemy, KinematicBody)

private:
	int speed;


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