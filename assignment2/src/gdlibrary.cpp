#include "player.h"
#include "candy.h"
#include "candycounter.h"
#include "sound.h"
#include "attacklight.h"
#include "healthbar.h"
#include "cam.h"
#include "watch.h"
#include "mybutton.h"
#include "menu.h"
#include "network.h"
#include "game.h"
#include "enemy.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);
    godot::register_class<godot::Player>();
    godot::register_class<godot::Candy>();
    godot::register_class<godot::CandyCounter>();
    godot::register_class<godot::Sound>();
    godot::register_class<godot::AttackLight>();
    godot::register_class<godot::Healthbar>();

    godot::register_class<godot::Cam>();
    godot::register_class<godot::MyButton>();
    godot::register_class<godot::Watch>();
    godot::register_class<godot::Menu>();
    godot::register_class<godot::Game>();
    godot::register_class<godot::Network>();
    godot::register_class<godot::Enemy>();
}
