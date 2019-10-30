#include "amap.h"

using namespace godot;

void AMap::_register_methods() {
    register_method("_process", &AMap::_process);
    register_method("_ready", &AMap::_ready);
}

AMap::AMap() {

}

AMap::~AMap() {
    // add your cleanup here
}

void AMap::_init() {
    
}

void AMap::_ready() {
}

void AMap::_process(float delta) {
 
}
