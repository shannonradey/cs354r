#ifndef CAM_H
#define CAM_H

#include <Godot.hpp>
#include <Input.hpp>
#include <Camera.hpp>

namespace godot {

class Cam : public Camera {
    GODOT_CLASS(Cam, Camera)

private:
    Input *input;

public:
    static void _register_methods();

    Cam();
    ~Cam();

    void _init(); // our initializer called by Godot

    void _process(float delta);
    void _ready();
    
};

}

#endif