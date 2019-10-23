#ifndef MENU_H
#define MENU_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <TextEdit.hpp>

namespace godot {

class Menu : public Node2D {
    GODOT_CLASS(Menu, Node2D)

private:
	String playerName;

public:
    static void _register_methods();

    Menu();
    ~Menu();

    void _init();

    void _ready();
    void _process(float delta);


    void create();
    void join();
    void text_changed();
    
  
    void _on_TextField_text_changed(String newText);

    void _on_CreateButton_pressed();

    void _on_JoinButton_pressed();
    
    void _load_game();




};

}

#endif
