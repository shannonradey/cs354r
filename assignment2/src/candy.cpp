#include "candy.h"

using namespace godot;

void Candy::_register_methods() {
    register_method("_process", &Candy::_process);
    register_method("_ready", &Candy::_ready);
    register_method("_on_body_entered", &Candy::_on_body_entered);


}

Candy::Candy() {

}

Candy::~Candy() {

}

void Candy::_ready() {
    this->connect("body_shape_entered", this, "_on_body_entered");
    set_name("candy");

}


void Candy::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
    if (body->get_name() == "player") {
        String name = get_parent()->get_parent()->get_name();
        String ledge = name;

        if ((name == "Ledge") || (name == "Ledge1A") || (name == "Ledge2") || (name == "Ledge3") || (name == "Ledge4")){
            body->call("_hang");
        }
        else {
            if (is_visible()) {
                Node *counter = body->get_child(11)->get_child(0)->get_child(1)->get_child(0)->get_child(0)->get_child(1);
                Node *coin_noise = body->get_child(11)->get_child(0)->get_child(1)->get_child(0)->get_child(0)->get_child(2);
                Node *final = body->get_child(10)->get_child(0)->get_child(1);
                counter->call("_increment");
                final->call("_increment");
                coin_noise->call("_play");
                set_visible(false);
                time_hit = time(NULL);
                set_name("nocandy");
            }
        }
    }
    if (body->get_name() == "candygrabber")
    {
        if (is_visible()) {
            set_visible(false);
            time_hit = time(NULL);
            set_name("nocandy");
        }
    }
}

void Candy::_init() {

}

void Candy::_process(float delta) {
    rotate_y(.1);
    if (!is_visible()) {
        if (time(NULL) - 10 > time_hit) {
            set_visible(true);
            set_name("candy");
        }

    }
}
