#include "candygrabber.h"

using namespace godot;

void CandyGrabber::_register_methods() {
    register_method("_process", &CandyGrabber::_process);
    register_method("_ready", &CandyGrabber::_ready);
    register_method("_on_body_entered", &CandyGrabber::_on_body_entered);
    register_method("set_target", &CandyGrabber::set_target);
    register_method("hit_ledge", &CandyGrabber::hit_ledge);


}

CandyGrabber::CandyGrabber() {

}

CandyGrabber::~CandyGrabber() {

}

void CandyGrabber::_ready() {
    speed = 150;
    get_child(3)->connect("body_shape_entered", this, "_on_body_entered");
    waypoints = get_parent()->get_parent()->get_node("Waypoints")->get_children();
    num_waypoints = waypoints.size();
    set_target();
    prev_pos = get_global_transform().origin;
    time_hit = time(NULL);
    set_name("candygrabber");
}

void CandyGrabber::_init() {

}

void CandyGrabber::set_target() {
    int i = rand() % num_waypoints;
    Vector3 new_target = ((Spatial *)waypoints[i])->get_global_transform().origin;
    target.x = round(int(new_target.x));
    target.z = round(int(new_target.z));
}


void CandyGrabber::hit_ledge() {
    Vector3 new_target = ((Spatial *)waypoints[0])->get_global_transform().origin;
    target.x = round(int(new_target.x));
    target.z = round(int(new_target.z));
}

void CandyGrabber::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
    set_target();
}

void CandyGrabber::_process(float delta) {
    Array bodies = get_node("Area")->call("get_overlapping_areas");
    Vector3 move = Vector3();
    int len = bodies.size();
    Vector3 cur_pos = get_global_transform().origin;
    if (time(NULL) - 3 > time_hit) {
        for (int i = 0; i < len; i++) {
            Node *node = (Node *)bodies[i];
            if (node->get_name() == "candy") {
                Vector3 player_pos = ((Spatial *)node)->get_global_transform().origin;
                if (player_pos.x < cur_pos.x) {
                    move.x += -1;
                }
                else if (player_pos.x > cur_pos.x) {
                    move.x += 1;
                }
                if (player_pos.z > cur_pos.z) {
                    move.z += 1;
                }
                else if (player_pos.z < cur_pos.z) {
                    move.z += -1;
                }
                if (player_pos.y > cur_pos.y) {
                    move.y += 1;
                }
                else if (player_pos.y < cur_pos.y) {
                    move.y += -1;
                }
                move_and_slide((move.operator*(4)));
                return;
            }
        }
    }
    if (move.x == 0 && move.z == 0) {
        if (int(round(cur_pos.x)) == target.x && int(round(cur_pos.z)) == target.z) {
            set_target();
        }
        if (target.x < cur_pos.x) {
            move.x += -1;
        }
        else if (target.x > cur_pos.x) {
            move.x += 1;
        }
        if (target.z > cur_pos.z) {
            move.z += 1;
        }
        else if (target.z < cur_pos.z) {
            move.z += -1;
        }
        if (target.y > cur_pos.y) {
            move.y += 1;
        }
        else if (target.y < cur_pos.y) {
            move.y += -1;
        
        }
    }
    move_and_slide((move.operator*(4)));
}
