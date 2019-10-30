#ifndef AMAP_H
#define AMAP_H

#include <Godot.hpp>
#include <Spatial.hpp>

namespace godot {

class AMap : public Spatial {
    GODOT_CLASS(AMap, Spatial)

private:
	Dictionary all_points = Dictionary();
	AStar as;

public:
    static void _register_methods();

    AMap();
    ~AMap();

    void _init(); // our initializer called by Godot

    void _process(float delta);
    void _ready();
    
};

}

#endif