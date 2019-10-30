#include "player.h"
#include <SceneTree.hpp>

using namespace godot;

void Player::_register_methods() {
    register_method("_physics_process", &Player::_fixed_process);
    register_method("_hang", &Player::_hang);
    register_method("_ready", &Player::_ready);
    register_method("_die", &Player::_die);
    register_method("init", &Player::init);

    register_signal<Player>((char*)"dead");

    register_property<Player, Transform>("slavePosition", &Player::slavePosition, Transform(), GODOT_METHOD_RPC_MODE_PUPPET);
    register_property<Player, Vector3>("slaveMovement", &Player::slaveMovement, Vector3(), GODOT_METHOD_RPC_MODE_PUPPET);

    register_property<Player, int64_t>("nodeName", &Player::nodeName, 0, GODOT_METHOD_RPC_MODE_DISABLED);
}

Player::Player() {
}

Player::~Player() {
}

void Player::_init() {
    alive = true;
    gravity = 9.8;
    time_passed = 0.0;
    velocity = Vector3(0, 0, 0);
    input = Input::get_singleton();
    x = 0;
    is_hanging = false;
    edge = "";
    t = time(NULL);
    nodeName = 0;
    slavePosition = Transform();
    slaveMovement = Vector3();
}

void Player::_die() {
    set_visible(false);
    alive = false;
    remove_child(get_child(5));
    remove_child(get_child(5));
}

void Player::_ready() {
    Node *node = this->get_child(10)->get_child(0)->get_child(1);
    this->connect("dead", node, "final");
}

void Player::_fixed_process(float delta) {
    if (!alive)
        return;
    velocity = Vector3(0, 0, 0);
    Vector3 cur;
    Vector3 floor_normal = Vector3(0, 1, 0);

    if (is_network_master())
    {
        if (is_hanging == true) {
            Vector3 rotation = get_rotation();
            gravity = 0.0;
            if ((edge == "Ledge") || (edge == "Ledge1A")) {
                set_rotation(Vector3(0, rotation.y,-0.2));
                if (input->is_action_pressed("k_up")) {
                    velocity.z -= 2;
                    set_rotation(Vector3(0,rotation.y,0));
                    gravity = 9.8;
                    is_hanging = false;    
                }
                if (input->is_action_pressed("l_down")) {
                    set_rotation(Vector3(0,0,0));
                    velocity.z += 2;
                    gravity =9.8;
                    is_hanging = false;
                    _die();
                    emit_signal("dead");
                }
            }
            if (edge == "Ledge2") {
                set_rotation(Vector3(0.2, 0,0));
                if (input->is_action_pressed("k_up")) {
                    velocity.x -= 2;
                    set_rotation(Vector3(0,rotation.y,0));
                    gravity = 9.8;
                    is_hanging = false;
                }
                if (input->is_action_pressed("l_down")) {
                    set_rotation(Vector3(0,rotation.y,0));
                    velocity.x += 4;
                    gravity =9.8;
                    is_hanging = false;
                    _die();
                    emit_signal("dead");
                }
            }
            if (edge == "Ledge3") {
                set_rotation(Vector3(0, 0,0.2));
                if (input->is_action_pressed("k_up")) {
                    velocity.z += 2;
                    set_rotation(Vector3(0,rotation.y,0));
                    gravity = 9.8;
                    is_hanging = false;
                }
                if (input->is_action_pressed("l_down")){
                    set_rotation(Vector3(0,rotation.y,0));
                    velocity.z -= 4;
                    gravity =9.8;
                    is_hanging = false;
                    _die();
                    emit_signal("dead");
                }
            }
             if (edge == "Ledge4"){
                set_rotation(Vector3(-0.2, 0,0));
                if (input->is_action_pressed("k_up")) {
                    velocity.x += 2;
                    set_rotation(Vector3(0,rotation.y,0));
                    gravity = 9.8;
                    is_hanging = false;    
                }
                if (input->is_action_pressed("l_down")) {
                    set_rotation(Vector3(0,rotation.y,0));
                    velocity.x -= 4;
                    gravity =9.8;
                    is_hanging = false;
                    _die();
                    emit_signal("dead");
                }
            }
            move_and_collide(velocity);
            

        }
        else {
            if (input->is_action_pressed("ui_down")) {
                cur = get_global_transform().basis.z;
                cur.y = 0;
                velocity += cur.rotated(Vector3(0, 1, 0), -M_PI/2);
            }
            if (input->is_action_pressed("ui_up")) {
                cur = get_global_transform().basis.z;
                cur.y = 0;
                velocity += cur.rotated(Vector3(0, 1, 0), M_PI/2);
            }
            if (input->is_action_pressed("ui_left")) {
                rotate_y(0.02);
            }
            if (input->is_action_pressed("ui_right")) {
                rotate_y(-0.02);
            } 
            if (input->is_action_just_pressed("ui_accept")) {
                velocity.y += 2;
                t = time(NULL);
            }
            if (input->is_key_pressed(39))
                velocity.y += .7;
            velocity.y -= gravity * delta;
            rset("slavePosition", get_transform());
        	move_and_collide(velocity);
        }
    } else {
        set_transform(slavePosition);
    }
    if(get_tree()->is_network_server()) {
        get_node("/root/Network")->call("update_position", get_name().to_int(), get_transform());
    }
}
   

void Player::_hang(String led) {
    is_hanging = true;
    edge = led;

}


void Player::init(String nickname, Vector3 startPosition, bool isSlave)
{
    set_translation(startPosition);
    set_name("player"); 
    printf("isSlave = %d\n", isSlave);
    if (isSlave)
    {
        set_translation(Vector3(0, 2, 0));
        ((CanvasItem *)get_child(11))->set_visible(false);
        ((CanvasItem *)get_child(13))->set_visible(false);
    }
    else
    {
        /* PUT BACK IN BEFORE TURN IN */
        // get_child(13)->call("mute"); 
    }
}
