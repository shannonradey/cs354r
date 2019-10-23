#ifndef SOUND_H
#define SOUND_H

#include <Godot.hpp>
#include <AudioStreamPlayer.hpp>

namespace godot {

class Sound : public AudioStreamPlayer {
    GODOT_CLASS(Sound, AudioStreamPlayer)

private:
	bool is_muted;

public:
    static void _register_methods();

    Sound();
    ~Sound();

    void _init();

    void _ready();
    void _play();

    void _mute();


};

}

#endif