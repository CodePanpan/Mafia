#include "Player.h"

Player::Player(int ID, std::string nm, Type tp):id(ID), name(nm), type(tp) {
    is_awake = true;
    is_alive = true;
}
