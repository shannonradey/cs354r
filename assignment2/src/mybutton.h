#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <Godot.hpp>
#include <Button.hpp>

namespace godot {

class MyButton : public Button {
    GODOT_CLASS(MyButton, Button)

private:


public:
    static void _register_methods();

    MyButton();
    ~MyButton();

    void _ready();

    void _init();

    void mute();
};

}

#endif