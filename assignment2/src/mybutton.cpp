#include "mybutton.h"

using namespace godot;

void MyButton::_register_methods() {
    register_method("_ready", &MyButton::_ready);
    register_method("mute", &MyButton::mute);
    
	register_signal<MyButton>((char*) "mute");

}

MyButton::MyButton() {

}

MyButton::~MyButton() {
}



void MyButton::_ready() {
    this->connect("pressed", this, "mute");
    Node *node = get_parent()->get_child(9)->get_child(0);
    this->connect("mute", node, "_mute");
    node = get_parent()->get_child(11)->get_child(0)->get_child(0)->get_child(0)->get_child(2);
    this->connect("mute", node, "_mute");
    node = get_parent()->get_child(11)->get_child(0)->get_child(0)->get_child(0)->get_child(3);
    this->connect("mute", node, "_mute");
    node = get_parent()->get_child(11)->get_child(0)->get_child(1)->get_child(0)->get_child(0)->get_child(2);
    this->connect("mute", node, "_mute");

}

void MyButton::_init() {
}

void MyButton::mute() {
	// Godot::print("here");
	emit_signal("mute");
    release_focus();
}