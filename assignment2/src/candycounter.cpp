#include "candycounter.h"

using namespace godot;

void CandyCounter::_register_methods() {
    register_method("_ready", &CandyCounter::_ready);
    register_method("_increment", &CandyCounter::_increment);
    register_method("get_count", &CandyCounter::get_count);
    register_method("final", &CandyCounter::final);
    register_method("stop", &CandyCounter::stop);
    register_method("rematch", &CandyCounter::rematch);
    register_method("disconnect", &CandyCounter::disconnect);
}

CandyCounter::CandyCounter() {

}

CandyCounter::~CandyCounter() {
}

void CandyCounter::_ready() {   
    if (get_name() == "Label2")
		((CanvasItem *)get_parent()->get_parent())->set_visible(false);
	dead = false;
}

void CandyCounter::_init() {
    candy_count = 0;
    set_text(String::num_int64(candy_count));
}

void CandyCounter::_increment() {
	if (!dead)
    	set_text(String::num_int64(++candy_count));
}

int CandyCounter::get_count() {
    return candy_count;
}

void CandyCounter::stop() {
	dead = true;
}

void CandyCounter::final() {
    if (is_network_master()) {
	    ((CanvasItem *)get_parent()->get_parent())->set_visible(true);
        Node *node = get_parent()->get_child(2);
        node->connect("pressed", this, "disconnect");
        node = get_parent()->get_child(3);
        node->connect("pressed", this, "rematch");
	    dead = true;
    }
}

void CandyCounter::rematch() {
    Godot::print("Rematch");
    get_tree()->change_scene("res://Lobby.tscn");

}

void CandyCounter::disconnect() {
    Godot::print("disconnect");
    get_tree()->quit();
}