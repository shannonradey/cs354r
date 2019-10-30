#include "candygrabber.h"

using namespace godot;

void CandyGrabber::_register_methods() {
    register_method("_process", &CandyGrabber::_process);
    register_method("_ready", &CandyGrabber::_ready);
    register_method("_on_body_entered", &CandyGrabber::_on_body_entered);


}

CandyGrabber::CandyGrabber() {

}

CandyGrabber::~CandyGrabber() {

}

void CandyGrabber::_ready() {
    speed = 150;
    get_child(3)->connect("body_shape_entered", this, "_on_body_entered");
    set_name("candygrabber");
}

void CandyGrabber::_init() {

}

void CandyGrabber::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
    //  if (body->get_name() == "player") {
    //     Node *node = body->get_child(11)->get_child(0)->get_child(0)->get_child(0)->get_child(1);
    //     node->call("_decrement");
    // }
}

void CandyGrabber::_process(float delta) {
    Array bodies = get_node("Area")->call("get_overlapping_areas");
    Vector3 move = Vector3();
    int len = bodies.size();
    for (int i = 0; i < len; i++) {
        Node *node = (Node *)bodies[i];
        if (node->get_name() == "candy") {
            Vector3 player_pos = ((Spatial *)node)->get_global_transform().origin;
            Vector3 cur_pos = get_global_transform().origin;
            if (player_pos.y < cur_pos.y) {
                
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
                
            }
        }        
    }
    move_and_slide((move.operator*(3)).normalized());
}
