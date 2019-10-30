#ifndef CANDYGRABBER_H
#define CANDYGRABBER_H

#include <Godot.hpp>
#include <KinematicBody.hpp>

namespace godot {

class CandyGrabber : public KinematicBody {
    GODOT_CLASS(CandyGrabber, KinematicBody)

private:
	int speed;
	Array waypoints;
	int num_waypoints;
	Vector3 target;
	Vector3 prev_pos;
	time_t time_hit;


public:
    static void _register_methods();

    CandyGrabber();
    ~CandyGrabber();

    void _ready();
    void set_target();
    void hit_ledge();

    void _init(); // our initializer called by Godot

    void _process(float delta);

    void _on_body_entered(int body_id, Node *body, int body_shape, int area_shape);
};

}

#endif