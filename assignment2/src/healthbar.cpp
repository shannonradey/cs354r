#include "healthbar.h"

using namespace godot;

void Healthbar::_register_methods() {
    register_method("_ready", &Healthbar::_ready);
    register_method("_decrement", &Healthbar::_decrement);

    register_signal<Healthbar>((char*)"dead");
    register_signal<Healthbar>((char*)"light_hit");
}

Healthbar::Healthbar() {
}

Healthbar::~Healthbar() {
}

void Healthbar::_ready() {    
	set_value(100);
    Node *node = get_parent()->get_child(2);
    this->connect("dead", node, "_play");
    node = get_parent()->get_parent()->get_parent()->get_parent()->get_parent();
    this->connect("dead", node, "_die");
    node = node->get_child(10)->get_child(0)->get_child(1);
    this->connect("dead", node, "final");
    node = get_parent()->get_child(3);
    this->connect("light_hit", node, "_play");
}

void Healthbar::_init() {

}

void Healthbar::_decrement() {
    set_value(get_value() - 25);
    if (get_value() > 0) {
        emit_signal("light_hit");
    } else {
        emit_signal("dead");
    }
}