#include "attacklight.h"

using namespace godot;

void AttackLight::_register_methods() {
    register_method("_process", &AttackLight::_process);
    register_method("_ready", &AttackLight::_ready);
    register_method("_on_body_entered", &AttackLight::_on_body_entered);
}

AttackLight::AttackLight() {

}

AttackLight::~AttackLight() {
}

void AttackLight::_ready() {
    this->connect("body_shape_entered", this, "_on_body_entered");
}


void AttackLight::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
    if (body->get_name() == "player") {
	    Node *node = body->get_child(11)->get_child(0)->get_child(0)->get_child(0)->get_child(1);
	    node->call("_decrement");
	}
}


void AttackLight::_init() {
}

void AttackLight::_process(float delta) {

}
