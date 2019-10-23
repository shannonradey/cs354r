#ifndef CANDYCOUNTER_H
#define CANDYCOUNTER_H

#include <Godot.hpp>
#include <Label.hpp>
#include <string.h>
#include <string>
#include <String.hpp>
#include <candy.h>
#include <CanvasItem.hpp>
#include <SceneTree.hpp>



namespace godot {

class CandyCounter : public Label {
    GODOT_CLASS(CandyCounter, Label)

private:
    int candy_count;
    bool dead;

public:
    static void _register_methods();

    CandyCounter();
    ~CandyCounter();

    void _init();

    void _ready();
    void _increment();
    int get_count();

    void final();

    void stop();
    void rematch();
    void disconnect();


};

}

#endif