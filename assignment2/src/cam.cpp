#include "cam.h"

using namespace godot;

void Cam::_register_methods() {
    register_method("_process", &Cam::_process);
    register_method("_ready", &Cam::_ready);
}

Cam::Cam() {

}

Cam::~Cam() {
    // add your cleanup here
}

void Cam::_init() {
    input = Input::get_singleton();
}

void Cam::_ready() {
}

void Cam::_process(float delta) {

	if (input->is_action_pressed("left_a")) {
		get_parent_spatial()->rotate_y(-.1);
	}
	if (input->is_action_pressed("right_d")) {
		get_parent_spatial()->rotate_y(.1);
	}
 
}
