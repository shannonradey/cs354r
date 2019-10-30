#include "enemy.h"

using namespace godot;

void Enemy::_register_methods() {
    register_method("_process", &Enemy::_process);
    register_method("_ready", &Enemy::_ready);
    register_method("_on_body_entered", &Enemy::_on_body_entered);
    register_method("set_target", &Enemy::set_target);
    register_method("hit_ledge", &Enemy::hit_ledge);


}

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

void Enemy::_ready() {
    speed = 150;
    get_child(4)->connect("body_shape_entered", this, "_on_body_entered");
    Vector3 cur_pos = get_global_transform().origin;
    if (cur_pos.y < 5) {
        waypoints = get_parent()->get_parent()->get_node("Waypoints")->get_children();
        num_waypoints = waypoints.size();
        set_target();
        prev_pos = get_global_transform().origin;
        time_hit = time(NULL);
    } else {
        waypoints = get_parent()->get_parent()->get_node("Waypoints2")->get_children();
        num_waypoints = waypoints.size();
        set_target();
        prev_pos = get_global_transform().origin;
        time_hit = time(NULL);
    }
    set_name("enemy");
}

void Enemy::_init() {
    bottom = true;

}

void Enemy::set_target() {
    int i = rand() % num_waypoints;
    Vector3 new_target = ((Spatial *)waypoints[i])->get_global_transform().origin;
    target.x = round(int(new_target.x));
    target.z = round(int(new_target.z));
}

void Enemy::hit_ledge() {
    Vector3 new_target = ((Spatial *)waypoints[0])->get_global_transform().origin;
    target.x = round(int(new_target.x));
    target.z = round(int(new_target.z));
}

void Enemy::_on_body_entered(int body_id, Node *body, int body_shape, int area_shape) {
    if (body->get_name() == "player") {
        Node *node = body->get_child(11)->get_child(0)->get_child(0)->get_child(0)->get_child(1);
        node->call("_decrement");
        time_hit = time(NULL);
    }
    set_target();
}

void Enemy::_process(float delta) {
    Array bodies = get_node("Area")->call("get_overlapping_bodies");
    Vector3 move = Vector3();
    int len = bodies.size();
    Vector3 cur_pos = get_global_transform().origin;
    if (time(NULL) - 3 > time_hit) {
        if (len > 2) {
            for (int i = 2; i < len; i++) {
                Node *node = (Node *)bodies[i];
                if (node->get_name() == "player") {
                    Vector3 player_pos = ((Spatial *)node)->get_global_transform().origin;
                    if (player_pos.x < cur_pos.x) {
                        move.x += -1;
                    }
                    else if (player_pos.x > cur_pos.x) {
                        move.x += 1;
                    }
                    if (player_pos.z > cur_pos.z) {
                        move.z += 1;
                    }
                    else if (player_pos.z < cur_pos.z) {
                        move.z += -1;
                    }
                    if (player_pos.y > cur_pos.y) {
                        move.y += 1;
                    }
                    else if (player_pos.y < cur_pos.y) {
                        move.y += -1;
                    }
                }
            }
        }
    }
    if (move.x == 0 && move.z == 0) {
        if (int(round(cur_pos.x)) == target.x && int(round(cur_pos.z)) == target.z) {
            set_target();
        }
        if (target.x < cur_pos.x) {
            move.x += -1;
        }
        else if (target.x > cur_pos.x) {
            move.x += 1;
        }
        if (target.z > cur_pos.z) {
            move.z += 1;
        }
        else if (target.z < cur_pos.z) {
            move.z += -1;
        }
        if (target.y > cur_pos.y) {
            move.y += 1;
        }
        else if (target.y < cur_pos.y) {
            move.y += -1;
        
        }
    }
    move.x += .0001;
    move.z += .0001;
    move_and_slide((move.operator*(4)));
}
