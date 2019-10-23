#include "watch.h"

using namespace godot;

void Watch::_register_methods() {
    register_method("_ready", &Watch::_ready);
    register_method("_process", &Watch::_process);
    register_method("start", &Watch::start);
    register_method("stop", &Watch::stop);
}

Watch::Watch() {
}

Watch::~Watch() {
}

void Watch::_ready() {

}

void Watch::_init() {
    s = 5;
    m = 0;

    dead = false;
    t = time(NULL);
}

void Watch::_process(float delta) {
    if (!dead && m >= 0){
        if (time(NULL) - 1 > t){
            start();
            t = time(NULL);
        }

        if (s < 0) {
            m -= 1;
            s = 59;
        }
        set_text(String::num_int64(m) + ":" + String::num_int64(s));
    }
    if (m == 0 && s == 0){
        stop();
    }
    
}


void Watch::start() {
    s -= 1;
}

void Watch::stop() {
    dead = true;
    set_text("0:0");
   
}