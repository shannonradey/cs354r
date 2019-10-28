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
    this->connect("body_shape_entered", this, "_on_body_entered");

}


void Enemy::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
    
}

void Enemy::_init() {

}

void Enemy::_process(float delta) {
    Array bodies = get_overlapping_bodies();
    int len = bodies.size();
    for (int i = 0; i < len; i++) {
        Godot::print(bodies[i].get_type());
    }
}
