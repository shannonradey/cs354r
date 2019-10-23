#include "sound.h"

using namespace godot;

void Sound::_register_methods() {
    register_method("_ready", &Sound::_ready);
    register_method("_play", &Sound::_play);
    register_method("_mute", &Sound::_mute);
}

Sound::Sound() {

}

Sound::~Sound() {
}

void Sound::_ready() {    
	is_muted = true;
	stop();
}

void Sound::_init() {
    
}

void Sound::_play() {
	if (!is_muted)
		play();
}

void Sound::_mute() {
	is_muted = !is_muted;
	if (is_muted)
		stop();
	else {
		if (get_parent()->get_name() == "BackgroundMusic")
			play();
	}
}