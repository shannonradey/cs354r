#include "enemy.h"

using namespace godot;

void Enemy::_register_methods() {
    register_method("_process", &Enemy::_process);
    register_method("_ready", &Enemy::_ready);
    register_method("_on_body_entered", &Enemy::_on_body_entered);


}

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

void Enemy::_ready() {
    speed = 150;
    get_child(4)->connect("body_shape_entered", this, "_on_body_entered");

}

void Enemy::_init() {

}

void Enemy::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
     if (body->get_name() == "player") {
        Node *node = body->get_child(11)->get_child(0)->get_child(0)->get_child(0)->get_child(1);
        node->call("_decrement");
    }
}

void Enemy::_process(float delta) {
    Array bodies = get_node("Area")->call("get_overlapping_bodies");
    Vector3 move = Vector3();
    int len = bodies.size();
    if (len > 2) {
        for (int i = 2; i < len; i++) {
            Node *node = (Node *)bodies[i];
            if (node->get_name() == "player") {
                Vector3 player_pos = ((Spatial *)node)->get_global_transform().origin;
                Vector3 cur_pos = get_global_transform().origin;
                Godot::print(player_pos.x - cur_pos.x);
                Godot::print(player_pos.z - cur_pos.z);
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
    move_and_slide(move.operator*(3));
}
