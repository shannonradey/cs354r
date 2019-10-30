#ifndef ENEMY_H
#define ENEMY_H

#include <Godot.hpp>
#include <KinematicBody.hpp>
#include <stdlib.h>
#include <MeshInstance.hpp>

namespace godot {

class Enemy : public KinematicBody {
    GODOT_CLASS(Enemy, KinematicBody)

private:
	int speed;
	Array waypoints;
	int num_waypoints;
	Vector3 target;
	Vector3 prev_pos;
	time_t time_hit;
	bool bottom;


public:
    static void _register_methods();

    Enemy();
    ~Enemy();

    void _ready();

    void _init(); // our initializer called by Godot

    void _process(float delta);
    void set_target();
    void hit_ledge();

    void _on_body_entered(int body_id, Node *body, int body_shape, int area_shape);
};

}

#endif